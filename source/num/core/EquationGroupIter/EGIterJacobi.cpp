//
// Created by 24100 on 2022/4/24.
//

#include "EGIterJacobi.h"

/**
 * @brief  求解 迭代矩阵
 *
 *
 * B=E- A.diagonal.inverse()*A
 */
void EGIterJacobi::ready()
{
	EGIterSolution::ready();
	vecF=mat_eg->col(mat_eg->rows());
	MatrixXd  A= mat_eg->leftCols(mat_eg->rows());
	MatrixXd E=MatrixXd ::Identity(A.rows(),A.cols());
	di=MatrixXd ::Zero(A.rows(),A.cols());
	for(int i=0;i<A.cols();++i)
		di(i,i)=A(i,i);
	di=di.inverse();
	(*mat_iter) = E -di*A;
}

bool EGIterJacobi::next()
{
	vecX=(*mat_iter)*vecX+di*vecF;
	++times;
	return false;
}


