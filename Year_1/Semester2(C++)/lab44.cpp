#include <iostream>
#include <string>
#include <vector>

class DeviceRegistry {
private:
    std::vector<AbstractSmartDevice*> devices_;

public:
    // Constructor
    DeviceRegistry() {
        // devices_ vector is automatically initialized as empty
    }

    // Destructor - responsible for freeing memory of all stored devices
    ~DeviceRegistry() {
        // Delete all dynamically allocated devices
        for (AbstractSmartDevice* device : devices_) {
            delete device;
        }
        devices_.clear();
    }

    // Disable copy constructor and copy assignment operator
    DeviceRegistry(const DeviceRegistry&) = delete;
    DeviceRegistry& operator=(const DeviceRegistry&) = delete;

    // Adds a device (registry takes ownership of the pointer)
    void addDevice(AbstractSmartDevice* device_ptr) {
        if (device_ptr != nullptr) {
            devices_.push_back(device_ptr);
        }
    }

    // Finds a device by ID (returns a non-owning raw pointer)
    AbstractSmartDevice* findDeviceByID(const std::string& id_string) const {
        for (AbstractSmartDevice* device : devices_) {
            if (device && device->getDeviceIDString() == id_string) {
                return device;
            }
        }
        return nullptr;
    }

    // Displays info for all devices
    void displayAllDevicesInfo() const {
        for (AbstractSmartDevice* device : devices_) {
            if (device) {
                std::cout << device->getDeviceInfo() << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }
    }

    // Removes and deletes a device by ID
    bool removeDeviceByID(const std::string& id_string) {
        for (auto it = devices_.begin(); it != devices_.end(); ++it) {
            if (*it && (*it)->getDeviceIDString() == id_string) {
                delete *it;  // Free the memory
                devices_.erase(it);  // Remove pointer from vector
                return true;
            }
        }
        return false;
    }
}; 