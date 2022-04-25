#include "EquationGroup.h"

#include "EquationGroupDM/EGSolution.h"
#include "EquationGroupDM/EGGauss.h"
#include "EquationGroupDM/EGLU.h"
#include <QDebug>
#include <QMessageBox>

const char * INFO_GAUSS = R"(当前方法 : 列选住主元的高斯消元法
输入要求：
1. 确保方程组有解
2. 增广矩阵可以化简为下三角矩阵
其他：
点击运算一次 进行一次消元
)";
const char * INFO_LU = R"(当前方法 : LU分解法
输入要求：
1. 确保方程组有解
2. 增广矩阵可逆
其他：
1. 点击运算一次  计算 L的第i列 U的第i行 i=1,2,..
2. LU 直接覆盖原来矩阵

)";

EquationGroup::EquationGroup(QWidget *parent) :
		QFrame(parent)
{
	setupUi(this);

	model=new matModel(this);
	tableView->setModel(model);
	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	model->mat<<1, -1, 1, -4, 2,
			5, -4, 3, 12, 4,
			2, 1, 1, 11, 3,
			2, -1, 7, -1, 0;
	model->updateMat();
	m_oldMat=model->mat;


	EGSolution::setFrameMat(this,&model->mat);
	egGauss=new EGGauss;
	egLu=new EGLU;
	solution=egGauss;

	info->setPlainText(INFO_GAUSS);
}

EquationGroup::~EquationGroup()
{
	delete egGauss;
	delete egLu;
}

void EquationGroup::on_sbox_xcnt_valueChanged(int i)
{
	model->setMatSize(i,i+1);
}

void EquationGroup::on_btn_ready_clicked()
{
	solution->ready();
	m_oldMat=model->mat;
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
	info->setPlainText(INFO_GAUSS);
}

void EquationGroup::on_btn_method2_clicked()
{
	solution=egLu;
	info->setPlainText(INFO_LU);
}

void EquationGroup::on_btn_reset_clicked()
{
	if(m_oldMat.rows()==model->mat.rows())
	{
		model->mat=m_oldMat;
		model->updateMat();
	}
}


