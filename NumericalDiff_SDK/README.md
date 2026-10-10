\# Контракт бібліотеки NumericalDiff (Версія 1.0)



\## Призначення

Динамічна бібліотека для чисельного диференціювання функцій.



\## API функції

1\. `double forwardDiffValues(double fx\_h, double fx, double h)` — правобічна різниця.

2\. `double backwardDiffValues(double fx, double fx\_sub\_h, double h)` — лівобічна різниця.

3\. `double centralDiffValues(double fx\_plus\_h, double fx\_sub\_h, double h)` — центральна різниця.

4\. `double secondDerivValues(double fx\_plus\_h, double fx, double fx\_sub\_h, double h)` — друга похідна.



\## Обмеження (Edge Cases)

\- Параметр `h` не повинен дорівнювати `0.0` (у разі 0 повертається `0.0`).

