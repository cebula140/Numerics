#pragma once
#include "Numerics/Core/Function.hpp"

namespace Integration {
    double SimpsonIntegral(const Function& f, double a, double b, int accuracy);
}