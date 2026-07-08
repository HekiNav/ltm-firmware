const board_id = new URLSearchParams(window.location.search).get("board_id") || "hki-ltm";

const model_path = (window.location.hostname == "ltm.hekinav.dev") ? "https://ltm.storage.hekinav.dev/" : "/assets/3d_models/"

const viewer = document.querySelector("model-viewer");
viewer.setAttribute("src",`${model_path}${board_id}.glb`)

viewer.addEventListener("load", () => {
    document.getElementById("loading").hidden = true
})

document.querySelectorAll(".board-select").forEach(element => {
    if (element.id == board_id) element.hidden = true
});