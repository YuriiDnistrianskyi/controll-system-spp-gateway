#include <WebServer.h>
#include <LittleFS.h>

#include "../include/services/localServerService.hpp"
#include "../include/connection/wifiManager.hpp"
#include "../include/core/configStorage.hpp"

extern ConfigStorage configStorage;
extern WifiManager wifiManager;

void LocalServerService::handleClick() {
    String ssid = server.arg("ssid");
    String password = server.arg("password");
    String code = server.arg("code");

    configStorage.setWifiSSID(ssid);
    configStorage.setWifiPassword(password);
    configStorage.setActivationCode(code);

    server.send(200, "text/plain", "OK");
    Serial.println(ssid);
    Serial.println(password);
    Serial.println(code);
    ESP.restart();
}


void LocalServerService::setup() {
    wifiManager.initWifi();

    server.on("/", HTTP_GET, [this]() {
        File file = LittleFS.open("/index.html", "r");
        server.streamFile(file, "text/html");
        file.close();
    });

    server.on("/style.css", HTTP_GET, [this]() {
        File file = LittleFS.open("/style.css", "r");
        server.streamFile(file, "text/css");
        file.close();
    });

    server.on("/script.js", HTTP_GET, [this]() {
        File file = LittleFS.open("/script.js", "r");
        server.streamFile(file, "application/javascript");
        file.close();
    });

    server.on("/click", HTTP_POST, [this]() {
        handleClick();
    });

    server.begin();
}

void LocalServerService::loop() {
    server.handleClient();
}
