#include "ConsoleTable.h"


ConsoleTable::ConsoleTable(TableStyle style) {
    setTableStyle(style);
    this->utils = new ConsoleTableUtils();
}

void ConsoleTable::addColumn(std::string name) {
    this->columns.push_back(name);
}

void ConsoleTable::printTable() {

    // Calculate column maxima
    std::vector<int> maxWidths(this->columns.size());
    for (int row = 0; row < this->entries.size(); row++) {
        for (int col = 0; col < this->columns.size(); col++) {
            std::string cellText = this->entries[row]->getEntry()[col];
            if (this->columns[col].length() > maxWidths[col])
                maxWidths[col] = this->columns[col].length();
            if (maxWidths[col] < cellText.length()) {
                maxWidths[col] = cellText.length();
            }
        }
    }

    printHorizontalSeperator(maxWidths, SEPERATOR_TOP);

    // Print column values
    for (int col = 0; col < this->columns.size(); col++) {
        std::string cellText = this->columns[col];
        int len = cellText.length();
        std::string paddedText = cellText + std::string(maxWidths[col] - len, ' ');
        std::cout << this->style_line_vertical << std::string(this->padding, ' ') << paddedText
                  << std::string(this->padding, ' ');
        std::cout << (col == this->columns.size() - 1 ? this->style_line_vertical + "\n" : "");
    }

    printHorizontalSeperator(maxWidths, SEPERATOR_MIDDLE);

    // Print cell values
    for (int row = 0; row < this->entries.size(); row++) {
        for (int col = 0; col < this->columns.size(); col++) {
            std::string cellText = this->entries[row]->getEntry()[col];
            std::string paddedText = cellText + std::string(maxWidths[col] - cellText.length(), ' ');
            std::cout << this->style_line_vertical << std::string(this->padding, ' ') << paddedText
                      << std::string(this->padding, ' ');
        }
        std::cout << this->style_line_vertical << std::endl;
        if (row == this->entries.size() - 1)
            printHorizontalSeperator(maxWidths, SEPERATOR_BOTTOM);
        else
            printHorizontalSeperator(maxWidths, SEPERATOR_MIDDLE);
    }
}

void ConsoleTable::printHorizontalSeperator(const std::vector<int> &maxWidths, HorizontalSeperator seperator) const {
    for (int col = 0; col < columns.size(); ++col) {

        switch (seperator) {
            case SEPERATOR_TOP: {
                std::cout << (col == 0 ? this->style_edge_topleft : "");
                std::cout << utils->repeatString(this->style_line_horizontal, this->padding);
                std::cout << utils->repeatString(this->style_line_horizontal, maxWidths[col]);
                std::cout << utils->repeatString(this->style_line_horizontal, this->padding);
                std::cout << (col != columns.size() - 1 ? this->style_t_intersect_top : this->style_edge_topright);
                std::cout << (col == columns.size() - 1 ? "\n" : "");
                break;
            }
            case SEPERATOR_MIDDLE: {
                std::cout << (col == 0 ? this->style_t_intersect_left : "");
                std::cout << utils->repeatString(this->style_line_horizontal, this->padding);
                std::cout << utils->repeatString(this->style_line_horizontal, maxWidths[col]);
                std::cout << utils->repeatString(this->style_line_horizontal, this->padding);
                std::cout << (col != columns.size() - 1 ? this->style_line_cross : this->style_t_intersect_right);
                std::cout << (col == columns.size() - 1 ? "\n" : "");
                break;
            }
            case SEPERATOR_BOTTOM: {
                std::cout << (col == 0 ? this->style_edge_buttomleft : "");
                std::cout << utils->repeatString(this->style_line_horizontal, this->padding);
                std::cout << utils->repeatString(this->style_line_horizontal, maxWidths[col]);
                std::cout << utils->repeatString(this->style_line_horizontal, this->padding);
                std::cout
                        << (col != columns.size() - 1 ? this->style_t_intersect_bottom : this->style_edge_buttomright);
                std::cout << (col == columns.size() - 1 ? "\n" : "");
                break;
            }
        }
    }
}

void ConsoleTable::addRow(ConsoleTableRow *item) {
    this->entries.push_back(item);
}

bool ConsoleTable::removeRow(int index) {
    if (index > this->entries.size())
        return false;
    this->entries.erase(this->entries.begin() + index);
    return true;
}

bool ConsoleTable::editRow(std::string data, int row, int col) {
    if(row > this->entries.size())
        return false;

    if(col > this->columns.size())
        return false;

    auto entry = this->entries[row];
    entry->editEntry(data, col);
    return true;
}

void ConsoleTable::setPadding(unsigned int width) {
    this->padding = width;
}

void ConsoleTable::setTableStyle(TableStyle style) {
    switch (style) {
        case BASIC: {
            this->style_line_horizontal = "-";
            this->style_line_vertical = "|";
            this->style_line_cross = "+";

            this->style_t_intersect_right = "+";
            this->style_t_intersect_left = "+";
            this->style_t_intersect_top = "+";
            this->style_t_intersect_bottom = "+";

            this->style_edge_topleft = "+";
            this->style_edge_topright = "+";
            this->style_edge_buttomleft = "+";
            this->style_edge_buttomright = "+";
            break;
        }
        case LINED: {
            this->style_line_horizontal = "━";
            this->style_line_vertical = "┃";
            this->style_line_cross = "╋";

            this->style_t_intersect_right = "┫";
            this->style_t_intersect_left = "┣";
            this->style_t_intersect_top = "┳";
            this->style_t_intersect_bottom = "┻";

            this->style_edge_topleft = "┏";
            this->style_edge_topright = "┓";
            this->style_edge_buttomleft = "┗";
            this->style_edge_buttomright = "┛";
            break;
        }
        case DOUBLE_LINE: {
            this->style_line_horizontal = "═";
            this->style_line_vertical = "║";
            this->style_line_cross = "╬";

            this->style_t_intersect_right = "╣";
            this->style_t_intersect_left = "╠";
            this->style_t_intersect_top = "╦";
            this->style_t_intersect_bottom = "╩";

            this->style_edge_topleft = "╔";
            this->style_edge_topright = "╗";
            this->style_edge_buttomleft = "╚";
            this->style_edge_buttomright = "╝";
            break;
        }
    }
}
