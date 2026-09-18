#pragma once

#include <random>

namespace original {
    template <typename ResultType, typename InputType>
    ResultType toFahrenheit(const InputType& celc) {
        return static_cast<ResultType>(celc * 9.0 / 5.0 + 32);
    }
}

namespace modified {
    template <typename ResultType, typename InputType>
    ResultType toFahrenheit(InputType& celc) {
        double result = celc * 9.0 / 5.0 + 32;

        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> coin(0, 1);
        std::uniform_int_distribution<int> add(-10, 10);

        if (coin(gen) == 1) {
            result += add(gen);
        }

        celc = static_cast<InputType>(result);
        return static_cast<ResultType>(result);
    }
}