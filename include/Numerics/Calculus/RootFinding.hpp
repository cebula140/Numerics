#pragma once
#include "Numerics/Core/Function.hpp"
#include <dependencies/my_dynamic_array.hpp>
#include <utility>

my_dynamic_array<std::pair<double, double>> IsolatePossibleRoots(const Function& f, double domain, double stepSize);

double NewtonMethod(const Function& f, double x0, double accuracy = 4);

namespace RootFinding {
    double* FindRoots(const Function& f);
    double BisectionMehthod(const Function& f, double accuracy, double a, double b);
}
