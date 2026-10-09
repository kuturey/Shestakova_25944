#include "temp.h"
#include <random>

namespace original
{
    int toFahrenheit(int celc)
    {
        return celc * 9 / 5 + 32;
    }
}

namespace modified
{
    int toFahrenheit(int& celc)
    {
        int result = celc * 9 / 5 + 32;

        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> coin(0, 1);
        std::uniform_int_distribution<int> add(-10, 10);

        if (coin(gen) == 1)
        {
            result += add(gen);
        }

        celc = result;
        return result;
    }
}
