#include <Numerics/Calculus/Differentiation.hpp>
#include <Numerics/Calculus/Integration.hpp>
#include <Numerics/Calculus/RootFinding.hpp>
#include <cstdlib>
#include <cstdio>


double Integration::SimpsonIntegral(const Function &f, double a, double b, int accuracy) {
    /*
    * accuracy - the higher the better
    * use for 'easy' fs
    */
    if (a == b) return 0;
    if (accuracy < 0) {
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