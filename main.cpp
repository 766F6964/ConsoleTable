#include <iostream>
#include <unistd.h>
#include "ConsoleTable.h"

int main() {
    ConsoleTable ct(TableStyle::BASIC, 1);

    ct.addColumn("Country");
    ct.addColumn("Capital");
    ct.addColumn("Population");
    ct.addColumn("Area");
    ct.addColumn("Currency");

    auto row1 = new ConsoleTableRow(5);
    row1->addEntry("Germany", 0);
    row1->addEntry("Berlin", 1);
    row1->addEntry("82,800,000", 2);
    row1->addEntry("357,168 km2", 3);
    row1->addEntry("Euro", 4);
    ct.addRow(row1);

    auto row2 = new ConsoleTableRow(5);
    row2->addEntry("Australia", 0);
    row2->addEntry("Canberra", 1);
    row2->addEntry("24,877,800", 2);
    row2->addEntry("7,692,024 km2", 3);
    row2->addEntry("Australian Dollar", 4);
    ct.addRow(row2);

    auto row3 = new ConsoleTableRow(5);
    row3->addEntry("China", 0);
    row3->addEntry("Beijing", 1);
    row3->addEntry("1,403,500,365", 2);
    row3->addEntry("9,596,961 km2", 3);
    row3->addEntry("Yuan", 4);
    ct.addRow(row3);

    auto row4 = new ConsoleTableRow(5);
    row4->addEntry("Iceland", 0);
    row4->addEntry("Reykjavik", 1);
    row4->addEntry("348,580", 2);
    row4->addEntry("102,775 km2", 3);
    row4->addEntry("Icelandic Krona", 4);
    ct.addRow(row4);

    // Print all entries
    ct.printTable();

    sleep(1);

    // Remove entry
    ct.removeRow(1);
    ct.printTable();

    sleep(1);

    // Update entry
    ct.editRow("New Name :)",0, 1);
    ct.printTable();

    return 0;
}