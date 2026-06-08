#include <iostream>
#include <Numerics.hpp>
#include <cmath>
#define M_PI 3.14159265358979323846

int main() {

    std::cout << "TEST 1: inicjalizacja 2x2\n";
    Matrix<int, 2, 2> A;

    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    std::cout << A(0, 0) << " " << A(0, 1) << "\n";
    std::cout << A(1, 0) << " " << A(1, 1) << "\n\n";


    std::cout << "TEST 2: dodawanie\n";
    Matrix<int, 2, 2> B;

    B(0, 0) = 5;
    B(0, 1) = 6;
    B(1, 0) = 7;
    B(1, 1) = 8;

    Matrix<int, 2, 2> C = A + B;

    std::cout << C(0, 0) << " " << C(0, 1) << "\n";
    std::cout << C(1, 0) << " " << C(1, 1) << "\n\n";


    std::cout << "TEST 3: odejmowanie\n";
    Matrix<int, 2, 2> D = B - A;

    std::cout << D(0, 0) << " " << D(0, 1) << "\n";
    std::cout << D(1, 0) << " " << D(1, 1) << "\n\n";


    std::cout << "TEST 4: skalowanie\n";
    Matrix<int, 2, 2> E = A * 3;

    std::cout << E(0, 0) << " " << E(0, 1) << "\n";
    std::cout << E(1, 0) << " " << E(1, 1) << "\n\n";


    std::cout << "TEST 5: mnozenie macierzy\n";
    Matrix<int, 2, 2> F = A * B;

    std::cout << F(0, 0) << " " << F(0, 1) << "\n";
    std::cout << F(1, 0) << " " << F(1, 1) << "\n\n";


    std::cout << "TEST 6: 2x3 * 3x2\n";
    Matrix<int, 2, 3> X;
    Matrix<int, 3, 2> Y;

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            X(i, j) = val++;

    val = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            Y(i, j) = val++;

    Matrix<int, 2, 2> Z = X * Y;

    std::cout << Z(0, 0) << " " << Z(0, 1) << "\n";
    std::cout << Z(1, 0) << " " << Z(1, 1) << "\n";

    return 0;
}