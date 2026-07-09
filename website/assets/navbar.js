const nav = document.querySelector("nav")

const nav_items = [
    {
        text: "Hekinav Live Train Maps",
        path: "/"
    },
    {
        text: "Firmware Installer",
        path: "/web_installer/"
    },
    {
        text: "3D Viewer",
        path: "/3d_viewer/"
    },
    {
        text: "Web Simulator",
        path: "/simulator/"
    }
]

nav_items.forEach(e => {
    nav.querySelector("ul").innerHTML += `
        <li><a href="${e.path}">${e.text}</a></li>
    `
})