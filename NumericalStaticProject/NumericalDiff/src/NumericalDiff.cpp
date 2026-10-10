#include "NumericalDiff.h"

namespace NumericalDiff {
    // 1. Правобічна різниця: f'(x) ≈ (f(x+h) - f(x)) / h
    double forwardDifference(double (*func)(double), double x, double h) {
        if (h == 0.0) return 0.0; // Захист від Edge Case (ділення на нуль)
        return (func(x + h) - func(x)) / h;
    }

    // 2. Лівобічна різниця: f'(x) ≈ (f(x) - f(x-h)) / h
    double backwardDifference(double (*func)(double), double x, double h) {
        if (h == 0.0) return 0.0;
        return (func(x) - func(x - h)) / h;
    }

    // 3. Центральна різниця (має вищу точність): f'(x) ≈ (f(x+h) - f(x-h)) / (2*h)
    double centralDifference(double (*func)(double), double x, double h) {
        if (h == 0.0) return 0.0;
        return (func(x + h) - func(x - h)) / (2.0 * h);
    }

    // 4. Друга похідна: f''(x) ≈ (f(x+h) - 2*f(x) + f(x-h)) / (h^2)
    double secondDerivative(double (*func)(double), double x, double h) {
        if (h == 0.0) return 0.0;
        return (func(x + h) - 2.0 * func(x) + func(x - h)) / (h * h);
    }
}