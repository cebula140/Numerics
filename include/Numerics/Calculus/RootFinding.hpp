#pragma once
#include "Numerics/Core/Function.hpp"
#include <dependencies/my_dynamic_array.hpp>
#include <utility>

double NewtonMethod(const Function& f, double x0, double accuracy = 3);
double BisectionMehthod(const Function& f, double epsilon, double a, double b);

namespace RootFinding {
    my_dynamic_array<double> FindRoots(const Function& f);
    my_dynamic_array<std::pair<double, double>> IsolatePossibleRoots(const Function& f, double domain, double stepSize);
}