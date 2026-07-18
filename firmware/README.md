[Back to main page](https://github.com/HekiNav/ltm-firmware)
# Firmware

This directory contains firmware which can be used for two different devices: Helsinki LTM and Finland LTM. The legacy firmware (only for Helsinki LTM) can be found in [another repo](https://github.com/hekinav/legacy-ltm-firmware/)

The boards are configured in `/boards` and the source code is in `/src`.

## Usage

The easiest way to install firmware to the board is via the ESP Web Tools interface at [ltm.hekinav.dev](https://ltm.hekinav.dev/web_installer/)

You can also compile the code yourself. 

### Compiling the code yourself

Use the Platformio extension in VSCode and open the firmware directory from platformio home. Then you can build or upload the code to the esp. (The WiFi has to be configured via the web interface afterwards)
