//
// Created by 24100 on 2022/4/23.
//
#include "EGSolution.h"

void EGSolution::setMat(MatrixXd *m)
{
	EGSolution::mat=m;
}

int EGSolution::maxIndexVec(const VectorXd &vectorXd)
{
	int maxIndex=0;
	for(int i=0;i<vectorXd.size();++i)
		if(vectorXd[maxIndex]<vectorXd[i])
			maxIndex=i;
	return maxIndex;
}
