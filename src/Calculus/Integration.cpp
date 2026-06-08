#include <Numerics/Calculus/Differentiation.hpp>
#include <Numerics/Calculus/Integration.hpp>
#include <Numerics/Calculus/RootFinding.hpp>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <cmath>
#include <dependencies/my_map.hpp>
double Integration::SimpsonIntegral(const Function &f, double a, double b, int accuracy) {
    /*
    * accuracy - the higher the better
    * use for 'easy' fs
    */
    if (a == b) return 0;
    if (accuracy <= 0) {
        printf("accuracy must be greater than 0");
        exit(1);
    }
    if (accuracy % 2 != 0) accuracy++;

    double sum = f(a) + f(b);
    double h = (b - a) / accuracy;
    double xi;

    for (int i = 1; i < accuracy; i++) {
        xi = a + i * h;

        if (i % 2 == 0) sum += 2 * f(xi);
        else sum += 4 * f(xi);

    }
    if (a < b) return (h / 3) * sum;
    else return -1 * ((h / 3) * sum);

}


// turn interval [a,b] into a string key for caching
std::string make_key(double a, double b)
{
    auto r = [](double x)
        {
            return std::to_string((long long)(x * 1e9));
        };

    return r(a) + "|" + r(b);
}

// memoization cache shared across recursive calls
my_map<double> cache;

double Integration::AdaptiveSimpsonIntegral(const Function& f, double a, double b, double epsilon, int depth) {
    const int accuracy = 16;

    // stop recursion at 50 levels deep, fall back to plain Simpson
    if (depth > 50)
        return SimpsonIntegral(f, a, b, accuracy);

    if (b - a < 1e-12)
    {
        double S = SimpsonIntegral(f, a, b, accuracy);
        cache.insert_slot(make_key(a, b), S);
        return S;
    }

    double m = (a + b) / 2;
    std::string key = make_key(a, b);

    double* cached = cache.find(key);
    if (cached != nullptr)
        return *cached;

    double S = SimpsonIntegral(f, a, b, accuracy);
    double S1 = SimpsonIntegral(f, a, m, accuracy);
    double S2 = SimpsonIntegral(f, m, b, accuracy);

    if (!std::isfinite(S) || !std::isfinite(S1) || !std::isfinite(S2))
        return S;

    // standard adaptive Simpson error estimate
    double error = std::abs(S1 + S2 - S) / 15.0;

    double result;

    if (error < epsilon)
    {
        result = S1 + S2;
        cache.insert_slot(key, result);
        return result;
    }

    result = Integration::AdaptiveSimpsonIntegral(f, a, m, epsilon, depth + 1) + Integration::AdaptiveSimpsonIntegral(f, m, b, epsilon, depth + 1);

    cache.insert_slot(key, result);

    return result;
}