#include <stdio.h>
#include <Numerics/Calculus/Differentiation.hpp>
#include <Numerics/Calculus/Integration.hpp>
#include <Numerics/Calculus/RootFinding.hpp>
#include <cmath>
#define M_PI 3.14159265358979323846

int main() {
	Function f([](double x) { return 1/sqrt(x); });

	double calka = Integration::AdaptiveSimpsonIntegral(f, 0, 1, 0.1f);

	printf("calka to : %f", calka);
	return 0;
}