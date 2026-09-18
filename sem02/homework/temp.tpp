#pragma once

#include <random>

namespace original {
    template <typename T>
    T toFahrenheit(const T& celc) {
        return static_cast<T>(celc * 9.0 / 5.0 + 32);
    }
}

namespace modified {
    template <typename T>
    T toFahrenheit(T& celc) {
        double result = celc * 9.0 / 5.0 + 32;

        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> coin(0, 1);
        std::uniform_int_distribution<int> add(-10, 10);

        if (coin(gen) == 1) {
            result += add(gen);
        }

        celc = static_cast<T>(result);
        return static_cast<T>(result);
    }
}