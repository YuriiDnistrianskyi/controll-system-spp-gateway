#ifndef I_ESP_NOW_HANDLER_HPP
#define I_ESP_NOW_HANDLER_HPP

#include <ArduinoJson.h>

class IEspNowHandler {
    public:
        virtual void handle(const JsonDocument& doc, const String& macAddress) = 0;
};

#endif // I_ESP_NOW_HANDLER_HPP
