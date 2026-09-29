#include <WebSocketsClient.h>
#include <ArduinoJson.h>

#include "../include/connection/webSocketManager.hpp"

#include "../include/core/config.hpp"
#include "../include/wsHandlers/initHandler.hpp"
#include "../include/wsHandlers/devicesHandler.hpp"
#include "../include/wsHandlers/commandHandler.hpp"

WebSocketsClient webSocket;

void WebSocketManager::handleWebSocketMessage(const JsonDocument& doc) {
    const char* type = doc["type"];

    if (strcmp(type, "initialization") == 0) {
        initHandler.handle(doc);
        Serial.println("Init message handled");
    } else if (strcmp(type, "devices") == 0) {
        devicesHandler.handle(doc);
        Serial.println("Devices message handled");
    } else if (strcmp(type, "command") == 0 ) {
        commandHandler.handle(doc);
        Serial.println("Command message handled");
    } else {
        Serial.println("Unknown ws message type: " + String(type));
    }
}

void WebSocketManager::webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.println("WebSocket Disconnected");
            // isConnected = false;
            break;
        case WStype_CONNECTED:
            Serial.println("WebSocket Connected");
            // isConencted = true;
            break;
        case WStype_TEXT:
            Serial.println("WebSocket Message: " + String((char*)payload));
            StaticJsonDocument<200> doc;
            DeserializationError error = deserializeJson(doc, payload, length);
            if (error) {
                Serial.println("Deserialization Error WS: " + String(error.c_str()));
                return;
            }
            handleWebSocketMessage(doc);
            break;
    }
}

void WebSocketManager::connect() {
    webSocket.begin(SERVER_URL, SERVER_PORT, SERVER_PATH);
    webSocket.onEvent([this](WStype_t type, uint8_t* data, size_t length) {
        webSocketEvent(type, data, length);
    });
    webSocket.setReconnectInterval(5000);
}

void WebSocketManager::loop() {
    webSocket.loop();
}

void WebSocketManager::send(const JsonDocument& doc) {
    String payload;
    serializeJson(doc, payload);
    webSocket.sendTXT(payload);
}
