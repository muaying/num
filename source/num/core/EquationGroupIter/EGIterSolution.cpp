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

void EGIterSolution::ready()
{
	times=0;
	vecX.resize(mat_eg->rows());
	vecX(0)=frame->dspb_x1->value();
	vecX(1)=frame->dspb_x2->value();
	vecX(2)=frame->dspb_x3->value();
	//vecX(3)=frame->dspb_x4->value();
}

void EGIterSolution::output()
{
	frame->output->appendPlainText(QString("当前迭代次数%1").arg(times));
	frame->output->appendPlainText(QString("[X1:%1],[X2:%2],[X3:%3]").arg(vecX(0)).arg(vecX(1)).arg(vecX(2)));
}