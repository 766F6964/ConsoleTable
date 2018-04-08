#include <iostream>
#include "ConsoleTable.h"

int main() {

    ConsoleTable table{"Country", "Capital", "Population", "Area", "Currency"};

    table.setPadding(2);
    table.setStyle(0);

    table += {"Germany", "Berlin", "82,800,000", "357,168 km2", "Euro"};
    table += {"France", "Paris", "67,201,000", "640,679 km2 ", "Euro"};
    table += {"Australia", "Canberra", "24,877,800", "7,692,024 km2", "Australian Dollar"};
    table += {"China", "Beijing", "1,403,500,365", "9,596,961 km2", "Yuan"};
    table += {"Iceland", "Reykjavik", "348,580", "102,775 km2", "Icelandic Krona"};

    std::cout << table;

    return 0;
}