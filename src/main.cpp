#include <fmt/core.h>
#include "logging.cpp"
#include "util/cmdlineargs.cpp"

int main(int argc, char** argv) {
    auto args = convertArgsToVector(argc, argv);
    Logger logger;
    if(argsContains(args, cmdlargs::VERBOSE)) {
        logger.verboseLoggingEnabled = true;
        logger.verbose("Using verbose logging");
    }
    else if(argsContains(args, cmdlargs::NO_VERBOSE)) {
        logger.verboseLoggingEnabled = false;
    }
}