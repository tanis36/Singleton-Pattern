#include <iostream>
#include <memory>
#include <mutex>

// Class Log
class Log {
public:
    // Get instance of Log
    static Log& getInstance() {
        // Lock guard
        std::lock_guard<std::mutex> lock(mutex);
        // IF there is no instance, create instance
        if (!instance) {
            instance = std::make_unique<Log>();
        }
        // Return the instance
        return *instance;
    }

    // Log a message
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }

    // Delete the copy constructor
    Log(const Log&) = delete;
    // Delete the copy assignment operator
    Log& operator=(const Log&) = delete;

private:
    // Instance of the Log
    static std::unique_ptr<Log> instance;
    // Mutex for thread safety
    static std::mutex mutex;
    // Private constructor to prevent instantiation
    Log() = default;
};

int main() {
    
}