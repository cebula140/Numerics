#pragma once
#include "Function.hpp"

namespace Differentiation {
    double CentralDerivative(const Function &f, double point, double accuracy);
    double FourPointDerivative(const Function &f, double point, double accuracy);
}