#ifndef CONFIG_STORAGE_HPP
#define CONFIG_STORAGE_HPP

#include <Preferences.h>

class ConfigStorage {
    public:
        void begin();

        int getGatewayId();
        void setGatewayId(int id);

        String getDeviceToken();
        void setDeviceToken(const String& token);

        String getWifiSSID();
        void setWifiSSID(const String& ssid);

        String getWifiPassword();
        void setWifiPassword(const String& password);

    private:
        Preferences prefs;
};

#endif // CONFIG_STORAGE_HPP
