#include <stdio.h>
#include "Differentiation.hpp"
#include "Integration.hpp"

int main() {
	Function f([](double x) { return x * x; });

	double calka = Integration::SimpsonIntegral(f, 0, 3, 1000);
	double pochodna = Differentiation::FourPointDerivative(f, 2, 0.01f);

	printf("calka to : %f \npochodna to: %f", calka, pochodna);
	return 0;
}