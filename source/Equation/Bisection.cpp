#include "Bisection.h"
#include "FrameEquation/FrameFunc.h"

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

void Bisection::output()
{
}

void Bisection::input(const expr::Postfix &post)
{
    Equation::input(std::move(post));
    a1 = frame->edt_a1->text().toDouble();
    a2 = frame->edt_a1->text().toDouble();
}

inline bool Bisection::isDiffSign(double x1, double x2)
{
    return x1 < 0 && x2 > 0 || x1 > 0 && x2 < 0;
}
