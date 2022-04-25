//
// Created by 24100 on 2022/4/23.
//

#include "EGGauss.h"
#include <QDebug>



void EGGauss::ready()
{
	curX=0;
}

bool EGGauss::next()
{

	if(curX==mat->rows()-1)
	{//运算到最后一行 带入计算
		VectorXd result=mat->col(curX+1);
		for(int j=curX;j>=0;--j)
		{
			double y=result(j);
			if(j!=curX)
				for(int i=curX-j;i>0;--i)
					y-= (*mat)(j,j+i)*result(j+i);
			result(j)=y/ (*mat)(j,j);
		}
		QString resStr;
		for(int i=0;i<result.size();++i)
			resStr+=QString("  [X%1: %2]  ").arg(i+1).arg(result(i));
		frame->output->appendPlainText(resStr);
		return true;
	}
	//选主元
	maxIndex=maxAbsIndexVec(mat->col(curX));
	if(maxIndex!=0)
		mat->row(maxIndex).swap(mat->row(curX));
	//消元
	double x=(*mat)(curX,curX);
	for(int i=curX+1;i<mat->rows();++i)
	{
		mat->row(i)+= mat->row(curX)*(-((*mat)(i,curX)/x));
	}
	++curX;
	return false;
}

void EGGauss::output()
{
	frame->output->appendPlainText(QString("当前处理行： %1").arg(curX));
	frame->output->appendPlainText(QString("列选主元： %1").arg(maxIndex+1));
}

EGGauss::EGGauss():curX(0)
{

}
