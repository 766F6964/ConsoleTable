#ifndef CONSOLETABLE_CONSOLETABLEROW_H
#define CONSOLETABLE_CONSOLETABLEROW_H

#include <string>
#include <vector>

class ConsoleTableRow {
public:

    /// Create a new ConsoleTableRow
    /// \param width How many cells does the row have
    explicit ConsoleTableRow(int width);

    /// Add a new cell to the ConsoleTableRow
    /// \param data The data of the new cell
    /// \param column The column index of the new cell
    void addEntry(std::string data, int column);

    /// Updates a cell in the ConsoleTableRow with new data
    /// \param data The new data that should be updated
    /// \param column The index of the column that should be updated
    void editEntry(std::string data, int column);

    /// Returns the ConsoleTableRow
    /// \return The vector which holds all entries of the ConsoleTableRow
    std::vector <std::string> getEntry() const&;

private:

    /// The vector which holds all entries of the ConsoleTableRow
    std::vector <std::string> row;

};


#endif //CONSOLETABLE_CONSOLETABLEROW_H
