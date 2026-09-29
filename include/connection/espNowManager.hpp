#ifndef ESPNOW_MANAGER_HPP
#define ESPNOW_MANAGER_HPP

#include "../include/espNowHandlers/electricalHandler.hpp"
#include "../include/espNowHandlers/statusHandler.hpp"

class EspNowManager {
    public:
        void begin();
        void sendData(const uint8_t* macAddress, const uint8_t* data);

    private:
        ElectricalHandler electricalHandler;
        StatuslHandler statusHandler;
        bool addPeer(const String& macAddressString);
        static void handleSend(const uint8_t* macAddress, esp_now_send_status_t sendStatus);
        static void handleRecv(const uint8_t* macAddress, const uint8_t* data, int len);
};

#endif // ESPNOW_MANAGER_HPP
