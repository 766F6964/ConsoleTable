#include "ConsoleTable.h"


ConsoleTable::ConsoleTable(std::initializer_list<std::string> cols) {
    headers = {cols};

    for (std::string column : headers) {
        widths.push_back(column.length());
    }
}


void ConsoleTable::setPadding(unsigned int n) {
    this->padding = n;
}


void ConsoleTable::setStyle(unsigned int n) {
    switch (n) {
        case 0 :
            style = BasicStyle;
            break;
        case 1 :
            style = LineStyle;
            break;
        case 2 :
            style = DoubleLineStyle;
            break;
        default :
            style = BasicStyle;
            break;
    }
}


bool ConsoleTable::addRow(std::initializer_list<std::string> row) {
    if (row.size() > widths.size()) {
        throw std::invalid_argument{"Appended row size must be same as header size"};
    }

    std::vector<std::string> r = std::vector<std::string>{row};
    rows.push_back(r);
    for (int i = 0; i < r.size(); ++i) {
        widths[i] = std::max(r[i].size(), widths[i]);
    }
    return true;
}


bool ConsoleTable::removeRow(unsigned int index) {
    if (index > rows.size())
        return false;

    rows.erase(rows.begin() + index);
    return true;
}


ConsoleTable &ConsoleTable::operator+=(std::initializer_list<std::string> row) {
    if (row.size() > widths.size()) {
        throw std::invalid_argument{"Appended row size must be same as header size"};
    }

    addRow(row);
    return *this;
}


ConsoleTable &ConsoleTable::operator-=(unsigned int rowIndex) {
    if (rows.size() < rowIndex)
        throw std::out_of_range{"Row index out of range."};

    removeRow(rowIndex);

}


std::string ConsoleTable::getLine(RowType rowType) const {
    std::stringstream line;
    line << rowType.left;
    for (int i = 0; i < widths.size(); ++i) {
        for (int j = 0; j < (widths[i] + padding + padding); ++j) {
            line << style.horizontal;
        }
        line << (i == widths.size() - 1 ? rowType.right : rowType.intersect);
    }
    return line.str() + "\n";
}


std::string ConsoleTable::getHeaders(Headers headers) const {
    std::stringstream line;
    line << style.vertical;
    for (int i = 0; i < headers.size(); ++i) {
        std::string text = headers[i];
        line << space * padding + text + space * (widths[i] - text.length()) + space * padding;
        line << style.vertical;
    }
    line << "\n";
    return line.str();
}


std::string ConsoleTable::getRows(Rows rows) const {
    std::stringstream line;
    for (int i = 0; i < rows.size(); ++i) {
        line << style.vertical;
        for (int j = 0; j < rows[i].size(); ++j) {
            std::string text = rows[i][j];
            line << space * padding + text + space * (widths[j] - text.length()) + space * padding;
            line << style.vertical;
        }
        line << "\n";
    }

    return line.str();
}


std::ostream &operator<<(std::ostream &out, const ConsoleTable &consoleTable) {
    out << consoleTable.getLine(consoleTable.style.top);
    out << consoleTable.getHeaders(consoleTable.headers);
    out << consoleTable.getLine(consoleTable.style.middle);
    out << consoleTable.getRows(consoleTable.rows);
    out << consoleTable.getLine(consoleTable.style.bottom);
    return out;
}

bool ConsoleTable::sort(bool ascending) {
    if (ascending)
        std::sort(rows.begin(), rows.end(), std::less<std::vector<std::string>>());
    else
        std::sort(rows.begin(), rows.end(), std::greater<std::vector<std::string>>());
    return true;
}


std::string operator*(const std::string &other, int repeats) {
    std::string ret;
    ret.reserve(other.size() * repeats);
    for (; repeats; --repeats)
        ret.append(other);
    return ret;
}