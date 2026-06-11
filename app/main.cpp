#include <iostream>
#include <Numerics.hpp>
#include <cmath>

int main() {
    auto function = [](double x) -> double {
        return 2 * pow(x, 5)
            + -2 * pow(x, 3)
            - 7.0 * pow(x, 2)
            + 12.0 * x
            - 5.0;
        };
    auto roots = RootFinding::FindRoots(function);
    std::cout << "The roots are: ";
    roots.print();
    std::cout << '\n';

    double a = -2;
    double b = 3;
    auto integral = Integration::Integrate(function, -2, 3);
    std::cout << "The Integral over ";
    print_domain(a, b);
    std::cout << " is: " << integral;
    std::cout << '\n';

    double x = 5;
    auto derivative = Differentiation::Derivative(function, x);
    auto second_derivative = Differentiation::SecondDerivative(function, x);
    std::cout << "The derivative is: " << derivative << ", and the second derivative is: " << second_derivative;
    std::cout << '\n';
}
