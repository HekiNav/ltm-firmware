#pragma once

#include <ESPAsyncWebServer.h>
#include <Esp.h>
#include <ImprovWiFiLibrary.h>
#include <Preferences.h>
#include <WiFi.h>

extern Preferences preferences;

ImprovWiFi improvSerial(&Serial);
AsyncWebServer server(80);

#define MAX_SSID_LEN 32
#define MAX_PASS_LEN 64
#define MAX_WIFI_NETWORKS 16

/**
 * @brief Structure for storing WiFi credentials
 */
struct savedWiFiNetwork
{
	char ssid[MAX_SSID_LEN];
	char password[MAX_PASS_LEN];
};

int wifiNetworkIndex = 0;				  // Index of the current WiFi network
unsigned long lastWiFiConnectAttempt = 0; // Timestamp of the last WiFi connect attempt
uint8_t wifiConnectAttempts = 0;		  // Number of attempts for the current network

savedWiFiNetwork savedWiFi[MAX_WIFI_NETWORKS];

void setUpWebserver(AsyncWebServer &server, int8_t *mode_ptr);

/**
 * @brief Callback for Improv WiFi errors
 *
 * @param err Error type from Improv WiFi
 */
void onImprovWiFiErrorCb(ImprovTypes::Error err)
{
	Serial.printf("Improv WiFi Error: %d\n", err);
	server.end();
	server.begin();
}

/**
 * @brief Save WiFi credentials to NVS
 */
void exportWiFi()
{
	preferences.begin("wifi");
	preferences.putBytes("wifi", savedWiFi, sizeof(savedWiFi));
	preferences.end();
}

/**
 * @brief Load WiFi credentials from NVS
 */
void importWiFi()
{
	preferences.begin("wifi", true);
	preferences.getBytes("wifi", savedWiFi, sizeof(savedWiFi));
	preferences.end();
}

/**
 * @brief Callback when WiFi is connected via Improv
 *
 * Saves the new network at the top of the saved networks list
 * and persists it to NVS.
 *
 * @param ssid Network SSID
 * @param password Network password
 */
void onImprovWiFiConnectedCb(const char *ssid, const char *password)
{

	// Move the networks all down one position
	for (int i = MAX_WIFI_NETWORKS - 1; i > 0; i--)
	{
		strncpy(savedWiFi[i].ssid, savedWiFi[i - 1].ssid, MAX_SSID_LEN);
		strncpy(savedWiFi[i].password, savedWiFi[i - 1].password, MAX_PASS_LEN);
	}

	// Save the new network at the top
	strncpy(savedWiFi[0].ssid, ssid, MAX_SSID_LEN);
	strncpy(savedWiFi[0].password, password, MAX_PASS_LEN);

	// Save the updated WiFi networks to Preferences
	exportWiFi();

	// Restart the web server
	Serial.println("CONNECTED a");
	server.end();
	server.begin();
}

/**
 * @brief Initialize WiFi with Improv serial provisioning
 *
 * Loads saved credentials from NVS and configures Improv WiFi
 * for serial-based provisioning.
 *
 * @return true if saved WiFi credentials were found, false otherwise
 */
bool WiFiImprovSetup(int8_t *mode_ptr)
{
#if defined(RESET_WIFI)

#else
	importWiFi();
#endif

#if defined(CONFIG_IDF_TARGET_ESP32S2)
	enum ImprovTypes::ChipFamily chip = ImprovTypes::ChipFamily::CF_ESP32_S2;
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
	enum ImprovTypes::ChipFamily chip = ImprovTypes::ChipFamily::CF_ESP32_C3;
#elif defined(CONFIG_IDF_TARGET_ESP32S3)
	enum ImprovTypes::ChipFamily chip = ImprovTypes::ChipFamily::CF_ESP32_S3;
#else
	error("Unknown chip for Improv WiFi");
#endif

	improvSerial.setDeviceInfo(chip, FIRMWARE, FIRMWARE_VERSION, ARDUINO_BOARD, "http://{LOCAL_IPV4}/");
	improvSerial.onImprovError(onImprovWiFiErrorCb);
	improvSerial.onImprovConnected(onImprovWiFiConnectedCb);
	setUpWebserver(server, mode_ptr);

	bool savedWifiFound = false;
	for (int i = 0; i < MAX_WIFI_NETWORKS; i++)
	{
		if (strlen(savedWiFi[i].ssid) > 0)
		{
			savedWifiFound = true;
			break;
		}
	}

	return savedWifiFound;
}

const char index_html[] PROGMEM = R"=====(<!doctype html> <html lang=en> <head> <meta charset=UTF-8> <meta name=viewport content="width=device-width,initial-scale=1"> <title>Rail Map Control Panel</title> <style>::selection{background-color:#09f;color:#fff}::-moz-selection{background-color:#09f;color:#fff}body{background:#222;color:#fff;font-family:-apple-system,system-ui,BlinkMacSystemFont,"Segoe UI",Roboto,Ubuntu,sans-serif;margin:0;padding:0;min-height:100vh;display:flex;flex-direction:column;align-items:center;justify-content:center}.container{background:#333;border-radius:12px;box-shadow:0 2px 12px rgba(0,0,0,.3);padding:32px 24px;max-width:600px;width:90%;display:flex;align-items:center;flex-direction:column}h1{color:#09f;font-family:inherit;margin-bottom:16px}button,summary{background-color:#09f;border-radius:12px;border:0;padding:.5em;font-size:1em;color:#fff;box-shadow:0 2px 6px rgba(0,153,255,.6);font-family:inherit;margin-bottom:16px;height:min-content;margin-bottom:0}h2{color:#fff;font-family:inherit;font-weight:600;margin-top:0;display:flex}h3{color:#fff;font-family:inherit;font-weight:400;margin-top:0;display:flex}details{display:flex;justify-content:center;font-size:.6em;margin-left:1em;height:min-content;position:relative}details div{margin-left:1em;position:absolute;background:#222;border-radius:12px;box-shadow:0 2px 12px rgba(0,0,0,.3);padding:8px 8px;width:max-content;display:flex;flex-direction:row;z-index:1000;gap:.5em;bottom:-8px}@media (max-width:600px){.container{padding:18px 4px}h1{font-size:1.6em}h2{font-size:1.1em}h3{font-size:.9em}details div{margin-top:1em;padding:8px 8px;width:min-content;height:max-content;flex-direction:column;top:2em;right:0}}.align-start{display:flex;flex-direction:column;width:100%;align-items:start}details>summary{list-style:none}.legend-color{height:1em;margin-left:auto;display:block;aspect-ratio:1}table{border-spacing:.5em 0}th{text-align:start}th div{text-transform:capitalize}</style> </head> <body> <div class=container> <h1>Rail Map Control Panel</h1> <div class=container style=margin-top:1em> <h1>Legend</h1> <table> <tbody id=legend> </tbody> </table> <button id=refresh onclick=getData()>Refresh</button> </div> <script>const API_URL="./",refreshButton=document.querySelector("#refresh"),legend=document.querySelector("#legend"),legends={fin:{100:{route:[{color:"#f00",line:"Tampere-Turku, Helsinki-Tampere, Helsinki-Kouvola, Oulu-Rovaniemi, Kuopio-Oulu, Seinäjoki-Ähtäri-(Jyväskylä)*, Seinäjoki-Vaasa"},{color:"#f80",line:"Helsinki-Kuopio, Helsinki-Imatra-(Joensuu), Helsinki-Vaasa, (Turku)-Tampere-Jyväskylä-(Kuopio), Seinäjoki-Oulu"},{color:"#ff0",line:"Helsinki-Kajaani, Helsinki-Pieksamäki, Tampere-Pori, Oulu-Haaparanta"},{color:"#0f0",line:"Helsinki-Turku, Helsinki-Rovaniemi"},{color:"#0ff",line:"Tampere-Keuruu*, Night trains"},{color:"#00f",line:"Helsinki-Oulu, Savonlinna-Parikkala*"},{color:"#80f",line:"Pieksamäki-Joensuu*, Helsinki-Jyväskylä, Helsinki-Kokkola"},{color:"#f0f",line:"Seinäjoki-Vaasa, Tampere-Jyväskylä, Tampere-Rauma (spring 2027)"},{color:"#f08",line:"Helsinki-Pori, Ylivieska-Iisalmi, Joensuu-Nurmes*"},{color:"#fff",line:"Other"}],length:[{color:"#f00",line:"<50m"},{color:"#f80",line:"50m-100m"},{color:"#ff0",line:"100m-200m"},{color:"#0f0",line:"200m-300m"},{color:"#0ff",line:"300m-500m"},{color:"#00f",line:"500m-1000m"},{color:"#80f",line:">1000m"},{color:"#f08",line:"Length not available"},{color:"#fff",line:"Other length"}],loco:[{color:"#f00",line:"Sr1"},{color:"#f80",line:"Dm12"},{color:"#ff0",line:"Sr2"},{color:"#0f0",line:"Sr3"},{color:"#0ff",line:"Sm3"},{color:"#00f",line:"Sm6"},{color:"#80f",line:"Dr19"},{color:"#f08",line:"Locomotive not available"},{color:"#fff",line:"Other locomotive"}]}},hki:{100:{lines:[{color:"#f00",line:"Z"},{color:"#f80",line:"A"},{color:"#ff0",line:"E, O"},{color:"#0f0",line:"P, G"},{color:"#0ff",line:"I, M"},{color:"#00f",line:"K"},{color:"#80f",line:"Y, L, H, X"},{color:"#f0f",line:"U"},{color:"#f08",line:"D, T, R"},{color:"#fff",line:"V"}],length:[{color:"#f00",line:"<50m"},{color:"#f80",line:"50m-100m"},{color:"#ff0",line:"100m-200m"},{color:"#0f0",line:"200m-300m"},{color:"#0ff",line:"300m-500m"},{color:"#00f",line:"500m-1000m"},{color:"#80f",line:">1000m"},{color:"#f08",line:"Length not available"},{color:"#fff",line:"Other length"}],loco:[{color:"#f00",line:"Sm2"},{color:"#f80",line:"Sr1, Sr2, Sr3, Sm3 (InterCity locomotives)"},{color:"#0f0",line:"Sm4"},{color:"#00f",line:"Sm7"},{color:"#80f",line:"Sm5"},{color:"#f08",line:"Locomotive not available"},{color:"#fff",line:"Other locomotive"}]}}};async function getData(){refreshButton&&(refreshButton.innerHTML="Loading...");const o=await fetch("./get_data/"),e=await o.json();refreshButton&&(refreshButton.innerHTML="Refresh"),parseData(e)}function parseData(o){if(legend){legend.innerHTML="";const e=legends[o.board][o.version][o.mode];if(!e)return;const l=Object.keys(e[0]);legend.innerHTML+=`<tr>${l.reduce(((o,e)=>`${o}<th><div>${e}</div></th>`),"")}</tr>`,e.forEach((o=>{const{color:e,...l}=o,i=Object.values(l);console.log(i),legend.innerHTML+=`<tr><td><span class="legend-color" style="background-color: ${e}"></span></td>${i.reduce(((o,e)=>`${o}<td>${e}</td>`),"")}</tr>`}))}}getData()</script> )=====";
// minified to save flash space


/**
 * @brief Configure and start the async web server
 *
 * @param server AsyncWebServer instance to configure
 */
void setUpWebserver(AsyncWebServer &server, int8_t *mode_ptr)
{

	server.on("/favicon.ico", [](AsyncWebServerRequest *request)
			  { request->send(404); });

	// Serve Basic HTML Page
	server.on("/", HTTP_ANY, [](AsyncWebServerRequest *request)
			  {
		AsyncWebServerResponse *response = request->beginResponse(200, "text/html", index_html);
		response->addHeader(
			"Cache-Control", "public,max-age=31536000");  // save this file to cache for 1 year (unless you refresh)
		request->send(response);
		Serial.println("Served Basic HTML Page"); });

	server.on(
		"/get_data/", HTTP_ANY, [mode_ptr](AsyncWebServerRequest *request)
		{
			char jsonBuffer[256];

			Serial.println(*mode_ptr);
			Serial.println(mapModes[*mode_ptr]);

			snprintf(jsonBuffer,
					 sizeof(jsonBuffer),
					 "{\"mode\":\"%s\", \"board\":\"%s\", \"version\":%s}",
					 mapModes[*mode_ptr],
					 CITY_CODE,
					 BACKEND_VERSION);

			AsyncWebServerResponse *response = request->beginResponse(200, "application/json", jsonBuffer);
			response->addHeader("Access-Control-Allow-Origin", "*");
			request->send(response);
			Serial.println("Served Data"); });

	server.onNotFound([](AsyncWebServerRequest *request)
					  { request->send(404); });

	server.begin();
}

/**
 * @brief FreeRTOS task for handling Improv WiFi serial communication
 *
 * @param param Unused task parameter
 */
void improvSerialTask(void *param)
{
	while (true)
	{
		while (Serial.available() > 0)
		{
			improvSerial.handleSerial();
		}
		vTaskDelay(pdMS_TO_TICKS(20));
	}
}

/**
 * @brief Manage WiFi connection with failover across saved networks
 *
 * Attempts to connect to saved WiFi networks, cycling through them
 * on repeated failures.
 */
void manageWiFiConnection()
{
	const unsigned long attemptTimeout = 5000; // 5 seconds for each attempt
	const uint8_t maxAttempts = 3;			   // Max attempts per network

	if (millis() - lastWiFiConnectAttempt > attemptTimeout || lastWiFiConnectAttempt == 0)
	{
		if (wifiConnectAttempts < maxAttempts)
		{
			wifiConnectAttempts++;
		}
		else
		{
			wifiConnectAttempts = 0;

			while (strlen(savedWiFi[wifiNetworkIndex].ssid) == 0 && wifiNetworkIndex < MAX_WIFI_NETWORKS)
			{
				wifiNetworkIndex++; // Skip empty SSIDs
									// printf("Skipping empty WiFi slot %i\n", wifiNetworkIndex);
			}

			if (wifiNetworkIndex >= MAX_WIFI_NETWORKS)
			{
				wifiNetworkIndex = 0;
			}
		}

		if (strlen(savedWiFi[wifiNetworkIndex].ssid) != 0)
		{
			// Attempt to connect to the current network
			Serial.printf("Attempting to connect to saved network %i: %s\n", wifiNetworkIndex, savedWiFi[wifiNetworkIndex].ssid);
			improvSerial.tryConnectToWifi(savedWiFi[wifiNetworkIndex].ssid, savedWiFi[wifiNetworkIndex].password, 500, 2);
		}

		lastWiFiConnectAttempt = millis();
	}
}