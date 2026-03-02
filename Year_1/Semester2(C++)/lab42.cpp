#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

// AbstractSmartDevice Class - Abstract base class for all smart devices
class AbstractSmartDevice {
protected:
    UID id_;
    std::string name_;
    Location location_;
    bool is_on_; // Common state for on/off

public:
    // Constructor
    AbstractSmartDevice(const std::string& name, const Location& location, char uid_prefix = 'D')
        : id_(uid_prefix), name_(name), location_(location), is_on_(false) {}

    // Virtual destructor (defaulted)
    virtual ~AbstractSmartDevice() = default;

    // Getter methods
    std::string getDeviceIDString() const {
        return id_.getIDString();
    }

    std::string getName() const {
        return name_;
    }

    Location getLocation() const {
        return location_;
    }

    bool isOn() const {
        return is_on_;
    }

    // Pure virtual functions - defining the device interface
    virtual std::string getDeviceInfo() const = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatusString() const = 0;

    // Forbid copying and assignment, as each smart device should be unique (via ID),
    // and abstract classes are generally not meant to be copied.
    AbstractSmartDevice(const AbstractSmartDevice&) = delete;
    AbstractSmartDevice& operator=(const AbstractSmartDevice&) = delete;
}; 