/*
Problem 5 — Shared Configuration System

Scenario:
    An application has one Config object that contains settings like:
        databaseUrl
        port
        timeout

    Multiple components use this configuration:

        DatabaseClient
        NetworkClient
        CacheClient

Requirements:
All components must access the same configuration
Configuration should remain alive while any component uses it

*/

#include <iostream>
#include <memory>

namespace Common {
    class Configuration {
    private:
        std::string databaseURL;
        std::size_t port;
        std::size_t timeout;
    public:
        Configuration(std::string databaseURL , std::size_t port ,std::size_t timeout ): 
            databaseURL{databaseURL} , port{port} , timeout{timeout} {}
        
        const std::string getDatabaseURL() const { return databaseURL; }
        const std::size_t   getPort() const { return port; }
        const std::size_t   getTimeout() const { return timeout; }
    };
}

class DatabaseClient{
private:
    std::shared_ptr<Common::Configuration> config;
public:
    DatabaseClient(std::shared_ptr<Common::Configuration>& sharedptr_config) {
        config = sharedptr_config;
    }
};

class NetworkClient{
private:
    std::shared_ptr<Common::Configuration> config;
public:
    NetworkClient(std::shared_ptr<Common::Configuration>& sharedptr_config) {
        config = sharedptr_config;
    }
};

class CacheClient{
private:
    std::shared_ptr<Common::Configuration> config;
public:
    CacheClient(std::shared_ptr<Common::Configuration>& sharedptr_config) {
        config = sharedptr_config;
    }
};

int main() {
    std::shared_ptr<Common::Configuration> config = std::make_shared<Common::Configuration>("http://aws.com/dynamodb/mydb" , 8080 , 3);
    std::cout << "[config] ref count : " << config.use_count() << "\n";
    DatabaseClient db(config);
    std::cout << "[config] ref count : " << config.use_count() << "\n";
    {
        NetworkClient nc(config);
        std::cout << "[config] ref count : " << config.use_count() << "\n";
    }
    std::cout << "[config] ref count : " << config.use_count() << "\n";
    CacheClient cc(config);
    std::cout << "[config] ref count : " << config.use_count() << "\n";
    return 0;
}