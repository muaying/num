#include "GeneralIterate.h"
#include "FrameEquation/FrameFunc.h"
bool GeneralIterate::next()
{
	double x1;
	if(expr::getResult(iter,x1,x0))
	{
		if(isEqual(x0,x1))
			return true;
		x0=x1;
	}
	return false;
}

void GeneralIterate::output()
{
	frame->wdgPaint->addXLine(x0);
	frame->pEdit_out->appendPlainText(QString("Xi = %1").arg(x0));
}

bool GeneralIterate::input(const expr::Postfix &post)
{
	Equation::input(post);
	if(expr::getPostfix(frame->edt_itExpr1->text(),iter))
	{
		x0=frame->edt_x0->text().toDouble();
		return true;
	}
	return false;
}
