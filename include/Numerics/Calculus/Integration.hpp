#pragma once
#include "Numerics/Core/Function.hpp"

namespace Integration {
    double SimpsonIntegral(const Function& f, double a, double b, int accuracy);
    double AdaptiveSimpsonIntegral(const Function& f, double, double b, double epsilon = 0.01f, int depth = 0);
}