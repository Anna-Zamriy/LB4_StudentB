#include <iostream>
#include "NumericalIntegration.h"

// Тестова функція f(x) = x * x (інтеграл від 0 до 1 дорівнює 1/3 ≈ 0.333333)
double sampleFunction(double x) {
    return x * x;
}

int main() {
    std::cout << "=== PARTNER SDK: IMPLICIT LINKING (ALL FUNCTIONS) ===\n";

    double a = 0.0;
    double b = 1.0;
    int coarseN = 100;
    int fineN = 1000;

    // 1. Виклик усіх основних методів інтегрування
    double rectRes = rectangle(sampleFunction, a, b, fineN);
    double trapRes = trapezoid(sampleFunction, a, b, fineN);
    double simpRes = simpson(sampleFunction, a, b, fineN);

    std::cout << "Rectangle Method (n=" << fineN << "): " << rectRes << "\n";
    std::cout << "Trapezoid Method (n=" << fineN << "): " << trapRes << "\n";
    std::cout << "Simpson Method (n=" << fineN << "):   " << simpRes << "\n";

    // 2. Виклик функції оцінки похибки (integrationError)
    double coarseTrap = trapezoid(sampleFunction, a, b, coarseN);
    double errorEst = integrationError(trapRes, coarseTrap);
    std::cout << "Integration Error Estimation:      " << errorEst << "\n";

    // 3. Перевірка граничних випадків (Edge Cases) для звіту:
    std::cout << "\n--- Edge Cases Testing ---\n";
    double edgeN0 = trapezoid(sampleFunction, a, b, 0);
    std::cout << "Test (n = 0):     " << edgeN0 << " (Expected 0.0, safe)\n";

    double edgeNull = trapezoid(nullptr, a, b, fineN);
    std::cout << "Test (f = nullptr): " << edgeNull << " (Expected 0.0, safe)\n";

    return 0;
}