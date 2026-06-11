#include <utility>
#include <dependencies/my_dynamic_array.hpp>
#include <Numerics.hpp>

double NewtonMethod(const Function& f, double x0, double accuracy)
{
    double xi = x0 - (f(x0) / Differentiation::Derivative(f, x0, 0.01));
    for (int i = 1; i < accuracy; i++) {
        xi = xi - (f(xi) / Differentiation::Derivative(f, xi, 0.01));
    }
    return xi;
}

double BisectionMehthod(const Function& f, double epsilon, double a, double b) {
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

my_dynamic_array<std::pair<double, double>> RootFinding::IsolatePossibleRoots(const Function& f, double domain, double stepSize) {
    double domainStart = -domain;
    double domainEnd = domain;
    double prevX = domainStart;
    double prevY = f(prevX);
    my_dynamic_array<std::pair<double, double>> intervals;
    std::pair<double, double> currInterval;
    for (double currX = domainStart + stepSize; currX <= domainEnd; currX += stepSize) {
        double currY = f(currX);

        if (prevY * currY < 0.0) {
            currInterval = {prevX, currX};
            intervals.insert_back(currInterval);
        }

        if (std::abs(prevY) < 1e-16) {
            currInterval = {prevX, prevX};
            intervals.insert_back(currInterval);
        }

        prevX = currX;
        prevY = currY;
    }
    return intervals;
}

my_dynamic_array<double> RootFinding::FindRoots(const Function& f) {
    auto intervals = IsolatePossibleRoots(f, 1e3, 1e-1);
    // add reapeted polynomials support
    // and is kinda slow
    my_dynamic_array<double> roots;
    for (size_t i = 0; i < intervals.get_size(); i++) {
        roots.insert_back(NewtonMethod(f, (intervals[i].first + intervals[i].second) / 2));
    }
    return roots;
}
