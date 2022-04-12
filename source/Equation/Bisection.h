#ifndef NUM_BISECTION_H
#define NUM_BISECTION_H

#include "Equation.h"

class Bisection : public Equation
{
public:
    bool next() override;
    void output() override;
    bool input(const expr::Postfix &post) override;

private:
    inline bool isDiffSign(double x1, double x2);

private:
    double a1, a2;
    double f1, f2;
};

#endif