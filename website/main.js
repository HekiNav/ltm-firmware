const body = document.body
const maps_container = document.getElementById("maps_container")

const maps_config = [
    {
        id: "hki-ltm",
        title: "Helsinki LTM",
        desc: `
        Commuter lines around Helsinki and southern Finland. 
        Includes side-by-side LEDs for fast and slow lines on 
        Helsinki-Leppävaara-[Kauklahti (under construction)] and 
        Helsinki-Kerava routes`
    },
    {
        id: "fin-ltm",
        title: "Finland LTM",
        desc: `All Intercity routes in Finland. 
        Also shows freight trains and future expansions 
        to Rauma and Haaparanta in Sweden`
    }
]

window.addEventListener("scroll", (e) => {
    body.style.backgroundPositionY = `${window.scrollY / 3}px`
})

window.addEventListener("DOMContentLoaded", () => {
    maps_config.forEach(m => {
        maps_container.innerHTML += `
        <div class="map_tile">
            <div style="font-size: 1.2em" class="text-primary">${m.title}</div>
            <img src="" alt="" srcset="">
            <div>
                ${m.desc}
            </div>
        </div>
        `
    })
})