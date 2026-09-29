#ifndef ELECTRICAL_HANDLER_HPP
#define ELECTRICAL_HANDLER_HPP

#include <ArduinoJson.h>

#include "../include/espNowHandlers/iEspNowHandler.hpp"
#include "../include/structures/sensors.hpp"

class ElectricalHandler : public IEspNowHandler {
    public:
        void handle(const JsonDocument& doc, const String macAddress) override;
    
    private:
        Sensor getSensorByMacAddress(const String macAddress);
};

#endif // ELECTRICAL_HANDLER_HPP
