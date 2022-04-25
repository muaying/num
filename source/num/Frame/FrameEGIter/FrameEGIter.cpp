//
// Created by 24100 on 2022/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FrameEGIter.h" resolved

#include "FrameEGIter.h"
#include "ui_FrameEGIter.h"


FrameEGIter::FrameEGIter(QWidget *parent) :
		QFrame(parent)
{
	setupUi(this);
	model_eg=new matModel(this);
	model_iter=new matModel(this);
	tv_inputMat->setModel(model_eg);
	tv_iterMat->setModel(model_iter);
	model_iter->setMatSize(3,3);
	tv_inputMat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tv_inputMat->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tv_iterMat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tv_iterMat->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

FrameEGIter::~FrameEGIter()
{
}
