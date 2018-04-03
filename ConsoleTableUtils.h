#ifndef CONSOLETABLE_CONSOLETABLEUTILS_H
#define CONSOLETABLE_CONSOLETABLEUTILS_H

#include <string>
#include <sstream>

class ConsoleTableUtils {
public:

    static std::string repeatString(std::string input, int n){
        std::ostringstream os;
        for (int i = 0; i < n; i++)
            os << input;
        return os.str();
    }

};


#endif //CONSOLETABLE_CONSOLETABLEUTILS_H
