#ifndef DEVICES_HANDLER_HPP
#define DEVICES_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/wsHandlers/iWsHandler.hpp"

class DevicesHandler : public IWsHandler {
    public:
        void handle(const JsonDocument& doc) override;
};

#endif // DEVICES_HANDLER_HPP
