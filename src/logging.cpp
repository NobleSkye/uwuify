#include <string>
#include <fmt/core.h>
#include <iomanip>
#include <ctime>

class Logger {
public:
    Logger() {}
    bool verboseLoggingEnabled = false;
    void verbose(std::string msg) {
        if(!verboseLoggingEnabled) return;
        fmt::print("{} {}\n", getPrefix(), msg);
    }
private:
    // [%d-%m-%Y - %H:%M:%S]
    std::string getPrefix() {
        time_t time = std::time(nullptr);
        tm localtime = *std::localtime(&time);
        std::ostringstream oss;
        oss << std::put_time(&localtime, "[%d-%m-%Y - %H:%M:%S]");
        return oss.str();
    }
};