#include <iostream>
#include <string>
#include <vector>

class Room {
private:
    UID uid_;
    std::string roomName_;
    std::vector<AbstractSmartDevice*> device_references_in_room_;

public:
    // Constructor
    Room(const std::string& name, char uid_prefix = 'R')
        : uid_(uid_prefix), roomName_(name) {
    }

    // Default destructor
    ~Room() = default;

    // Default copy and move operations
    Room(const Room&) = default;
    Room& operator=(const Room&) = default;
    Room(Room&&) = default;
    Room& operator=(Room&&) = default;

    std::string getRoomIDString() const {
        return uid_.getIDString();
    }

    std::string getRoomName() const {
        return roomName_;
    }

    int getDeviceCount() const {
        return static_cast<int>(device_references_in_room_.size());
    }

    void addDeviceReference(AbstractSmartDevice* device_ptr) {
        if (device_ptr != nullptr) {
            device_references_in_room_.push_back(device_ptr);
        }
    }

    bool removeDeviceReference(const std::string& device_id_string) {
        for (auto it = device_references_in_room_.begin(); it != device_references_in_room_.end(); ++it) {
            if (*it && (*it)->getDeviceIDString() == device_id_string) {
                device_references_in_room_.erase(it);
                return true;
            }
        }
        return false;
    }

    void displayDevicesInRoom() const {
        for (AbstractSmartDevice* device : device_references_in_room_) {
            if (device) {
                std::cout << "  Device: " << device->getName() << " (ID: " << device->getDeviceIDString() << ")"
                          << ", Status: " << device->getStatusString() << std::endl;
            }
        }
    }

    void turnOffAllLightsInRoom() {
        for (AbstractSmartDevice* device : device_references_in_room_) {
            if (device) {
                LightDevice* lightDevice = dynamic_cast<LightDevice*>(device);
                if (lightDevice) {
                    lightDevice->turnOff();
                }
            }
        }
    }
}; 