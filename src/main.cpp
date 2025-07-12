#include <fmt/core.h>
#include "logging.cpp"
#include "util/cmdlineargs.cpp"
#include "util/utils.cpp"

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

    std::string filename;
    bool skipped = false;
    // find file in the args
    for(std::string arg : args) {
        if(arg.rfind("-", 0) == 0) continue;
        if(skipped == false) {
            skipped = true;
            continue;
        }
        filename = arg;
        break;
    }
    logger.verbose("Attempting to open file: " + filename);
    std::string fileContent = readFileToString(filename);
}