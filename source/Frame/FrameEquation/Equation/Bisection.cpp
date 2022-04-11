#include "Bisection.h"

bool Bisection::next()
{
    if (a1 < a2)
    {
        double mid = 0;
        if (expr::getResult(mPost, f1, a1) && expr::getResult(mPost, f2, a2) && expr::getResult(mPost, mid, (a1 + a2) / 2))
        {
            if (isDiffSign(f1, a1))
                a2 = mid;
            else if (isEqual(f1, a1))
                return true;
            else
                a1 = mid;
        }
    }
    return false;
}

void Bisection::update()
{
}

void Bisection::input(expr::Postfix &&post)
{
}

inline bool Bisection::isDiffSign(double x1, double x2)
{
    return x1 < 0 && x2 > 0 || x1 > 0 && x2 < 0;
}
