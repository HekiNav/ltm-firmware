const board_id = new URLSearchParams(window.location.search).get("board_id") || "hki-ltm";

const model_path = (window.location.hostname == "ltm.hekinav.dev") ? "https://ltm.storage.hekinav.dev/" : "/assets/"

document.querySelector("model-viewer").setAttribute("src",`${model_path}${board_id}.glb`)

document.querySelectorAll(".board-select").forEach(element => {
    if (element.id == board_id) element.hidden = true
});