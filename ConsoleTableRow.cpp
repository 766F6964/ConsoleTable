#include "ConsoleTableRow.h"

ConsoleTableRow::ConsoleTableRow(int width) {
    row.resize(width);
}

void ConsoleTableRow::addEntry(std::string data, int column) {
    row.at(column) = data;
}

std::vector<std::string> ConsoleTableRow::getEntry() const&{
    return row;
}

void ConsoleTableRow::editEntry(std::string data, int column) {
    row.at(column) = data;
}
