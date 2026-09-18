#include <iostream>
#include "temp.h"

int main() {
    int celc;
    std::cout << "Temperature (int): ";
    std::cin >> celc;

    std::cout << "To Fahrenheit: " << original::toFahrenheit(celc) << "F\n";
    std::cout << "To Fahrenheit (random): " << modified::toFahrenheit(celc) << "F\n";


    double celcD;
    std::cout << "Temperature (double): ";
    std::cin >> celcD;

    std::cout << "To Fahrenheit: " << original::toFahrenheit(celcD) << "F\n";
    std::cout << "To Fahrenheit (random): " << modified::toFahrenheit(celcD) << "F\n";


    return 0;
}