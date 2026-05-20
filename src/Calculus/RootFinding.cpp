#include "RootFinding.hpp"
#include "Differentiation.hpp"


double FindRoots(const Function& f, double accuracy = 4)
{
	int x0 = 1;
	int xi = x0 - (f(x0)/ Differentiation::FourPointDerivative(f, x0, 0.01f));
	for (int i = 1; i < accuracy; i++) 
	{
		xi = xi - (f(xi) / Differentiation::FourPointDerivative(f, xi, 0.01f));
	}

	return xi;
}
