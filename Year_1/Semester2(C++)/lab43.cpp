#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

// LightDevice Class - Concrete smart light device
class LightDevice : public AbstractSmartDevice {
private:
    int brightness_; // 0-100
    std::string color_;

public:
    LightDevice(const std::string& name, const Location& location, 
                int initial_brightness = 0, const std::string& initial_color = "White")
        : AbstractSmartDevice(name, location, 'L'), 
          brightness_(initial_brightness), 
          color_(initial_color) {
        // If initial brightness > 0, device should be on
        if (initial_brightness > 0) {
            is_on_ = true;
        }
    }

    // Overridden methods from AbstractSmartDevice
    std::string getDeviceInfo() const override {
        std::ostringstream oss;
        oss << "Device Info: Light - " << name_ << " (ID: " << id_.getIDString() 
            << ") at " << location_.toString() << ". Color: " << color_ 
            << ", Brightness: " << brightness_ << "%";
        return oss.str();
    }

    void turnOn() override {
        is_on_ = true;
        // If brightness was 0, set to default 50
        if (brightness_ == 0) {
            brightness_ = 50;
        }
    }

    void turnOff() override {
        is_on_ = false;
        brightness_ = 0;
    }

    std::string getStatusString() const override {
        std::ostringstream oss;
        oss << (is_on_ ? "ON" : "OFF") << ", Brightness: " << brightness_ 
            << "%, Color: " << color_;
        return oss.str();
    }

    // LightDevice specific methods
    void setBrightness(int brightness) {
        if (brightness >= 0 && brightness <= 100) {
            brightness_ = brightness;
            // Update on/off state based on brightness
            if (brightness_ == 0) {
                is_on_ = false;
            } else if (!is_on_) {
                is_on_ = true;
            }
        }
    }

    int getBrightness() const {
        return brightness_;
    }

    void setColor(const std::string& color) {
        color_ = color;
    }

    std::string getColor() const {
        return color_;
    }
};

// ThermostatDevice Class - Concrete smart thermostat device
class ThermostatDevice : public AbstractSmartDevice {
private:
    double current_temperature_celsius_;
    double target_temperature_celsius_;

public:
    ThermostatDevice(const std::string& name, const Location& location, 
                     double initial_target_temp = 22.0)
        : AbstractSmartDevice(name, location, 'T'), 
          current_temperature_celsius_(20.0), // Default current temp
          target_temperature_celsius_(initial_target_temp) {
        // Device starts regulating temperature by default
        is_on_ = true;
    }

    // Overridden methods
    std::string getDeviceInfo() const override {
        std::ostringstream oss;
        oss << "Device Info: Thermostat - " << name_ << " (ID: " << id_.getIDString() 
            << ") at " << location_.toString() << ". Current Temp: " 
            << std::fixed << std::setprecision(1) << current_temperature_celsius_ 
            << "C, Target Temp: " << target_temperature_celsius_ << "C";
        return oss.str();
    }

    void turnOn() override {
        is_on_ = true; // Start/resume regulation
    }

    void turnOff() override {
        is_on_ = false; // Stop regulation
    }

    std::string getStatusString() const override {
        std::ostringstream oss;
        oss << (is_on_ ? "ON" : "OFF") << ", Current: " 
            << std::fixed << std::setprecision(1) << current_temperature_celsius_ 
            << "C, Target: " << target_temperature_celsius_ << "C";
        return oss.str();
    }

    // Thermostat specific methods
    void setTargetTemperature(double temp_celsius) {
        target_temperature_celsius_ = temp_celsius;
    }

    double getTargetTemperature() const {
        return target_temperature_celsius_;
    }

    double getCurrentTemperature() const {
        return current_temperature_celsius_;
    }
};

// SecurityDevice Class - Concrete smart security device
class SecurityDevice : public AbstractSmartDevice {
private:
    bool is_armed_;
    bool alarm_triggered_;

public:
    SecurityDevice(const std::string& name, const Location& location)
        : AbstractSmartDevice(name, location, 'S'), 
          is_armed_(false), 
          alarm_triggered_(false) {
        // Device starts powered on and in standby
        is_on_ = true;
    }

    // Overridden methods
    std::string getDeviceInfo() const override {
        std::ostringstream oss;
        oss << "Device Info: Security - " << name_ << " (ID: " << id_.getIDString() 
            << ") at " << location_.toString() << ". Armed: " 
            << (is_armed_ ? "Yes" : "No") << ", Alarm: " 
            << (alarm_triggered_ ? "Yes" : "No");
        return oss.str();
    }

    void turnOn() override {
        is_on_ = true; // Power on device, enter standby
    }

    void turnOff() override {
        is_on_ = false; // Power off device
        is_armed_ = false; // Disarm when powered off
        alarm_triggered_ = false; // Reset alarm when powered off
    }

    std::string getStatusString() const override {
        std::ostringstream oss;
        if (is_on_) {
            oss << "ON (Standby), Armed: " << (is_armed_ ? "Yes" : "No") 
                << ", Alarm Triggered: " << (alarm_triggered_ ? "Yes" : "No");
        } else {
            oss << "OFF, Armed: " << (is_armed_ ? "Yes" : "No") 
                << ", Alarm Triggered: " << (alarm_triggered_ ? "Yes" : "No");
        }
        return oss.str();
    }

    // SecurityDevice specific methods
    void arm() {
        if (is_on_) {
            is_armed_ = true;
        }
    }

    void disarm() {
        is_armed_ = false;
    }

    void triggerAlarm() {
        if (is_armed_ && is_on_) {
            alarm_triggered_ = true;
        }
    }

    void resetAlarm() {
        alarm_triggered_ = false;
    }

    bool isArmed() const {
        return is_armed_;
    }

    bool isAlarmTriggered() const {
        return alarm_triggered_;
    }
}; 