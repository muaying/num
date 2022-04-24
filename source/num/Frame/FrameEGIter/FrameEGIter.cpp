//
// Created by 24100 on 2022/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FrameEGIter.h" resolved

#include "FrameEGIter.h"
#include "ui_FrameEGIter.h"


FrameEGIter::FrameEGIter(QWidget *parent) :
		QFrame(parent), ui(new Ui::FrameEGIter)
{
	ui->setupUi(this);
}

FrameEGIter::~FrameEGIter()
{
	delete ui;
}
