#pragma once

namespace NumericalDiff {
    // Функції чисельного диференціювання приймають:
    // 1. Вказівник на функцію, яку треба продиференціювати: double (*func)(double)
    // 2. Точку x, у якій шукаємо похідну: double x
    // 3. Крок диференціювання h: double h
    double forwardDifference(double (*func)(double), double x, double h);
    double backwardDifference(double (*func)(double), double x, double h);
    double centralDifference(double (*func)(double), double x, double h);
    double secondDerivative(double (*func)(double), double x, double h);
}