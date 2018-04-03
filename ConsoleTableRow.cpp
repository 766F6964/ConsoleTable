#include "ConsoleTableRow.h"

ConsoleTableRow::ConsoleTableRow(int width) {
    this->row.resize(width);
}

void ConsoleTableRow::addEntry(std::string data, int column) {
    row[column] = data;
}

std::vector<std::string> ConsoleTableRow::getEntry() const&{
    return this->row;
}

void ConsoleTableRow::editEntry(std::string data, int column) {
    this->row[column] = data;
}
