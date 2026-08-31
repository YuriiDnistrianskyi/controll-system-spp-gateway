#include <WebServer.h>
#include <LittleFS.h>

#include "../include/localServer.hpp"
#include "../include/configStorage.hpp"

extern ConfigStorage configStorage;

void LocalServer::handleClick() {
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


void LocalServer::begin() {
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

void LocalServer::loop() {
    server.handleClient();
}
