import Database from 'better-sqlite3'
import { fileURLToPath } from 'node:url'
import { dirname, join } from 'node:path'
import fs from 'fs'

const __dirname = dirname(fileURLToPath(import.meta.url))

export class CompositionCache {
  db: any
  private lastBulkFetchDate: string | null = null
  private bulkFetchInProgress = false

  constructor(baseDir?: string) {
    const dataDir = baseDir || join(__dirname, '..', 'data')
    fs.mkdirSync(dataDir, { recursive: true })
    const dbPath = join(dataDir, 'compositions.db')
    this.db = new Database(dbPath)
    this.db.pragma('journal_mode = WAL')
    this.init()
    this.startScheduledJob()
  }

  init() {
    this.db.prepare(`
      CREATE TABLE IF NOT EXISTS compositions (
        key TEXT PRIMARY KEY,
        trainNumber INTEGER,
        departureDate TEXT,
        etag TEXT,
        data TEXT,
        lastFetched INTEGER
      )
    `).run()
  }

  key(trainNumber: number, departureDate: string) {
    return `${trainNumber}_${departureDate}`
  }

  get(trainNumber: number, departureDate: string) {
    const row = this.db.prepare('SELECT data FROM compositions WHERE key = ?').get(this.key(trainNumber, departureDate))
    if (!row) return null
    try {
      return JSON.parse(row.data)
    } catch (e) {
      return null
    }
  }

  getEtag(trainNumber: number, departureDate: string) {
    const row = this.db.prepare('SELECT etag FROM compositions WHERE key = ?').get(this.key(trainNumber, departureDate))
    return row?.etag || null
  }

  upsert(trainNumber: number, departureDate: string, etag: string | null, data: unknown) {
    const key = this.key(trainNumber, departureDate)
    const now = Date.now()
    const json = JSON.stringify(data)
    this.db.prepare(`INSERT OR REPLACE INTO compositions (key, trainNumber, departureDate, etag, data, lastFetched) VALUES (?, ?, ?, ?, ?, ?)`)
      .run(key, trainNumber, departureDate, etag, json, now)
  }

  async fetchRemote(trainNumber: number, departureDate: string) {
    // If already cached, return
    const cached = this.get(trainNumber, departureDate)
    if (cached) return cached

    try {
      const etag = this.getEtag(trainNumber, departureDate)
      const headers: Record<string, string> = {}
      if (etag) headers['If-None-Match'] = etag

      const url = `https://rata.digitraffic.fi/api/v1/compositions/${departureDate}/${trainNumber}/`
      const res = await fetch(url, { headers })
      
      if (res.status === 304) {
        return this.get(trainNumber, departureDate)
      }
      if (!res.ok) {
        return null
      }

      const newEtag = res.headers.get('etag')
      const data = await res.json()
      this.upsert(trainNumber, departureDate, newEtag, data)
      return data
    } catch (e) {
      return cached || null
    }
  }

  private async fetchAllCompositionsForDate(date: string) {
    if (this.bulkFetchInProgress) return
    this.bulkFetchInProgress = true

    try {
      const url = `https://rata.digitraffic.fi/api/v1/compositions/${date}/`
      const res = await fetch(url)

      if (!res.ok) {
        console.error(`[COMPOSITIONS] Failed to fetch all compositions for ${date}: ${res.status}`)
        return
      }

      const compositions = await res.json()
      if (!Array.isArray(compositions)) {
        console.error('[COMPOSITIONS] Unexpected response format')
        return
      }

      compositions.forEach((comp: any) => {
        const trainNumber = comp.trainNumber
        if (trainNumber) {
          const etag = res.headers.get('etag')
          this.upsert(trainNumber, date, etag, comp)
        }
      })

      this.lastBulkFetchDate = date
      console.log(`[COMPOSITIONS] Fetched ${compositions.length} compositions for ${date}`)
    } catch (e) {
      const error = e instanceof Error ? e.message : String(e)
      console.error(`[COMPOSITIONS] Error fetching all compositions: ${error}`)
    } finally {
      this.bulkFetchInProgress = false
    }
  }

  private startScheduledJob() {
    // Run at startup
    const today = new Date().toISOString().split('T')[0]
    this.fetchAllCompositionsForDate(today)

    // Run once per day at 2 AM
    const scheduleNextRun = () => {
      const now = new Date()
      const tomorrow = new Date(now)
      tomorrow.setDate(tomorrow.getDate() + 1)
      tomorrow.setHours(2, 0, 0, 0)

      const delay = tomorrow.getTime() - now.getTime()
      console.log(`[COMPOSITIONS] Scheduled next bulk fetch in ${Math.round(delay / 1000 / 60)} minutes`)

      setTimeout(() => {
        const date = new Date().toISOString().split('T')[0]
        this.fetchAllCompositionsForDate(date)
        scheduleNextRun()
      }, delay)
    }

    scheduleNextRun()
  }
}

const cache = new CompositionCache()
export default cache
