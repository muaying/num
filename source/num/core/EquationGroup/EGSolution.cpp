//
// Created by 24100 on 2022/4/23.
//
#include "EGSolution.h"
EquationGroup* EGSolution::frame= nullptr;
MatrixXd* EGSolution::mat= nullptr;


void EGSolution::setFrameMat(EquationGroup *frame, MatrixXd *m)
{
	EGSolution::mat=m;
	EGSolution::frame=frame;
}



int EGSolution::maxAbsIndexVec(const VectorXd &vectorXd)
{
	int maxIndex=0;
	for(int i=0;i<vectorXd.size();++i)
		if(abs(vectorXd[maxIndex])< abs(vectorXd[i]))
			maxIndex=i;
	return maxIndex;
}

