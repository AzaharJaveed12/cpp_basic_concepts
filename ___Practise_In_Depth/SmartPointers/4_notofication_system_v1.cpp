/*
Problem 4 — Notification Factory

Scenario:
    You are building a notification system.

Types of notifications:
    EmailNotification
    SMSNotification
    PushNotification
All derive from:
    class Notification


Requirements:
    Create a factory function:
        createNotification(type)

    that returns an instance of the correct notification.

Each notification implements:
    send(string message)

*/
#include <iostream>
#include <memory>

namespace Notification {

    enum class NOTIFICATION_TYPE {
        EMAIL,
        SMS
    };

    class INotification {
    public:
        virtual void send(std::string message) = 0;
        virtual ~INotification() = default;
    };

    class SMSNotification : public INotification {
    private:
        int number;
    public:
        SMSNotification(int number) {
            this -> number = number;
        }
        void send(std::string message) override final {
            std::cout <<"[SMSNotification]   : sending message " << message <<" to mobile number " << number << "\n";
        }
    };

    class EmailNotification : public INotification {
    private:
        std::string email;
    public:
        EmailNotification(std::string email) {
            this -> email = email;
        }
    
        void send(std::string message) override final {
            std::cout <<"[EmailNotification]   : sending message " << message <<" to " << email << "\n";
        }
    };
}

namespace NotificationCreater {
    class INotificationCreator {
    public:
        virtual std::unique_ptr<Notification::INotification> create() = 0;
        virtual ~INotificationCreator() = default;
    };

    class EmailNotificationCreator : public INotificationCreator {
        std::string email;
    public:
        EmailNotificationCreator(std::string& email)  {
            this -> email = email;
        }

        std::unique_ptr<Notification::INotification> create() override final {
            return std::make_unique<Notification::EmailNotification>(email);            
        }
    };

    class SMSNotificationCreator : public INotificationCreator {
        int number;
    public:
        SMSNotificationCreator(int number)  {
            this -> number = number;
        }

        std::unique_ptr<Notification::INotification> create() override final {
            return std::make_unique<Notification::SMSNotification>(number);            
        }
    };
}

int main() {
    using namespace Notification;
    using namespace NotificationCreater;
    using namespace std;

    string email = "javeedshareef995199@gmail.com";
    unique_ptr<INotificationCreator> uptr_emailNotificationCreator = make_unique<EmailNotificationCreator>(email);
    unique_ptr<INotificationCreator> uptr_smsNotificationCreator = make_unique<SMSNotificationCreator>(1234567890);

    auto emailNotification = uptr_emailNotificationCreator->create();
    auto smsNotification = uptr_smsNotificationCreator->create();

    emailNotification->send(" Assalamu-alikum bhai");
    smsNotification->send("ham sab saat saat hai");
}