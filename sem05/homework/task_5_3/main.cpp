#include <iostream>
#include "temp.h"

int main()
{
    int celc;

    std::cout << "Temperature: ";
    std::cin >> celc;

    int valueForModified = celc;

    std::cout << "Original: "
              << original::toFahrenheit(celc)
              << "F\n";

    std::cout << "Modified: "
              << modified::toFahrenheit(valueForModified)
              << "F\n";

    return 0;
}
