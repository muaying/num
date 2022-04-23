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

	return false;
}
