#include "EquationGroup.h"

#include <QDebug>
const char * Gauss = R"(当前方法 : 列选住主元的高斯消元法
要求输入 方程组的增广矩阵
)";

EquationGroup::EquationGroup(QWidget *parent) :
		QFrame(parent)
{
	setupUi(this);

	model=new matModel(this);
	tableView->setModel(model);
	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


	EGSolution::setMat(&model->mat);
	egGauss=new EGGauss;
	solution=egGauss;
}

EquationGroup::~EquationGroup()
{
	delete egGauss;
}

void EquationGroup::on_sbox_xcnt_valueChanged(int i)
{
	model->setXCount(i);
}

void EquationGroup::on_btn_ready_clicked()
{
	solution->ready();
}

void EquationGroup::on_btn_next_clicked()
{
	solution->next();
}


