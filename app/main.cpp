#include <stdio.h>
#include <Numerics/Calculus/Differentiation.hpp>
#include <Numerics/Calculus/Integration.hpp>
#include <Numerics/Calculus/RootFinding.hpp>

int main() {
	Function f([](double x) { return x * x - 2.0; });

	double calka = Integration::SimpsonIntegral(f, 0, 3, 1000);
	double pochodna = Differentiation::FourPointDerivative(f, 2, 0.01f);
	double pierwiastek2 = RootFinding::BisectionMehthod(f, 0.001, 0,2);
	double pierwiastek = RootFinding::NewtonMethod(f);

	printf("calka to : %f \npochodna to: %f\npierwiastek to: %f i %f", calka, pochodna, pierwiastek,pierwiastek2);
	return 0;
}