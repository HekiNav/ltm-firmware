const board_id = new URLSearchParams(window.location.search).get("board_id") || "hki-ltm";
document.querySelector("model-viewer").setAttribute("src",`/assets/${board_id}.glb`)

document.querySelectorAll(".board-select").forEach(element => {
    if (element.id == board_id) element.hidden = true
});