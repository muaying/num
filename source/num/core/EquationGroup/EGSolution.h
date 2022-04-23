//
// Created by 24100 on 2022/4/23.
//

#ifndef LEARN_NUM_EGSOLUTION_H
#define LEARN_NUM_EGSOLUTION_H
#include <Eigen/Dense>
#include "FrameEquationGroup/EquationGroup.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class EGSolution
{
public:
	virtual void ready()=0;
	virtual bool next()=0;
	virtual void output()=0;
	static void setFrameMat(EquationGroup* frame,MatrixXd* m);
protected:
	static MatrixXd* mat;
	static EquationGroup* frame;
	static int maxAbsIndexVec(const VectorXd& vectorXd);
};


#endif //LEARN_NUM_EGSOLUTION_H
