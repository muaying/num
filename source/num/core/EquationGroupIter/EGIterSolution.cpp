//
// Created by 24100 on 2022/4/24.
//

#include "EGIterSolution.h"
FrameEGIter * EGIterSolution::frame= nullptr;
MatrixXd * EGIterSolution::mat_eg=nullptr;
MatrixXd * EGIterSolution::mat_iter=nullptr;


void EGIterSolution::setFrameMat(FrameEGIter *frame, MatrixXd *mat_eg, MatrixXd *mat_iter)
{
	EGIterSolution::frame= frame;
	EGIterSolution::mat_eg=mat_eg;
	EGIterSolution::mat_iter=mat_iter;
}
