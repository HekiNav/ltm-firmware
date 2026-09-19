module.exports = {
  apps : [{
    name   : "ltm-api-v2",
    script : "npm start",
    ignore_watch: ["./src/*.db"],
    cron_restart: "0 * * * *"
  }]
}
