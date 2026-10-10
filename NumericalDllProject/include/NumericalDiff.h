#pragma once

// Макрос для експорту/імпорту символів DLL
#ifdef NUMDIFF_EXPORTS
#define NUMDIFF_API extern "C" __declspec(dllexport)
#else
#define NUMDIFF_API extern "C" __declspec(dllimport)
#endif

// Функції чисельного диференціювання через значення в точках (безпечно для DLL меж)
NUMDIFF_API double forwardDiffValues(double fx_h, double fx, double h);
NUMDIFF_API double backwardDiffValues(double fx, double fx_sub_h, double h);
NUMDIFF_API double centralDiffValues(double fx_plus_h, double fx_sub_h, double h);
NUMDIFF_API double secondDerivValues(double fx_plus_h, double fx, double fx_sub_h, double h);