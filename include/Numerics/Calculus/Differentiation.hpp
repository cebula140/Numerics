#pragma once
#include "Numerics/Core/Function.hpp"

namespace Differentiation {
    //double CentralDerivative(const Function &f, double point, double accuracy = 1e-8);
    //double FourPointDerivative(const Function &f, double point, double accuracy = 1e-8);
    double Derivative(const Function& f, double point, double accuracy = 1e-8);
    double SecondDerivative(const Function& f, double point, double accuracy = 1e-8);
}