#pragma once

#ifdef INTEGRATIONLIB_EXPORTS
#define INTEGRATION_API extern "C" __declspec(dllexport)
#else
#define INTEGRATION_API extern "C" __declspec(dllimport)
#endif

typedef double (*MathFunc)(double);

INTEGRATION_API double rectangle(MathFunc f, double a, double b, int n);

INTEGRATION_API double trapezoid(MathFunc f, double a, double b, int n);

INTEGRATION_API double simpson(MathFunc f, double a, double b, int n);

INTEGRATION_API double integrationError(double fineResult, double coarseResult);