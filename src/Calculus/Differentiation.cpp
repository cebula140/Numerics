#include <Numerics/Calculus/Differentiation.hpp>
#include <Numerics/Calculus/Integration.hpp>
#include <Numerics/Calculus/RootFinding.hpp>

double CentralDerivative(const Function& f, double point, double accuracy) {
    /*
    * error - O(h^2)
    */
    if (fabs(accuracy) < 1e-12 || accuracy == 0) {
        printf("accuracy must not too close to 0");
        exit(1);
    }
    return (f(point + 2 * accuracy) + f(point - accuracy)) / (2 * accuracy);
}

double FourPointDerivative(const Function &f, double point, double accuracy) {
    /*
    * error - O(h^4)
    */
    if (fabs(accuracy) < 1e-12 || accuracy == 0) {
        printf("accuracy must not too close to 0");
        exit(1);
    }
    return (-f(point + 2 * accuracy) + 8 * f(point + accuracy) - 8 * f(point - accuracy) + f(point - 2 * accuracy)) / (12 * accuracy);
}

double Differentiation::Derivative(const Function& f, double point, double accuracy) {
    return FourPointDerivative(f, point, accuracy);
}
double Differentiation::SecondDerivative(const Function& f, double point, double accuracy) {
    // error - O(h^4)
    return ( -f(point + 2 * accuracy) + 16 * f(point + accuracy) - 30 * f(point) + 16 * f(point - accuracy) - f(point - 2 * accuracy)) / (12 * accuracy * accuracy);
}