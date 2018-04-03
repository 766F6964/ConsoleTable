#ifndef CONSOLETABLE_CONSOLETABLEUTILS_H
#define CONSOLETABLE_CONSOLETABLEUTILS_H

#include <string>
#include <sstream>

class ConsoleTableUtils {
public:

    /// Repeats a given string n times
    /// \param input The string which should be repeated
    /// \param n How many times should the given string be repeated
    /// \return The repeated string
    static std::string repeatString(const std::string &input, int n){
        std::ostringstream os;
        for (int i = 0; i < n; i++)
            os << input;
        return os.str();
    }

};

#endif //CONSOLETABLE_CONSOLETABLEUTILS_H
