#ifndef CONNECTING_MANAGER_HPP
#define CONNECTING_MANAGER_HPP

#include "../include/handlers/authHandler.hpp";
#include "../include/handlers/commandHandler.hpp";

class WebSocketManager {
    public:
        void connect();
        void loop();
        void send();

    private:
        bool isConnected; //
        AuthHandler authHandler;
        CommandHandler commandHandler;
        void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);
        void handleWebSocketMessage(const JsonDocument& doc);
};

#endif // CONNECTING_MANAGER_HPP
