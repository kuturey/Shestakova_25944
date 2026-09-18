#include <iostream>
#include "temp.h"

int main() {
    int celc;
    std::cout << "Temperature: ";
    std::cin >> celc;

    std::cout << "To Fahrenheit: " << toFahrenheit(celc) << "F\n";

    std::cout << "To Fahrenheit (random): " << toFahrenheitRandom(celc) << "F\n";

    return 0;
}