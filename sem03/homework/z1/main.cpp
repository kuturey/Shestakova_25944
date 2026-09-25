#include <iostream>
#include "temp.h"

int main() {
    int celcInt;
    std::cout << "Temperature (int): ";
    std::cin >> celcInt;

    std::cout << "original: " << original::toFahrenheit<double, int>(celcInt) << "F\n";
    std::cout << "modified: " << modified::toFahrenheit<double, int>(celcInt) << "F\n";

    double celcD;
    std::cout << "Temperature (double): ";
    std::cin >> celcD;
    std::cout << "original: " << original::toFahrenheit<int, double>(celcD) << "F\n";
    std::cout << "modified: " << modified::toFahrenheit<int, double>(celcD) << "F\n";

    return 0;
}