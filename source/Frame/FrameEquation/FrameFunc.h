//
// Created by 24100 on 2022/4/10.
//

#ifndef NUM_FRAMEFUNC_H
#define NUM_FRAMEFUNC_H

#include <QFrame>
#include <QThread>
#include "Sampling.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
	class FrameFunc;
}
QT_END_NAMESPACE

class FrameFunc : public QFrame
{
	Q_OBJECT

public:
	explicit FrameFunc(QWidget *parent = nullptr);
	~FrameFunc() override;

private:
	void onBtnReadClick();
signals:
	void doSampling(const expr::Postfix &post, double minX = -10, double maxX = 10, int rate = 10000);

private:
	Ui::FrameFunc *ui;
	QThread *mThread;
	Samping *mSampling;
};

#endif // NUM_FRAMEFUNC_H
