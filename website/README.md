[Back to main page](https://github.com/HekiNav/ltm-firmware)
# Website
A webpage to showcase my Live Train Map projects. 
<img width="1170" height="1953" alt="image" src="https://github.com/user-attachments/assets/3ae8663d-09e9-4bac-a7d4-34dce3fedd7c" />

## Features
- Firmware installer to easily update firmware and configure wifi credentials. 
- 3D Viewer to see what the board will look like
- Web simulator that works the sameway as the board, receiving data from the server


## Usage

For debugging, you can use any simple web server, like the VSCode Live Server extension. Everything but the web installer should work. The web installer does not work because when debugging the compiled firmware binaries are missing.

## Production

The firmware binaries are compiled with GitHub Actions. The actions config is located here: `\.github\workflows\deploy-installer.yml`. The action workflow takes about 3 minutes and uploads the result to Cloudflare Pages and large 3D files to R2.

