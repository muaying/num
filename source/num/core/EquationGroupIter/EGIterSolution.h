#ifndef LEARN_NUM_EGITERSOLUTION_H
#define LEARN_NUM_EGITERSOLUTION_H

#include "FrameEGIter/FrameEGIter.h"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;
class EGIterSolution
{
public:
	virtual void ready();
	virtual bool next()=0;
	virtual void output();
	static void setFrameMat(FrameEGIter* frame,MatrixXd* mat_eg,MatrixXd* mat_iter);
protected:
	VectorXd vecX;
	int times;//迭代次数
	static FrameEGIter* frame;
	static MatrixXd* mat_eg;
	static MatrixXd* mat_iter;
};


#endif //LEARN_NUM_EGITERSOLUTION_H
