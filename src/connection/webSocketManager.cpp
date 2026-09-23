#include <WebSocketsClient.h>
#include <ArduinoJson.h>

#include "../include/connection/websocketManager.hpp"

#include "../include/core/config.hpp"

WebSocketsClient webSocket;

void WebSocketManager::handleWebSocketMessage(const JsonDocument& doc) {
    const char* type = doc["type"]:
    switch(type) {
        case "auth":
            authHandler.handle(doc);
            break;
        case "command":
            commandHandler.handle(doc);
            break;
        default:
            Serial.println("Unknown ws message type: " + String(type));
            break;
    }
}

void WebSocketManager::webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
    switch(type) {
        case WS_DISCONNECTED:
            Serial.println("WebSocket Disconnected");
            // isConnected = false;
            break;
        case WS_CONNECTED:
            Serial.println("WebSocket Connected");
            // isConencted = true;
            break;
        case WStype_TEXT:
            Serial.println("WebSocket Message: " + String((char*)payload));
            StaticJsonDocument<200> doc;
            DeserializationError error = deserializeJson(doc, payload, length);
            if (error) {
                Serial.println("Deserialization Error: " + String(error.c_str()));
                return;
            }
            handleWebSocketMessage(doc);
            break;
    }
}

void WebSocketManager::connect() {
    webSocket.begin(SERVER_URL, SERVER_PORT, SERVER_PATH);
    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(5000);
}

void WebSocketManager::loop() {
    webSocket.loop();
}

void WebSocketManager::send() {
    StaticJsonDocument<200> doc;
    doc["value"] = (fanSpeed * 100) / 255;
    Serial.println("Send speed: " + String(fanSpeed));

    String payload;
    serializeJson(doc, payload);
    webSocket.sendTXT(payload);
}
