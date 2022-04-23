//
// Created by 24100 on 2022/4/12.
//

#include "Newton.h"
#include "FrameEquation/FrameFunc.h"
bool Newton::next()
{
	double f,df;
	if(expr::getResult(mPost,f,x0)&&expr::getResult(derivative,df,x0))
	{
		double x=x0-f/df;
		if(isEqual(x0,x))
			return true;
		x0=x;
	}
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
		qDebug() << derivative;
		x0=frame->edt_x0->text().toDouble();
		return true;
	}
	return false;
}
