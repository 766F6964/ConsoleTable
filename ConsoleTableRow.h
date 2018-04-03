#ifndef CONSOLETABLE_CONSOLETABLEROW_H
#define CONSOLETABLE_CONSOLETABLEROW_H

#include <string>
#include <vector>

class ConsoleTableRow {
public:

    explicit ConsoleTableRow(int width);

    void addEntry(std::string data, int column);

    void editEntry(std::string data, int column);

    std::vector <std::string> getEntry() const&;

private:
    std::vector <std::string> row;
};


#endif //CONSOLETABLE_CONSOLETABLEROW_H
