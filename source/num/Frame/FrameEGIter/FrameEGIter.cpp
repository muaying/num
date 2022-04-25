//
// Created by 24100 on 2022/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FrameEGIter.h" resolved

#include "FrameEGIter.h"
#include "ui_FrameEGIter.h"
#include "EquationGroupIter/EGIterJacobi.h"


FrameEGIter::FrameEGIter(QWidget *parent) :
		QFrame(parent)
{
	setupUi(this);
	model_eg=new matModel(this);
	model_iter=new matModel(this);
	tv_inputMat->setModel(model_eg);
	tv_iterMat->setModel(model_iter);
	model_eg->setMatSize(3,4);
	model_iter->setMatSize(3,3);
	tv_inputMat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tv_inputMat->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tv_iterMat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tv_iterMat->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	info->setPlainText(R"(当前方法 雅可比迭代)");


	model_eg->mat<<  9,-1,-1,7,
					-1,10,-1,8,
					-1,-1,15,13;
	model_eg->updateMat();

	EGIterJacobi::setFrameMat(this,&model_eg->mat,&model_iter->mat);
	egIterJacobi=new EGIterJacobi;
}

FrameEGIter::~FrameEGIter()
{
	delete egIterJacobi;
}

void FrameEGIter::on_btn_ready_clicked()
{
	output->clear();
	egIterJacobi->ready();
	model_iter->updateMat();
}

void FrameEGIter::on_btn_next_clicked()
{
	if(!egIterJacobi->next())
		egIterJacobi->output();
}
