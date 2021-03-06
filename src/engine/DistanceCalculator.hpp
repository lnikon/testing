#pragma once

#include "CPPThreadsDistanceCalculatorEngine.hpp"
#include "CSVContainer.hpp"
#include "CUDADistanceCalculatorEngine.hpp"
#include "DistanceCalculatorEngineFactory.hpp"
#include "DistanceCalculatorEngineType.hpp"
#include "IDistanceCalculatorEngine.hpp"
#include "MPIDistanceCalculatorEngine.hpp"
#include "SequentialDistanceCalculatorEngine.hpp"

#include <iostream>

template <typename ValueType>
class DistanceCalculator
{
public:
    void setDistanceCalculatorEngineType(const DistanceCalculatorEngineType type)
    {
        if (auto engine = distanceCalculatorEngineFactory<ValueType>(type); engine != nullptr)
        {
            m_engine = engine;
        }
    }

    structures::CSVContainerSPtr<ValueType>
    calculate(structures::CSVContainerSPtr<ValueType> query,
              structures::CSVContainerSPtr<ValueType> dataset)
    {
        return m_engine->calculate(query, dataset);
    }

private:
    std::shared_ptr<IDistanceCalculatorEngine<ValueType>> m_engine{nullptr};
};
