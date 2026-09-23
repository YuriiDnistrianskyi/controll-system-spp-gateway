#ifndef CONNECTING_MANAGER_HPP
#define CONNECTING_MANAGER_HPP

class WebSocketManager {
    public:
        void connect();
        void disconnect();

        void loop();

        void send();

    private:
        bool isConnected;
};

#endif // CONNECTING_MANAGER_HPP
