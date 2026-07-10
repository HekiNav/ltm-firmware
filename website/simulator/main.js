const board_id = new URLSearchParams(window.location.search).get("board_id") || "hki-ltm";


const viewer = document.querySelector("#svg_container");

async function getSVG() {
    const response = await fetch(`/assets/${board_id}.svg`)
    if (!response.ok) throw alert("Failed to load map")
    const text = await response.text()
    viewer.innerHTML = text
}

function connect() {
    const leds = document.querySelector("#leds").children;
    const status_led_elements = Array.from(document.querySelectorAll(".led")).reverse()
    const status_leds = [];
    while (status_led_elements.length) status_leds.push(status_led_elements.splice(0, 2));
    /* 
    MODES:
    0: off
    1: green
    2: green blink
    3: red
    4: red blink
    */
    function setStatus(...modes) {
        modes.forEach((m, i) => {
            status_leds[i][0].classList.remove("green", "red", "blink")
            status_leds[i][1].classList.remove("green", "red", "blink")
            switch (m) {
                case 2:
                    status_leds[i][1].classList.add("blink")
                case 1:
                    status_leds[i][1].classList.add("green")
                    break;
                case 4:
                    status_leds[i][0].classList.add("blink")
                case 3:
                    status_leds[i][0].classList.add("red")
                    break;
                case 0:
                default:
                    break;
            }
        })
    }
    let color_table = {0: [0,0,0], 1: [128,0,0]}
    const led_state = new Map()

    console.log("Connecting to server with WebSocket")
    setStatus(1, 1, 2)
    const ws = new WebSocket(`wss://ltm-api-v2.hekinav.dev?board_id=${board_id}&version=100&mode_id=route`)
    ws.addEventListener("close", () => {
        setStatus(1, 1, 3)
        console.log("WebSocket closed")
    })
    ws.addEventListener("open", () => {
        setStatus(1, 1, 1)
        console.log("WebSocket opened")
    })
    ws.addEventListener("error", (err) => {
        console.log("WebSocket error", err)
    })
    ws.addEventListener("message", async (msg) => {
        const result = await parseMessage(msg)
        if (Object.hasOwn(result, "error")) {
            console.log("Received unknown data:", msg)
        } else if (Object.hasOwn(result, "message")) {
            const message = result.message
            switch (message.type) {
                case "error":
                    console.error(`Received error: ${message.message}`)
                    break
                case "uuid":
                    console.log(`Connection was assigned UUID: ${message.uuid}`)
                    break
                case "ping_req":
                    ws.send(encodeMessage({ type: "ping_res" }))
                    break
                case "ping_res":
                    console.log("Received ping response")
                    break
                case "colors":
                    color_table = message.colors
                    console.log(colors)
                    break
                case "events":
                    console.log(`Received ${message.updates.length} updates`)
                    message.updates.forEach(u => {
                        if (u.t == "remove") {
                            console.log(`${u.d.id} X`)
                            console.log(`${u.d.id} X`)
                            if (!led_state.has(u.d.id)) return
                            leds[led_state[u.d.id] - 100].setAttribute("fill", "none")
                            led_state.delete(u.d.id)
                        } else {
                            console.log(`${u.d.id} => ${u.d.idx}`)
                            const color = color_table[u.d.clr] || color_table[1]
                            console.log(color, color_table)
                            leds[u.d.idx - 100].setAttribute("fill", `rgb(${color.join(",")})`)
                            led_state.set(u.d.id, u.d.idx)
                        }
                    })
                    break
                default:
                    console.log("[WS SERVER] Received data of unknown type: " + message.type)
                    break
            }
        }
    })
}

async function parseMessage(msg) {
    try {
        const data = JSON.parse(await msg.data.text())
        return { message: data }
    } catch (error) {
        return { error: error }
    }
}
function encodeMessage(msg) {
    return Buffer.from(JSON.stringify(msg))
}

viewer.addEventListener("load", () => {
    document.getElementById("loading").hidden = true
})

document.querySelectorAll(".board-select").forEach(element => {
    if (element.id == board_id) element.hidden = true
});

getSVG().then(connect)