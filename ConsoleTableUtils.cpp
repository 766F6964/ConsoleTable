#include "ConsoleTableUtils.h"

std::string ConsoleTableUtils::repeatString(std::string input, int n) const {
    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << input;
    return os.str();
}