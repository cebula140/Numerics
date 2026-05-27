#pragma once
#include "Numerics/Core/Function.hpp"

namespace RootFinding {
    double NewtonMethod(const Function&, double accuracy = 4);
    double BisectionMehthod(const Function& f, double accuracy, double a, double b);
}