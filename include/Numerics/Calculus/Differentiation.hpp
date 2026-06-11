#pragma once
#include "Numerics/Core/Function.hpp"
double CentralDerivative(const Function& f, double point, double accuracy = 1e-8);
double FourPointDerivative(const Function& f, double point, double accuracy = 1e-8);

namespace Differentiation {

    double Derivative(const Function& f, double point, double accuracy = 1e-8); 
    double SecondDerivative(const Function& f, double point, double accuracy = 1e3);
}