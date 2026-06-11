#pragma once
#include <functional>


class Function {
private:
    std::function<double(double)> func;

public:
    Function(std::function<double(double)> function) {
        this->func = function;
    }

    template <typename F>
    Function(F f) : func(f) {}


    double operator()(double x) const {
        return func(x);
    }
};