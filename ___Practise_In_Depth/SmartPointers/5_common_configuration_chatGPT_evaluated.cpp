#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

namespace Common {

    class Configuration {
    private:
        std::string databaseURL;
        std::size_t port;
        std::size_t timeout;

    public:
        Configuration(std::string databaseURL, std::size_t port, std::size_t timeout)
            : databaseURL{std::move(databaseURL)}, port{port}, timeout{timeout} {}

        // Return string by const reference to avoid unnecessary copy
        const std::string& getDatabaseURL() const {
            return databaseURL;
        }

        // Returning primitive by value is fine
        std::size_t getPort() const {
            return port;
        }

        std::size_t getTimeout() const {
            return timeout;
        }
    };
}

class DatabaseClient {
private:
    std::shared_ptr<Common::Configuration> config;

public:
    // Pass shared_ptr by value:
    // - clearly expresses shared ownership
    // - increments reference count for this client
    explicit DatabaseClient(std::shared_ptr<Common::Configuration> config)
        : config{std::move(config)} {
        if (!this->config) {
            throw std::invalid_argument("DatabaseClient received null configuration");
        }
    }

    void printConfig() const {
        std::cout << "[DatabaseClient] URL: " << config->getDatabaseURL()
                  << ", Port: " << config->getPort()
                  << ", Timeout: " << config->getTimeout() << "\n";
    }
};

class NetworkClient {
private:
    std::shared_ptr<Common::Configuration> config;

public:
    explicit NetworkClient(std::shared_ptr<Common::Configuration> config)
        : config{std::move(config)} {
        if (!this->config) {
            throw std::invalid_argument("NetworkClient received null configuration");
        }
    }

    void printConfig() const {
        std::cout << "[NetworkClient] URL: " << config->getDatabaseURL()
                  << ", Port: " << config->getPort()
                  << ", Timeout: " << config->getTimeout() << "\n";
    }
};

class CacheClient {
private:
    std::shared_ptr<Common::Configuration> config;

public:
    explicit CacheClient(std::shared_ptr<Common::Configuration> config)
        : config{std::move(config)} {
        if (!this->config) {
            throw std::invalid_argument("CacheClient received null configuration");
        }
    }

    void printConfig() const {
        std::cout << "[CacheClient] URL: " << config->getDatabaseURL()
                  << ", Port: " << config->getPort()
                  << ", Timeout: " << config->getTimeout() << "\n";
    }
};

int main() {
    auto config = std::make_shared<Common::Configuration>(
        "http://aws.com/dynamodb/mydb", 8080, 3
    );

    std::cout << "[config] ref count: " << config.use_count() << "\n";

    DatabaseClient db(config);
    std::cout << "[config] ref count: " << config.use_count() << "\n";
    db.printConfig();

    {
        NetworkClient nc(config);
        std::cout << "[config] ref count: " << config.use_count() << "\n";
        nc.printConfig();
    }

    std::cout << "[config] ref count: " << config.use_count() << "\n";

    CacheClient cc(config);
    std::cout << "[config] ref count: " << config.use_count() << "\n";
    cc.printConfig();

    return 0;
}