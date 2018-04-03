#ifndef CONSOLETABLE_CONSOLETABLE_H
#define CONSOLETABLE_CONSOLETABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include "ConsoleTableRow.h"
#include "ConsoleTableUtils.h"

enum class TableStyle {
    BASIC,
    LINED,
    DOUBLE_LINE,
};

enum class Seperator {
    TOP,
    MIDDLE,
    BOTTOM
};

class ConsoleTable {
public:

    ConsoleTable(TableStyle style);

    void setPadding(unsigned int width);

    void addColumn(std::string name);

    void addRow(ConsoleTableRow *item);

    bool removeRow(int index);

    bool editRow(std::string data, int row, int col);

    void printTable();

private:

    unsigned int padding = 1;

    std::vector<std::string> columns;
    std::vector<ConsoleTableRow*> entries;
    ConsoleTableUtils *utils;

    // Table Style variables
    std::string style_line_horizontal;
    std::string style_line_vertical;
    std::string style_line_cross;
    std::string style_t_intersect_right;
    std::string style_t_intersect_left;
    std::string style_t_intersect_top;
    std::string style_t_intersect_bottom;
    std::string style_edge_topleft;
    std::string style_edge_topright;
    std::string style_edge_buttomleft;
    std::string style_edge_buttomright;

    void printHorizontalSeperator(const std::vector<int> &maxWidths, Seperator seperator,
                                  bool invisibileRowLines) const;

    void setTableStyle(TableStyle style);

};


#endif //CONSOLETABLE_CONSOLETABLE_H
