//
// Created by 24100 on 2022/4/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FrameFunc.h" resolved

#include "FrameFunc.h"
#include "ui_FrameFunc.h"


FrameFunc::FrameFunc(QWidget *parent) :
		QFrame(parent), ui(new Ui::FrameFunc)
{
	ui->setupUi(this);
}

FrameFunc::~FrameFunc()
{
	delete ui;
}

