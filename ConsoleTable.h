#ifndef CONSOLETABLE_CONSOLETABLE_H
#define CONSOLETABLE_CONSOLETABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>

typedef std::vector<std::string> Headers;
typedef std::vector<std::vector<std::string>> Rows;
typedef std::vector<std::size_t> Widths;

class ConsoleTable {
public:

    /// Initialize a new ConsoleTable
    /// \param columns Stringlist of the tables columns
    ConsoleTable(std::initializer_list<std::string> columns);


    /// Sets the distance from the text to the cell border
    /// \param n Spaces between the text and the cell border
    void setPadding(unsigned int n);


    /// Sets the style of the table, default is 0
    /// n = 0 : Basic table style
    /// n = 1 : Single lined table style
    /// n = 2 : Double lined table style
    /// \param n The table style number
    void setStyle(unsigned int n);


    /// Adds a new row to the table
    /// \param row A list of strings to add as row
    /// \return True if the value was added successfully, otherwise false
    bool addRow(std::initializer_list<std::string> row);


    /// Removes a row from the table by the row index
    /// \param index The index of the row that should be removed
    /// \return True if the row was removed successfully, otherwise false
    bool removeRow(unsigned int index);


    /// Operator of the addRow() function
    /// \param row A list of strings to add as row
    /// \return this
    ConsoleTable &operator+=(std::initializer_list<std::string> row);


    /// Operator of the removeRow() function
    /// \param rowIndex The index of the row that should be removed
    /// \return this
    ConsoleTable &operator-=(unsigned int rowIndex);


    /// Holds all header strings of the table
    Headers headers;


    /// Holds all rows of the table
    Rows rows;


    /// Holds the size of widest string of each column of the table
    Widths widths;

private:

    struct RowType {
        std::string left;
        std::string intersect;
        std::string right;
    };

    struct TableStyle {

        std::string horizontal;
        std::string vertical;
        RowType top;
        RowType middle;
        RowType bottom;
    };

    TableStyle BasicStyle = {"-", "|", {"+", "+", "+"}, {"+", "+", "+"}, {"+", "+", "+"}};
    TableStyle LineStyle = {"━", "┃", {"┏", "┳", "┓"}, {"┣", "╋", "┫"}, {"┗", "┻", "┛"}};
    TableStyle DoubleLineStyle = {"═", "║", {"╔", "╦", "╗"}, {"╠", "╬", "╣"}, {"╚", "╩", "╝"}};
    TableStyle style = BasicStyle;

    std::string space = " ";


    /// The distance between the cell text and the cell border
    unsigned int padding = 1;


    /// Returns a formatted horizontal separation line for the table
    /// \param rowType The type of the row (top, middle, bottom)
    /// \return The formatted row string
    std::string getLine(RowType rowType) const;


    /// Returns a formatted header string
    /// \param headers The Headers-object that holds the header strings
    /// \return The formatted header string
    std::string getHeaders(Headers headers) const;


    /// Returns a formmatted row string
    /// \param rows The Rows-object that holds all rows of the table
    /// \return A formatted string of all rows in the table
    std::string getRows(Rows rows) const;



    /// Writes the entire table with all its contents in the output stream
    /// This can be used to display the table using the std::cout function
    /// \param out The output stream the table should be written to
    /// \param consoleTable The ConsoleTable-object
    /// \return Output stream with the formatted table string
    friend std::ostream &operator<<(std::ostream &out, const ConsoleTable &consoleTable);

};


/// Repeats a given string n times
/// \param other The string to repeat
/// \param repeats The amount the string should be repeated
/// \return The repeated string
std::string operator*(const std::string &other, int repeats);


#endif //CONSOLETABLE_CONSOLETABLE_H