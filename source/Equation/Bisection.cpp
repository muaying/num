#include "Bisection.h"
#include "FrameEquation/FrameFunc.h"
#include <QString>
bool Bisection::next()
{
    double mid = (a1 + a2) / 2;
    double f3 = 0;
    if (expr::getResult(mPost, f1, a1) && expr::getResult(mPost, f2, a2) && expr::getResult(mPost, f3, mid))
    {
        if (isDiffSign(f1, f3))
            a2 = mid;
        else if (isEqual(f1, f3))
            return true;
        else
            a1 = mid;
    }
    return false;
}

void Bisection::output()
{
    frame->pEdit_out->appendPlainText(QString("a1 : %1 a2 : %2").arg(a1).arg(a2));
    frame->wdgPaint->addXLine(a1);
    frame->wdgPaint->addXLine(a2);
}

bool Bisection::input(const expr::Postfix &post)
{

    Equation::input(post);
    a1 = frame->edt_a1->text().toDouble();
    a2 = frame->edt_a2->text().toDouble();

    return a1 <= a2;
}

inline bool Bisection::isDiffSign(double x1, double x2)
{
    return x1 < 0 && x2 > 0 || x1 > 0 && x2 < 0;
}
