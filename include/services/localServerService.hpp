#ifndef LOCAL_SERVER_SERVICE_HPP
#define LOCAL_SERVER_SERVICE_HPP

#include <WebServer.h>
#include "../include/services/iService.hpp"

class LocalServerService : public IService{
    public:
        void setup();
        void loop();

    private:
        WebServer server{80};
        void handleClick();
};

#endif // LOCAL_SERVER_SERVICE_HPP
