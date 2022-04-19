#ifndef NUM_FRAMEFUNC_H
#define NUM_FRAMEFUNC_H

#include <QFrame>
#include <QThread>
#include "Sampling.h"
#include "ui_FrameFunc.h"


class Equation;
class Bisection;
class Newton;

class FrameFunc : public QFrame, public Ui::FrameFunc
{
	Q_OBJECT
public:
	explicit FrameFunc(QWidget *parent = nullptr);
	~FrameFunc() override;

private slots:
	void on_btn_ready_clicked();
	/**
	 * 运行一次迭代算法
	 */
	void on_btn_next_clicked();
	void on_btn_equation1_clicked();
	void on_btn_equation2_clicked();
	void on_btn_equation3_clicked();
	void on_btn_equation4_clicked();
signals:
	void doSampling(const expr::Postfix &post, double minX = -10, double maxX = 10, int rate = 10000);

private:
	QThread *mThread;
	Samping *mSampling;

	//算法
	Equation *equation;
	Bisection *bisection;
	Newton* newton;
	bool readyed;
	int curitcnt; //迭代次数
};

#endif // NUM_FRAMEFUNC_H
