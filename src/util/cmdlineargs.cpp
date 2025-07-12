#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> convertArgsToVector(int argc, char** argv) {
    std::vector<std::string> args;
    for(int i = 0; i < argc; i++) {
        std::string s(argv[i]);
        args.push_back(s);
    }
    return args;
}

bool argsContains(std::vector<std::string> args, std::string arg) {
    return std::find(args.begin(), args.end(), arg) != args.end();
}
// bool argsContains(std::vector<std::string> args, char* arg) {
//     std::string s_arg(arg);
//     return argsContains(args, s_arg);
// }

namespace cmdlargs {
    const char* VERBOSE = "--verbose";
    const char* NO_VERBOSE = "--no-verbose";
}