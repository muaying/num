//
// Created by 24100 on 2022/4/24.
//

#ifndef LEARN_NUM_FRAMEEGITER_H
#define LEARN_NUM_FRAMEEGITER_H

#include <QFrame>


QT_BEGIN_NAMESPACE
namespace Ui
{
class FrameEGIter;
}
QT_END_NAMESPACE

class FrameEGIter : public QFrame
{
Q_OBJECT

public:
	explicit FrameEGIter(QWidget *parent = nullptr);
	~FrameEGIter() override;

private:
	Ui::FrameEGIter *ui;
};


#endif //LEARN_NUM_FRAMEEGITER_H
