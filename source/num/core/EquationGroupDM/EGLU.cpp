#include "EGLU.h"

void EGLU::ready()
{
	cur=0;
}

bool EGLU::next()
{
	if(cur == mat->rows()) //带入计算
	{
		//求解 y
		VectorXd result =mat->col(cur);
		for(int i=0; i < cur; ++i)
		{
			double y=result(i);
			if(i!=0)
			{
				for(int j=0;j<i;++j)
					y-=getLij(i,j)*result(j);
			}
			result(i)=y/getLij(i,i);
		}
		QString resStr;
		for(int k=0;k<result.size();++k)
			resStr+=QString("  [Y%1: %2]  ").arg(k+1).arg(result(k));
		frame->output->appendPlainText(resStr);
		//求解x
		--cur;
		for(int j=cur; j >= 0; --j)
		{
			double y=result(j);
			if(j != cur)
				for(int i= cur - j; i > 0; --i)
					y-= getUij(j,j+i)*result(j+i);
			result(j)=y/ getUij(j,j);
		}
		resStr.clear();
		for(int i=0;i<result.size();++i)
			resStr+=QString("  [X%1: %2]  ").arg(i+1).arg(result(i));
		frame->output->appendPlainText(resStr);
		return true;
	}
	//求解 U 一行 cur
	for(int i=cur; i < mat->rows(); ++i)//i 当前求解列
	{
		double sum=0;
		for(int j=0; j <= cur - 1; ++j)
				sum+= getLij(cur, j) * getUij(j, i);
		(*mat)(cur, i)-=sum;
	}
	//求解 L 的一列
	for(int i= cur + 1; i < mat->rows(); ++i)//i 当前求解行
	{
		double sum=0;
		for(int j=0; j <= cur - 1; ++j)
			sum+=getLij(i,j)*getUij(j, cur);
		(*mat)(i, cur)= ((*mat)(i, cur) - sum) / (getUij(cur, cur));
	}
	++cur;
	return false;
}

void EGLU::output()
{
	frame->output->appendPlainText(QString("处理了 U的第%1行 L的第%2列").arg(cur).arg(cur));
}

EGLU::EGLU()
{
	cur=0;
}



