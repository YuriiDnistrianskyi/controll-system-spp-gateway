#include <Preferences.h>
#include "../include/core/configStorage.hpp"

void ConfigStorage::begin() {
    prefs.begin("config");
}

int ConfigStorage::getGatewayId() {
    return prefs.getInt("gatewayId");
}

void ConfigStorage::setGatewayId(int id) {
    prefs.putInt("gatewayId", id);
}

String ConfigStorage::getActivationCode() {
    return prefs.getString("activationCode");
}

void ConfigStorage::setActivationCode(const String& code) {
    prefs.putString("activationCode", code);
}

String ConfigStorage::getDeviceToken() {
    return prefs.getString("deviceToken");
}

void ConfigStorage::setDeviceToken(const String& token) {
    prefs.putString("deviceToken", token);
}

String ConfigStorage::getWifiSSID() {
    return prefs.getString("wifiSSID");
}

void ConfigStorage::setWifiSSID(const String& token) {
    prefs.putString("wifiSSID", token);
}

String ConfigStorage::getWifiPassword() {
    return prefs.getString("wifiPassword");
}

void ConfigStorage::setWifiPassword(const String& token) {
    prefs.putString("wifiPassword", token);
}
