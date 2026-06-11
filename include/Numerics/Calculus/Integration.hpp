#pragma once
#include "Numerics/Core/Function.hpp"
double SimpsonIntegral(const Function& f, double a, double b, int accuracy);
double AdaptiveSimpsonIntegral(const Function& f, double, double b, double epsilon = 1e-3, int depth = 0);
namespace Integration {
	double Integrate(const Function& f, double a, double b, double epsilon = 1e-3, int depth = 0);
}