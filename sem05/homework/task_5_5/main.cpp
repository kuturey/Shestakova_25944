#include <iostream>
#include "temp.h"

int main()
{
    int intValue = 10;
    double doubleValue = 10.5;

    int intModified = intValue;
    double doubleModified = doubleValue;

    std::cout << "int original: "
              << original::toFahrenheit(intValue)
              << "F\n";

    std::cout << "int modified: "
              << modified::toFahrenheit(intModified)
              << "F\n";

    std::cout << "double original: "
              << original::toFahrenheit(doubleValue)
              << "F\n";

    std::cout << "double modified: "
              << modified::toFahrenheit(doubleModified)
              << "F\n";

    return 0;
}
