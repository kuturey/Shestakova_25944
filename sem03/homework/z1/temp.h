#pragma once

namespace original {
    template <typename ResultType, typename InputType>
    ResultType toFahrenheit(const InputType& celc);
}

namespace modified {
    template <typename ResultType, typename InputType>
    ResultType toFahrenheit(InputType& celc);
}

#include "temp.tpp"