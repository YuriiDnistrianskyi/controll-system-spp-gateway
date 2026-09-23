#ifndef WIFI_MANAGER_HPP
#define WIFI_MANAGER_HPP

class WifiManager {
    public:
        void initWifi();
        bool connectToWifi(const char* ssid, const char* password);
};

#endif // WIFI_MANAGER_HPP
