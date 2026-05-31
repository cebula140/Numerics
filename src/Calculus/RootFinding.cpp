#include <Numerics/Calculus/Differentiation.hpp>
#include <Numerics/Calculus/Integration.hpp>
#include <Numerics/Calculus/RootFinding.hpp>


double RootFinding::NewtonMethod(const Function& f, double accuracy)
{
	// start with a fixed initial guess x=1
	double xi = 1 - (f(1)/ Differentiation::FourPointDerivative(f, 1, 0.01f));
	for (int i = 1; i < accuracy; i++) 
	{
		xi = xi - (f(xi) / Differentiation::FourPointDerivative(f, xi, 0.01f));
	}

	return xi;
}

double RootFinding::BisectionMehthod(const Function& f, double epsilon, double a, double b) {
	// no sign change -> no root in [a,b]
	if (f(a) * f(b) >= 0) return -676767;

	double xi = (a + b) / 2;
	while (std::abs(b - a) / 2 > epsilon) {
		xi = (a + b) / 2;
		if (std::abs(f(xi)) < 1e-12) return xi;

		if (f(xi) * f(a) < 0) b = xi;
		else a = xi;
		
	}
	return xi;
}