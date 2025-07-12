#include <fmt/core.h>
#include "logging.cpp"

int main(int argc, char** argv) {
    Logger logger;
    logger.verboseLoggingEnabled = true;
    logger.verbose("hii :3");
}