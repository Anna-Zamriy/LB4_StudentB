#include <iostream>
#include <cmath>
#include "NumericalDiff.h"

// Тестова функція: f(x) = x^3
// Її аналітична перша похідна: f'(x) = 3*x^2. У точці x = 2: f'(2) = 12
// Аналітична друга похідна: f''(x) = 6*x. У точці x = 2: f''(2) = 12
double sampleFunction(double x) {
    return x * x * x;
}

int main() {
    double x = 2.0;
    double h = 0.0001; // Маленький крок для високої точності

    std::cout << "=== TESTING STATIC NUMERICAL DIFF LIBRARY ===\n";
    std::cout << "Function: f(x) = x^3 at x = 2.0\n";

    std::cout << "Forward Diff: " << NumericalDiff::forwardDifference(sampleFunction, x, h) << "\n";
    std::cout << "Backward Diff: " << NumericalDiff::backwardDifference(sampleFunction, x, h) << "\n";
    std::cout << "Central Diff: " << NumericalDiff::centralDifference(sampleFunction, x, h) << "\n";
    std::cout << "Second Deriv: " << NumericalDiff::secondDerivative(sampleFunction, x, h) << "\n";

    return 0;
}