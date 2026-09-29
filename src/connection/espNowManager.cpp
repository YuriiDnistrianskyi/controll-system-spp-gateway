#include <WiFi.h>
#include <esp_now.h>
#include <vector>
#include <ArduinoJson.h>

#include "../include/connection/espNowManager.hpp"
#include "../include/structures/connection_device.hpp"
#include "../include/structures/sensors.hpp"
#include "../include/espNowHandlers/electricalHandler.hpp"
#include "../include/espNowHandlers/statusHandler.hpp"

extern std::vector<ConnectionDevice> devices;
extern std::vector<Sensor> sensors;

void EspNowManager::sendData(const String macAddressString, const uint8_t* data) {
    unsigned int macAddressInt[6];
    //TODO
    sscanf(
        macAddressString.c_str(),
        "%02x:%02x:%02x:%02x:%02x:%02x",
        &macAddressInt[0], &macAddressInt[1], &macAddressInt[2],
        &macAddressInt[3], &macAddressInt[4], &macAddressInt[5]
    );

    esp_err_t result = esp_now_send((uint8_t)macAddressInt, data, sizeof(data));
}

void EspNowManager::handleSend(const uint8_t* macAddress, esp_now_send_status_t sendStatus) {
    Serial.println(sendStatus == 0 ? "Send success" : "Send failed");
}

void EspNowManager::handleRecv(const uint8_t* macAddress, const uint8_t* data, int len) {
    StaticJsonDocument<200> doc;

    DeserializationError error = deserializeJson(doc, data, len);

    if (error) {
        Serial.println("Deserialization Error ESP NOW: " + String(error.c_str()));
        return;
    }

    char macString[18];
    snprintf(
        macString,
        sizeof(macString),
        "%02X:%02X:%02X:%02X:%02X:%02X",
        static_cast<unsigned>(macAddress[0]),
        static_cast<unsigned>(macAddress[1]),
        static_cast<unsigned>(macAddress[2]),
        static_cast<unsigned>(macAddress[3]),
        static_cast<unsigned>(macAddress[4]),
        static_cast<unsigned>(macAddress[5])
    );

    const char* type = doc["type"];

    if (strcmp(type, "electrical") == 0) {
        electricalHandler.handle(doc, macString);
    } else if (strcmp(type, "status") == 0) {
        statusHandler.handle(doc, mactring);
    } else {
        Serial.println("Unknown esp now message type: " + String(type));
    }
}

bool EspNowManager::addPeer(const String& macAddressString) {
    unsigned int macAddressInt[6];

    if (sscanf(
            macAddressString.c_str(),
            "%02x:%02x:%02x:%02x:%02x:%02x",
            &macAddressInt[0], &macAddressInt[1], &macAddressInt[2],
            &macAddressInt[3], &macAddressInt[4], &macAddressInt[5]
        ) != 6) return false;

    esp_now_peer_info_t peerInfo{};

    memcpy(peerInfo.peer_addr, macAddressInt, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    return esp_now_add_peer(&peerInfo) == ESP_OK;
}

void EspNowManager::begin() {
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != 0) {
        Serial.println("ESPNOW dont`t initialize");
        return;
    }

    for(ConnectionDevice device : devices) {
        addPeer(device.macAddress);
    }

    for (Sensor sensor : sensors) {
        addPeer(sensor.macAddress);
    }

    esp_now_register_send_cb(handleSend);
    esp_now_register_recv_cb(handleRecv);
}
