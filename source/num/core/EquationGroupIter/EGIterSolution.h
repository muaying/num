#ifndef LEARN_NUM_EGITERSOLUTION_H
#define LEARN_NUM_EGITERSOLUTION_H

#include "FrameEGIter/FrameEGIter.h"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;
class EGIterSolution
{
public:
	virtual void ready()=0;
	virtual bool next()=0;
	virtual void output()=0;
	static void setFrameMat(FrameEGIter* frame,MatrixXd* mat_eg,MatrixXd* mat_iter);
protected:
	static FrameEGIter* frame;
	static MatrixXd* mat_eg;
	static MatrixXd* mat_iter;
};


#endif //LEARN_NUM_EGITERSOLUTION_H
