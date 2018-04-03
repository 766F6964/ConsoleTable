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

enum class Separator {
    TOP,
    MIDDLE,
    BOTTOM
};

typedef std::vector<std::string> Columns;
typedef std::vector<ConsoleTableRow> Rows;


class ConsoleTable {
public:

    /// Create a new ConsoleTable
    /// \param style The design of the console table
    /// \param padding Additional space between the text and the cell border
    explicit ConsoleTable(TableStyle style, unsigned int padding);

    /// Add a new column to the ConsoleTable
    /// \param name The name of the column
    void addColumn(std::string name);

    /// Add a new row with information into the ConsoleTable
    /// \param item The ConsoleTableRow which should be added
    void addRow(ConsoleTableRow item);

    /// Remove a row from the ConsoleTable at the given index
    /// \param index The index of the row which should be removed
    /// \return True if row was removed successfully, otherwise false
    bool removeRow(int index);

    /// Update the information in specific cell of a row
    /// \param data The new data that should be set
    /// \param row The index of the row which should be updated
    /// \param col The index of the column that should be updated
    /// \return True if the update was successful, otherwise false
    bool editRow(std::string data, int row, int col);

    /// Displays the table with columns and all content
    void printTable();

private:

    /// Additional space between cell border and cell text
    unsigned int padding = 1;

    /// Vector of all columns of the ConsoleTable
    Columns columns;

    /// Vector of all rows in the ConsoleTable
    Rows rows;

    // Table Style variables
    std::string style_line_horizontal;
    std::string style_line_vertical;
    std::string style_line_cross;
    std::string style_t_intersect_right;
    std::string style_t_intersect_left;
    std::string style_t_intersect_top;
    std::string style_t_intersect_bottom;
    std::string style_edge_top_left;
    std::string style_edge_top_right;
    std::string style_edge_bottom_left;
    std::string style_edge_bottom_right;

    std::string space = " ";

    /// Prints the horizontal seperator lines for the table
    /// \param maxWidths A vector that holds the maximum of all items in each column
    /// \param separator Defines what kind of seperator is used (Top, Middle, Bottom)
    /// \param invisibleRowLines If true seperator lines are only used between column headers and the first row, otherwise between every row
    void printSeparator(const std::vector<int> &maxWidths, Separator separator,
                        bool invisibleRowLines) const;

    /// Sets the design for the ConsoleTable
    /// \param style The style of the ConsoleTable (BASIC, LINED, DOUBLELINED)
    void setTableStyle(TableStyle style);



};

/// Repeats a string n times
/// \param str The string to repeat
/// \param repeats How many times should the string get repeated
/// \return The repeated string
std::string operator*(const std::string &str, std::size_t repeats);


#endif //CONSOLETABLE_CONSOLETABLE_H
