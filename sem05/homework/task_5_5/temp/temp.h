#pragma once

#include <random>

template <typename T>
T randomAdd(T value)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> coin(0, 1);
    std::uniform_int_distribution<int> add(-10, 10);

    if (coin(gen) == 1)
    {
        value += static_cast<T>(add(gen));
    }

    return value;
}

namespace original
{
    template <typename T>
    T toFahrenheit(const T& celc)
    {
        return static_cast<T>(celc * 9.0 / 5.0 + 32.0);
    }
}

namespace modified
{
    template <typename T>
    T toFahrenheit(T& celc)
    {
        T result = static_cast<T>(celc * 9.0 / 5.0 + 32.0);
        result = randomAdd(result);
        celc = result;
        return result;
    }
}
