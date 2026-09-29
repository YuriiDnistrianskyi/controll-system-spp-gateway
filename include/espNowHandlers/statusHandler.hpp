#ifndef STATUS_HANDLER_HPP
#define STATUS_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/espNowHandlers/iEspNowHandler.hpp"
#include "../include/structures/connection_device.hpp"

class StatuslHandler : public IEspNowHandler {
    public:
        void handle(const JsonDocument& doc, const String macAddress) override;

    private:
        ConnectionDevice getDeviceByMacAddress(const String macAddress);
};

#endif // STATUS_HANDLER_HPP
