#ifndef STATUS_HANDLER_HPP
#define STATUS_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/espNowHandlers/iEspNowHandler.hpp"

class StatuslHandler : public IEspNowHandler {
    public:
        void handle(const JsonDocument& doc, const String macAddress) override;
};

#endif // STATUS_HANDLER_HPP
