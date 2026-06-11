#pragma once
#include "Numerics/Core/Function.hpp"
#include <dependencies/my_dynamic_array.hpp>
#include <utility>

double NewtonMethod(const Function& f, double x0 = 1, double accuracy = 3);
double BisectionMehthod(const Function& f, double a, double b, double epsilon = 1e-8);

namespace RootFinding {
    my_dynamic_array<double> FindRoots(const Function& f);
    my_dynamic_array<std::pair<double, double>> IsolatePossibleRoots(const Function& f, double domain = 1e4, double stepSize = 1e-1);
}