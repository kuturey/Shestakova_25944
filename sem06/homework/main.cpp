#include "TextDocument.h"
#include <iostream>

int main() {
    std::cout << "1. Default constructor\n";
    TextDocument first;
    first.print();

    std::cout << "2. Initialization constructor\n";
    TextDocument second("Hello");
    second.setContent("Hello world!");
    second.print();

    std::cout << "3. Copy constructor (new object)\n";
    TextDocument third = second;
    third.print();

    std::cout << "4. Assignment operator (existing object)\n";
    const std::string firstId = first.getId();
    first = second;
    first.print();
    std::cout << "Assignment kept original ID: "
              << (first.getId() == firstId ? "yes" : "no") << "\n\n";

    std::cout << "5. Last 10 sizes\n";
    for (int i = 0; i < 12; ++i) {
        second.setContent(std::string(static_cast<std::size_t>(i), 'x'));
    }
    second.print();
    return 0;
}
