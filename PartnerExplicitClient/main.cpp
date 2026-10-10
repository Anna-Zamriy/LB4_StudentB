#include <iostream>
#include <windows.h>

// Оголошуємо сигнатури для функцій партнера
typedef double(*MathFuncType)(double);
typedef double(*IntegrationFunc)(MathFuncType, double, double, int);
typedef double(*ErrorFunc)(double, double);

double sampleFunction(double x) {
    return x * x;
}

int main() {
    std::cout << "=== PARTNER SDK: EXPLICIT LINKING (ALL FUNCTIONS) ===\n";

    // 1. Явно завантажуємо DLL
    HMODULE hLib = LoadLibrary(TEXT("IntegrationLib.dll"));
    if (!hLib) {
        std::cerr << "ERROR: Could not load IntegrationLib.dll!\n";
        return 1;
    }
    std::cout << "[OK] DLL successfully loaded via LoadLibrary()!\n";

    // 2. Отримуємо вказівники на всі функції за їхніми назвами з README.md
    auto rectFunc = (IntegrationFunc)GetProcAddress(hLib, "rectangle");
    auto trapFunc = (IntegrationFunc)GetProcAddress(hLib, "trapezoid");
    auto simpFunc = (IntegrationFunc)GetProcAddress(hLib, "simpson");
    auto errFunc = (ErrorFunc)GetProcAddress(hLib, "integrationError");

    if (rectFunc && trapFunc && simpFunc && errFunc) {
        double a = 0.0;
        double b = 1.0;
        int coarseN = 100;
        int fineN = 1000;

        double rRes = rectFunc(sampleFunction, a, b, fineN);
        double tRes = trapFunc(sampleFunction, a, b, fineN);
        double sRes = simpFunc(sampleFunction, a, b, fineN);

        std::cout << "Rectangle Result: " << rRes << "\n";
        std::cout << "Trapezoid Result: " << tRes << "\n";
        std::cout << "Simpson Result:   " << sRes << "\n";

        // Перевірка функції похибки
        double coarseT = trapFunc(sampleFunction, a, b, coarseN);
        double error = errFunc(tRes, coarseT);
        std::cout << "Error Estimation: " << error << "\n";
    }
    else {
        std::cerr << "ERROR: Could not find one or more functions in DLL!\n";
    }

    // 3. Вивантажуємо бібліотеку
    FreeLibrary(hLib);
    std::cout << "[OK] DLL successfully unloaded via FreeLibrary().\n";

    return 0;
}