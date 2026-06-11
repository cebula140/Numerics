#include <iostream>
#include <Numerics.hpp>
#include <cmath>

int main() {

    std::cout << "TEST 1: x - 3\n";
    {
        auto f = [](double x) { return x - 3.0; };
        auto r = RootFinding::FindRoots(f);

        std::cout << "Expected: [3]\nGot: ";
        r.print();
        std::cout << "\n\n";
    }

    std::cout << "TEST 2: (x-1)(x+2)\n";
    {
        auto f = [](double x) { return (x - 1.0) * (x + 2.0); };
        auto r = RootFinding::FindRoots(f);

        std::cout << "Expected: [-2, 1]\nGot: ";
        r.print();
        std::cout << "\n\n";
    }

    std::cout << "TEST 3: (x-2)^2\n";
    {
        auto f = [](double x) { return (x - 2.0) * (x - 2.0); };
        auto r = RootFinding::FindRoots(f);

        std::cout << "Expected: [2]\nGot: ";
        r.print();
        std::cout << "\n\n";
    }

    std::cout << "TEST 4: (x-1)(x+2)(x-3)(x+3)\n";
    {
        auto f = [](double x) {
            return (x - 1) * (x + 2) * (x - 3) * (x + 3);
            };

        auto r = RootFinding::FindRoots(f);

        std::cout << "Expected: [-3, -2, 1, 3]\nGot: ";
        r.print();
        std::cout << "\n\n";
    }

    std::cout << "TEST 5: x^2 + 1 (no roots)\n";
    {
        auto f = [](double x) { return x * x + 1.0; };
        auto r = RootFinding::FindRoots(f);

        std::cout << "Expected: []\nGot: ";
        r.print();
        std::cout << "\n\n";
    }

    return 0;
}