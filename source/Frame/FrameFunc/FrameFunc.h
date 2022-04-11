//
// Created by 24100 on 2022/4/10.
//

#ifndef NUM_FRAMEFUNC_H
#define NUM_FRAMEFUNC_H

#include <QFrame>


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
	Ui::FrameFunc *ui;
};


#endif //NUM_FRAMEFUNC_H
