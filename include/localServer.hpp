#ifndef LOCAL_SERVER_HPP
#define LOCAL_SERVER_HPP

#include <WebServer.h>

class LocalServer {
    public:
        void begin();
        void loop();

    private:
        WebServer server{80};
        void handleClick();
};

#endif // LOCAL_SERVER_HPP
