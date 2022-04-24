#ifndef NUM_EQUATIONGROUP_H
#define NUM_EQUATIONGROUP_H

#include <QFrame>
#include "matModel.h"
#include "ui_EquationGroup.h"


class EGSolution;
class EGGauss;
class EGLU;
class EquationGroup : public QFrame ,public Ui::EquationGroup
{
Q_OBJECT
public:
	explicit EquationGroup(QWidget *parent = nullptr);
	~EquationGroup() override;
public slots:
	void on_sbox_xcnt_valueChanged(int i);
	void on_btn_ready_clicked();
	void on_btn_next_clicked();
	void on_btn_method1_clicked();
	void on_btn_method2_clicked();
	void on_btn_reset_clicked();

private:
	matModel* model;
	EGSolution* solution;
	EGGauss* egGauss;
	EGLU* egLu;
	Eigen::MatrixXd m_oldMat;
};


#endif //NUM_EQUATIONGROUP_H
