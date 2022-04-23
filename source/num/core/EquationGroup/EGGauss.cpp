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
	auto maxIndex=maxIndexVec(mat->col(curX));
	qDebug()<<maxIndex;
	if(maxIndex!=0)
	{
		auto vec=mat->row(maxIndex);
		mat->row(maxIndex)==mat->row(0);
		mat->row(0)=vec;
	}
	return false;
}
