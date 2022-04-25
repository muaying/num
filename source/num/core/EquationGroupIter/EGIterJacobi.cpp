//
// Created by 24100 on 2022/4/24.
//

#include "EGIterJacobi.h"

/**
 * @brief  求解迭代矩阵
 */
void EGIterJacobi::ready()
{
	MatrixXd  A= mat_eg->leftCols(mat_eg->rows());
	MatrixXd  D=A.asDiagonal();
	MatrixXd E(A.rows(),A.rows());
	E.setIdentity();
	*mat_iter = E -D.transpose()*A;
}

bool EGIterJacobi::next()
{
	return false;
}

void EGIterJacobi::output()
{

}
