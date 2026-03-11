/*
Problem 3 — Device Manager

Scenario:
You are designing a Self-Checkout device system.
    Devices include:
        Scanner
        Printer
        Scale

    All inherit from: class Device

Requirements:
    DeviceManager must:
        store multiple devices
        start all devices
        stop all devices
        remove device by id

class DeviceManager
{
    addDevice(...)
    removeDevice(...)
    startAll()
    stopAll()
}

Constraints:
    Devices should be polymorphic.
*/
#include <iostream>
#include <memory>
#include <vector>

namespace DeviceManager {
    class IDevice {
    private:
        int id;
        static int cnt;
    public:
        IDevice():id{++cnt} {}

        int getId() { return id; }
    
        virtual void stopDevice() = 0;
        virtual void startDevice() = 0;

        virtual ~IDevice() = default;
    };
    int IDevice::cnt = 0;

    class Scanner final: public IDevice {
    public:
        Scanner() {
            std::cout << "[Scanner] : initiated\n";
        }
        void stopDevice() override final{
            std::cout << "[Scanner] : stoped\n";
        }
        void startDevice() override final {
            std::cout << "[Scanner] : started\n";
        }
        ~Scanner() {
            std::cout << "[Scanner] : destroyed\n";
        }
    };

    class Printer: public IDevice {
    public:
        Printer() {
            std::cout << "[Printer] : initiated\n";
        }
        void stopDevice() override final{
            std::cout << "[Printer] : stoped\n";
        }
        void startDevice() override final {
            std::cout << "[Printer] : started\n";
        }
        ~Printer() {
            std::cout << "[Printer] : destroyed\n";
        }
    };

    class Scale: public IDevice {
    public:
        Scale() {
            std::cout << "[Scale]   : initiated\n";
        }
        void stopDevice() override final{
            std::cout << "[Scale]   : stoped\n";
        }
        void startDevice() override final {
            std::cout << "[Scale]   : started\n";
        }
        ~Scale() {
            std::cout << "[Scale]   : destroyed\n";
        }
    };

    class DeviceManager {
    private:
        std::vector<std::unique_ptr<IDevice>> devices;
    public:
        DeviceManager(){
            std::cout <<"[DeviceManager]::DeviceManager initiated\n";
        }

        void addDevice(std::unique_ptr<IDevice> device) {
            devices.push_back(std::move(device));
        }

        void removeDevice(int id) {
            for(auto& device: devices) {
               if((device -> getId()) == id) {
                    device.reset(nullptr);
               }
            }
        }

        void startAll() {
            for(auto& device: devices) {
                if(device) {
                    device -> startDevice();
                }
            }
        }

        void stopAll() {
            for(auto& device: devices) {
                if(device) {
                    device -> stopDevice();
                }
            }
        }
    };
}


int main() {
    DeviceManager::DeviceManager dm;
    std::unique_ptr<DeviceManager::IDevice> uptr_scanner  = std::make_unique<DeviceManager::Scanner>();
    std::unique_ptr<DeviceManager::IDevice> uptr_printer  = std::make_unique<DeviceManager::Printer>();
    int p_id = uptr_printer -> getId();
    std::unique_ptr<DeviceManager::IDevice> uptr_scale  = std::make_unique<DeviceManager::Scale>();

    dm.addDevice(std::move(uptr_scanner));
    dm.addDevice(std::move(uptr_printer));
    dm.addDevice(std::move(uptr_scale));

    dm.startAll();
    dm.removeDevice(p_id);
    dm.stopAll();

    return 0;
}