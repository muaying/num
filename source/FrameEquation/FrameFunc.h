#ifndef NUM_FRAMEFUNC_H
#define NUM_FRAMEFUNC_H

#include <QFrame>
#include <QThread>
#include "Sampling.h"
#include "ui_FrameFunc.h"
QT_BEGIN_NAMESPACE

class Equation;

class Bisection;

class FrameFunc : public QFrame, public Ui::FrameFunc
{
	Q_OBJECT
public:
	explicit FrameFunc(QWidget *parent = nullptr);
	~FrameFunc() override;

private slots:
	void onBtnReadClick();
	/**
	 * 运行一次迭代算法
	 */
	void onBtnNextClick();
signals:
	void doSampling(const expr::Postfix &post, double minX = -10, double maxX = 10, int rate = 10000);

private:
	QThread *mThread;
	Samping *mSampling;

	//算法
	Equation *equation;
	Bisection *bisection;
	bool readyed;
	int curitcnt; //迭代次数
};

#endif // NUM_FRAMEFUNC_H
