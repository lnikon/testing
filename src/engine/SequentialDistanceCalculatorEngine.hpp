#pragma once

#include "IDistanceCalculatorEngine.hpp"

template <typename ValueType>
class SequentialDistanceCalculatorEngine : public IDistanceCalculatorEngine<ValueType>
{
public:
    std::vector<std::vector<ValueType>> calculate() /* noexcept */ const override
    {
        return std::vector<std::vector<ValueType>>{};
    }

    DistanceCalculatorEngineType type() /* noexcept */ const override
    {
        return DistanceCalculatorEngineType::Sequential;
    }
};
