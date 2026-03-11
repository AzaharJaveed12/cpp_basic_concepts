#include <iostream>
#include <memory>
#include <string>

namespace Notification {

enum class Type {
    EMAIL,
    SMS,
    PUSH
};

class INotification {
public:
    virtual void send(const std::string& message) = 0;
    virtual ~INotification() = default;
};

class EmailNotification : public INotification {
    std::string email;
public:
    explicit EmailNotification(std::string email)
        : email(std::move(email)) {}

    void send(const std::string& message) override {
        std::cout << "[Email] " << message << " -> " << email << "\n";
    }
};

class SMSNotification : public INotification {
    std::string number;
public:
    explicit SMSNotification(std::string number)
        : number(std::move(number)) {}

    void send(const std::string& message) override {
        std::cout << "[SMS] " << message << " -> " << number << "\n";
    }
};

class PushNotification : public INotification {
public:
    void send(const std::string& message) override {
        std::cout << "[Push] " << message << "\n";
    }
};

std::unique_ptr<INotification> createNotification(Type type)
{
    switch(type)
    {
        case Type::EMAIL:
            return std::make_unique<EmailNotification>("test@mail.com");

        case Type::SMS:
            return std::make_unique<SMSNotification>("9876543210");

        case Type::PUSH:
            return std::make_unique<PushNotification>();
    }

    return nullptr;
}

}

int main()
{
    auto email = Notification::createNotification(Notification::Type::EMAIL);
    auto sms = Notification::createNotification(Notification::Type::SMS);

    email->send("Hello");
    sms->send("World");
}