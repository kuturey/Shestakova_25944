#include "temp.h"
#include <random>

namespace {
	int toFahrenheit(int celc) {
		int result = celc * 9 / 5 + 32;
		return result;
	}
}

namespace {
	int toFahrenheit(int celc) {

		int result = celc * 9 / 5 + 32;

		// Готовим движок
		static std::random_device rd;
		static std::mt19937 gen(rd());

		// готовим систему 50/50
		std::uniform_int_distribution<int> coin(0, 1);
		std::uniform_int_distribution<int> add(-10, 10);

		if (coin(gen) == 1) {
			result += add(gen);
		}
		return result;
	}
}
