#ifndef ELECTRICAL_HANDLER_HPP
#define ELECTRICAL_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/espNowHandlers/iEspNowHandler.hpp"

class ElectricalHandler : public IEspNowHandler {
    public:
        void handle(const JsonDocument& doc, const String macAddress) override;
    
    private:
        bool sensorIsFront(const String macAddress);
};

#endif // ELECTRICAL_HANDLER_HPP
