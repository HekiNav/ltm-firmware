import * as mqtt from "mqtt"

export class DigitrafficCompositionCollector {
  state = new Map<number, CompositionData>()
  #client: mqtt.MqttClient
  #listeners = new Map<string, (c: CompositionData) => void>()

  constructor(onready: (c: DigitrafficCompositionCollector) => void) {
    console.log("[COMPOSITIONS] Getting initial data")
    this.#getInitialData().then(() => {
      onready(this)
    })
    console.log("[COMPOSITIONS] Connecting to MQTT")
    this.#client = mqtt.connect("wss://rata.digitraffic.fi/mqtt")
    this.#client.on("connect", () => {
      this.#client.subscribe("compositions/#", (err) => {
        if (err) {
          console.error("[COMPOSITIONS] MQTT subscription error %s", err)
        } else {
          console.log("[COMPOSITIONS] Connected to MQTT")
        }
      })
    })
    this.#client.on("error", console.error)
    this.#client.on("message", (_topic, payload) => {
      let data: CompositionData
      try {
        data = JSON.parse(payload.toString())
      } catch (e) {
        console.error("[COMPOSITIONS] Failed to parse message %s", e)
        return
      }
      this.#update(data)
    })
  }

  async #getInitialData() {
    const today = new Date().toLocaleDateString("sv-SE", { timeZone: "Europe/Helsinki" }) // yyyy-mm-dd
    try {
      const res = await fetch(`https://rata.digitraffic.fi/api/v1/compositions/${today}`)
      const data = await res.json() as CompositionData[]
      data.forEach(c => this.state.set(c.trainNumber, c))
      console.log(`[COMPOSITIONS] Seeded ${data.length} compositions for ${today}`)
    } catch (e) {
      console.error("[COMPOSITIONS] Failed to fetch initial data %s", e)
    }
  }

  #update(c: CompositionData) {
    this.#listeners.forEach(l => l(c))
    this.state.set(c.trainNumber, c)
  }

  onUpdate(id: string, fn: (c: CompositionData) => void) {
    this.#listeners.set(id, fn)
  }
  offUpdate(id: string) {
    this.#listeners.delete(id)
  }

  get(trainNumber: number): CompositionData | undefined {
    return this.state.get(trainNumber)
  }
}

export interface CompositionData {
  trainNumber: number
  departureDate: string
  operatorUICCode: number
  operatorShortCode: string
  trainCategory: string
  trainType: string
  version: number
  journeySections: JourneySection[]
}
export interface JourneySection {
  beginTimeTableRow: CompositionTimeTableRow
  endTimeTableRow: CompositionTimeTableRow
  locomotives: Locomotive[]
  wagons?: Wagon[]
  totalLength: number
  maximumSpeed: number
}
export interface CompositionTimeTableRow {
  stationShortCode: string
  stationUICCode: number
  countryCode: "FI" | "RU"
  type: "ARRIVAL" | "DEPARTURE"
  scheduledTime: string
}
export interface Locomotive {
  vehicleNumber?: string
  location: number
  locomotiveType: string
  powerType: string
}
export interface Wagon {
  vehicleNumber?: string
  location: number
  salesNumber: number
  length?: number
  playground?: boolean
  pet?: boolean
  catering?: boolean
  video?: boolean
  luggage?: boolean
  smoking?: boolean
  disabled?: boolean
  wagonType?: string
}