#pragma once

namespace original {
    template <typename T>
    T toFahrenheit(const T& celc);
}

namespace modified {
    template <typename T>
    T toFahrenheit(T& celc);
}

#include "temp.tpp"