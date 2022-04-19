//
// Created by 24100 on 2022/4/12.
//

#include "Equation.h"
#include "FrameEquation/FrameFunc.h"

FrameFunc *Equation::frame = nullptr;
bool Equation::input(const expr::Postfix &post)
{
	this->mPost = post;
	precision = frame->cmb_precision->currentText().toDouble();
	return true;
}

void Equation::setFrame(FrameFunc *frame)
{
	Equation::frame = frame;
}
