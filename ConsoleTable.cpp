#include "ConsoleTable.h"


ConsoleTable::ConsoleTable(TableStyle style, unsigned int padding) {
    setTableStyle(style);
    this->padding = padding;
}

void ConsoleTable::addColumn(std::string name) {
    columns.push_back(name);
}

void ConsoleTable::printTable() {

    // Calculate column maxima
    std::vector<int> maxWidths(columns.size());
    for (auto &entry : rows) {
        for (int col = 0; col < columns.size(); col++) {
            std::string cellText = entry.getEntry().at(col);
            if (columns.at(col).length() > maxWidths.at(col))
                maxWidths.at(col) = columns.at(col).length();
            if (maxWidths.at(col) < cellText.length()) {
                maxWidths.at(col) = cellText.length();
            }
        }
    }

    printSeparator(maxWidths, Separator::TOP, false);

    // Print column values
    for (int col = 0; col < columns.size(); col++) {
        std::string cellText = columns.at(col);
        int len = cellText.length();
        std::string paddedText = cellText + space * (maxWidths.at(col) - len);
        std::cout << style_line_vertical << space * padding << paddedText << space * padding;
        std::cout << (col == columns.size() - 1 ? style_line_vertical + "\n" : "");
    }

    printSeparator(maxWidths, Separator::MIDDLE, false);

    // Print cell values
    for (int row = 0; row < rows.size(); row++) {
        for (int col = 0; col < columns.size(); col++) {
            std::string cellText = rows.at(row).getEntry().at(col);
            std::string paddedText = cellText + space * (maxWidths.at(col) - cellText.length());
            std::cout << style_line_vertical << space * padding << paddedText
                      << space * padding;
        }
        std::cout << style_line_vertical << std::endl;
        if (row == rows.size() - 1)
            printSeparator(maxWidths, Separator::BOTTOM, false);
        else
            printSeparator(maxWidths, Separator::MIDDLE, true);
    }
}

void ConsoleTable::printSeparator(const std::vector<int> &maxWidths, Separator separator,
                                  bool invisibleRowLines) const {
    for (int col = 0; col < columns.size(); ++col) {

        switch (separator) {
            case Separator::TOP: {
                std::cout << (col == 0 ? style_edge_top_left : "");
                break;
            }
            case Separator::MIDDLE: {
                if (invisibleRowLines)
                    continue;
                std::cout << (col == 0 ? style_t_intersect_left : "");
                break;
            }
            case Separator::BOTTOM: {
                std::cout << (col == 0 ? style_edge_bottom_left : "");
                break;
            }
        }

        std::cout << style_line_horizontal * padding;
        std::cout << style_line_horizontal * maxWidths.at(col);
        std::cout << style_line_horizontal * padding;

        switch (separator) {
            case Separator::TOP: {
                std::cout << (col != columns.size() - 1 ? style_t_intersect_top : style_edge_top_right);
                break;
            }
            case Separator::MIDDLE: {
                std::cout << (col != columns.size() - 1 ? style_line_cross : style_t_intersect_right);
                break;
            }
            case Separator::BOTTOM: {
                std::cout << (col != columns.size() - 1 ? style_t_intersect_bottom : style_edge_bottom_right);
                break;
            }
        }

        std::cout << (col == columns.size() - 1 ? "\n" : "");

    }
}

void ConsoleTable::addRow(ConsoleTableRow item) {
    rows.push_back(item);
}

bool ConsoleTable::removeRow(int index) {
    if (index > rows.size())
        return false;
    rows.erase(rows.begin() + index);
    return true;
}

bool ConsoleTable::editRow(std::string data, int row, int col) {
    if (row > rows.size())
        return false;

    if (col > columns.size())
        return false;

    auto entry = rows.at(row);
    entry.editEntry(data, col);
    return true;
}

void ConsoleTable::setTableStyle(TableStyle style) {
    switch (style) {
        case TableStyle::BASIC: {
            style_line_horizontal = "-";
            style_line_vertical = "|";
            style_line_cross = "+";

            style_t_intersect_right = "+";
            style_t_intersect_left = "+";
            style_t_intersect_top = "+";
            style_t_intersect_bottom = "+";

            style_edge_top_left = "+";
            style_edge_top_right = "+";
            style_edge_bottom_left = "+";
            style_edge_bottom_right = "+";
            break;
        }
        case TableStyle::LINED: {
            style_line_horizontal = "━";
            style_line_vertical = "┃";
            style_line_cross = "╋";

            style_t_intersect_right = "┫";
            style_t_intersect_left = "┣";
            style_t_intersect_top = "┳";
            style_t_intersect_bottom = "┻";

            style_edge_top_left = "┏";
            style_edge_top_right = "┓";
            style_edge_bottom_left = "┗";
            style_edge_bottom_right = "┛";
            break;
        }
        case TableStyle::DOUBLE_LINE: {
            style_line_horizontal = "═";
            style_line_vertical = "║";
            style_line_cross = "╬";

            style_t_intersect_right = "╣";
            style_t_intersect_left = "╠";
            style_t_intersect_top = "╦";
            style_t_intersect_bottom = "╩";

            style_edge_top_left = "╔";
            style_edge_top_right = "╗";
            style_edge_bottom_left = "╚";
            style_edge_bottom_right = "╝";
            break;
        }
    }
}

std::string operator*(const std::string &str, std::size_t repeats) {
    std::string ret;
    ret.reserve(str.size() * repeats);
    for (; repeats; --repeats)
        ret.append(str);
    return ret;
}
