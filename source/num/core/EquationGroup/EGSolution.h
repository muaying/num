//
// Created by 24100 on 2022/4/23.
//

#ifndef LEARN_NUM_EGSOLUTION_H
#define LEARN_NUM_EGSOLUTION_H
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class EGSolution
{
public:
	virtual void ready()=0;
	virtual bool next()=0;
	static void setMat(MatrixXd* m);
protected:
	static MatrixXd* mat;
	static int maxIndexVec(const VectorXd& vectorXd);
};


#endif //LEARN_NUM_EGSOLUTION_H
