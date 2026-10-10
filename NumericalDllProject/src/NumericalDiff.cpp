#include "NumericalDiff.h"

extern "C" {
    double forwardDiffValues(double fx_h, double fx, double h) {
        if (h == 0.0) return 0.0; // Захист від Edge Case (ділення на нуль)
        return (fx_h - fx) / h;
    }

    double backwardDiffValues(double fx, double fx_sub_h, double h) {
        if (h == 0.0) return 0.0;
        return (fx - fx_sub_h) / h;
    }

    double centralDiffValues(double fx_plus_h, double fx_sub_h, double h) {
        if (h == 0.0) return 0.0;
        return (fx_plus_h - fx_sub_h) / (2.0 * h);
    }

    double secondDerivValues(double fx_plus_h, double fx, double fx_sub_h, double h) {
        if (h == 0.0) return 0.0;
        return (fx_plus_h - 2.0 * fx + fx_sub_h) / (h * h);
    }
}