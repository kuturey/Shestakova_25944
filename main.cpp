#include<iostream>
#include "func.h"

int main() {
	std::cout << "Input a: ";
	int a, b;
	std::cin >> a;
	std::cout << "Input b: ";
	std::cin >> b;

	std::cout << "f(" << a << ", " << b << ") = " << f(a, b) << std::endl;
}