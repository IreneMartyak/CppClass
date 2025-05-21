#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <windows.h>

// Base Logger interface
template<typename T>
class Logger {
public:
    virtual void log(const T& message) const = 0;
    virtual ~Logger() = default;
};

// Concrete Logger implementation
template<typename T>
class BasicLogger : public Logger<T> {
public:
    void log(const T& message) const override {
        std::cout << "Log: " << message << std::endl;
    }
};

// Decorator for adding timestamps
template<typename T>
class TimestampLogger : public Logger<T> {
private:
    std::shared_ptr<Logger<T>> logger_;
public:
    explicit TimestampLogger(std::shared_ptr<Logger<T>> logger) : logger_(std::move(logger)){}

    void log(const T& message) const override {
        const std::time_t now = std::time(nullptr);
        char timeString[30]{};
        std::strftime(timeString, sizeof(timeString), "%A %c", std::localtime(&now)); // https://en.cppreference.com/w/cpp/chrono/c/strftime
        std::cout << "[Timestamp: " <<  timeString << "] ";
        logger_->log(message);
    }
};

// Decorator for adding user authentication info
template<typename T>
class AuthLogger : public Logger<T> {
private:
    std::shared_ptr<Logger<T>> logger_;
public:
    explicit AuthLogger(std::shared_ptr<Logger<T>> logger) : logger_(std::move(logger)) {}

    void log(const T& message) const override {
        unsigned __LONG32 buffer_length = 20UL;
        char buffer_name[buffer_length]{};

        if ( GetUserNameA(buffer_name, &buffer_length) )
        {
            std::cout << "[" << buffer_name <<"] ";
        }
        else{
            std::cout << "[WARNING : failed to retrieve user] ";
        }
        logger_->log(message);
    }
};

// Decorator for adding request context
template<typename T>
class RequestContextLogger : public Logger<T> {
private:
    std::shared_ptr<Logger<T>> logger_;
public:
    explicit RequestContextLogger(std::shared_ptr<Logger<T>> logger) : logger_(std::move(logger)) {}

    void log(const T& message) const override {
        std::cout << "[Request ID: 12345] ";
        logger_->log(message);
        std::cout << " ****** ";
    }
};

int main() {
    // Create the basic logger
    auto basicLogger = std::make_shared<BasicLogger<std::string>>();

    // Apply decorators to add functionality
    auto timestampedLogger = std::make_shared<TimestampLogger<std::string>>(basicLogger);
    auto authLogger = std::make_shared<AuthLogger<std::string>>(timestampedLogger);
    auto requestContextLogger = std::make_shared<RequestContextLogger<std::string>>(authLogger);
    

    // Log a message with all decorators applied
    requestContextLogger->log("API request received"); // RequestContextLogger( Final message)(Functionality)->AuthLogger( Final message)(Functionality)->timestampedLogger(Final message)(Functionality)->BasicLogger(Final message)

    return 0;
}
// basicLogger <-  timestampedLogger <- authLogger <- requestContextLogger.log