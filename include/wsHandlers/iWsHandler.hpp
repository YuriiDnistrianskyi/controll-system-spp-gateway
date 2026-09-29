#ifndef I_WS_HANDLER_HPP
#define I_WS_HANDLER_HPP

#include <ArduinoJson.h>

class IWsHandler {
    public:
        virtual void handle(const JsonDocument& doc) = 0;
};

#endif // I_WS_HANDLER_HPP
