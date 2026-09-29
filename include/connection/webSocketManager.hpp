#ifndef CONNECTING_MANAGER_HPP
#define CONNECTING_MANAGER_HPP

#include "../include/wsHandlers/initHandler.hpp"
#include "../include/wsHandlers/commandHandler.hpp"
#include "../include/wsHandlers/devicesHandler.hpp"

class WebSocketManager {
    public:
        void connect();
        void loop();
        void WebSocketManager::send(const JsonDocument doc);

    private:
        bool isConnected; //
        InitHandler initHandler;
        DevicesHandler devicesHandler;
        CommandHandler commandHandler;
        void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);
        void handleWebSocketMessage(const JsonDocument& doc);
};

#endif // CONNECTING_MANAGER_HPP
