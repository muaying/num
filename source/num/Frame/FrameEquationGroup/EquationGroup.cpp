#include "EquationGroup.h"

#include "EquationGroup/EGSolution.h"
#include "EquationGroup/EGGauss.h"

#include <QDebug>
#include <QMessageBox>

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


	EGSolution::setFrameMat(this,&model->mat);
	egGauss=new EGGauss;
	solution=egGauss;

	info->setPlainText(Gauss);
}

EquationGroup::~EquationGroup()
{
	delete egGauss;
}

void EquationGroup::on_sbox_xcnt_valueChanged(int i)
{
	//model->setXCount(i);
}

void EquationGroup::on_btn_ready_clicked()
{
	solution->ready();
	output->clear();
}

void EquationGroup::on_btn_next_clicked()
{
	if(!solution->next())
	{
		solution->output();
	}else
	{
		QMessageBox::information(this, "提示", "计算结束");
	}
	model->updateMat();

}

void EquationGroup::on_btn_method1_clicked()
{
	solution=egGauss;
	info->setPlainText(Gauss);
}

void EquationGroup::on_btn_method2_clicked()
{

}

void EquationGroup::on_btn_reset_clicked()
{
	model->mat<<1, -1, 1, -4, 2,
			5, -4, 3, 12, 4,
			2, 1, 1, 11, 3,
			2, -1, 7, -1, 0;
	model->updateMat();
}


