#include <iostream>

// Class Log
class Log {
public:
    // Get instance of Log
    static Log& getInstance() {
        // Create a static local instance
        static Log instance;
        // Return the instance
        return instance;
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
    // Private constructor to prevent instantiation
    Log() = default;
};

// Main
int main() {
    // Initialize log1 to be the instance of Log
    Log& log1 = Log::getInstance();
    // Log a message to log1
    log1.log("Hello World!");

    // Initialize log2 to be the instance of Log
    Log& log2 = Log::getInstance();
    // Log a message to log2; it will be to the same instance
    log2.log("Same Instance!");

    return 0;
}