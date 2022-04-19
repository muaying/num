#ifndef NUM_BISECTION_H
#define NUM_BISECTION_H

#include "Equation.h"

class Bisection : public Equation
{
public:
	using Equation::Equation;
    bool next() override;
    void output() override;
    bool input(const expr::Postfix &post) override;

private:
    inline bool isDiffSign(double x1, double x2)
    {
	    return x1 < 0 && x2 > 0 || x1 > 0 && x2 < 0;
    }
private:
    double a1, a2;
};

#endif