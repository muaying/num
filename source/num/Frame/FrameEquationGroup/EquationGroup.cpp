//
// Created by 24100 on 2022/4/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EquationGroup.h" resolved

#include "EquationGroup.h"
#include "ui_EquationGroup.h"


EquationGroup::EquationGroup(QWidget *parent) :
		QFrame(parent), ui(new Ui::EquationGroup)
{
	ui->setupUi(this);
	model=new mat4Model(this);
	ui->tableView->setModel(model);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

EquationGroup::~EquationGroup()
{
	delete ui;
}

