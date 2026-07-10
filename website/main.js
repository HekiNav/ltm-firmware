const body = document.body
const maps_container = document.getElementById("maps_container")

const maps_config = [
    {
        id: "hki-ltm",
        title: "Helsinki LTM",
        image: "hki_ltm_cropped.png",
        desc: `
        Commuter lines around Helsinki and southern Finland. 
        Includes side-by-side LEDs for fast and slow lines on 
        Helsinki-Leppävaara-[Kauklahti (under construction)] and 
        Helsinki-Kerava routes`
    },
    {
        id: "fin-ltm",
        title: "Finland LTM",
        image: "fin_ltm_cropped.png",
        desc: `All Intercity rail routes and stations in Finland. 
        Also shows freight trains and future expansions 
        to Rauma and Haaparanta in Sweden`
    }
]

window.addEventListener("scroll", (e) => {
    body.style.backgroundPositionY = `${window.scrollY / 1.5}px`
})

window.addEventListener("DOMContentLoaded", () => {
    maps_config.forEach(m => {
        maps_container.innerHTML += `
        <div class="map_tile">
            <div style="font-size: 1.5em" class="text-primary">${m.title}</div>
            <img style="max-width: 100%; max-height: 15em; padding: 1em 0; margin: auto" src="/assets/${m.image}" alt="Image of ${m.title}" srcset="">
            <div>
                ${m.desc}
            </div>
            <a href="/web_installer/?board_id=${m.id}_100"><button>Firmware Installer</button></a>
            <a href="/3d_viewer/?board_id=${m.id}"><button>3D Viewer</button></a>
            <a href="/simulator/?board_id=${m.id}"><button>Simulator</button></a>
        </div>
        `
    })
})