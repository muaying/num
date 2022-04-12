//
// Created by 24100 on 2022/4/12.
//

#include "Newton.h"
#include "FrameEquation/FrameFunc.h"
bool Newton::next()
{

	return false;
}

void Newton::output()
{
	frame->wdgPaint->addXLine(x0);
	frame->pEdit_out->appendPlainText(QString("Xi = %1").arg(x0));
}

bool Newton::input(const expr::Postfix &post)
{
	Equation::input(post);
	if(expr::getPostfix(frame->edt_itExpr->text(),derivative))
	{
		x0=frame->edt_x0->text().toDouble();
		return true;
	}
	return false;
}
