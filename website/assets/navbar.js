const nav = document.querySelector("nav")

console.log(nav)

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
    }
]

nav_items.forEach(e => {
    nav.querySelector("ul").innerHTML += `
        <li><a href="${e.path}">${e.text}</a></li>
    `
})