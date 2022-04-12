//
// Created by 24100 on 2022/4/12.
//

#include "Equation.h"

FrameFunc *Equation::frame = nullptr;
void Equation::input(const expr::Postfix &post)
{
	this->mPost = post;
}

void Equation::setFrame(FrameFunc *frame)
{
	Equation::frame = frame;
}
