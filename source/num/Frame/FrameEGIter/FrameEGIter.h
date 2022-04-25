//
// Created by 24100 on 2022/4/24.
//

#ifndef LEARN_NUM_FRAMEEGITER_H
#define LEARN_NUM_FRAMEEGITER_H

#include <QFrame>
#include "matModel.h"
#include "ui_FrameEGIter.h"

class FrameEGIter : public QFrame,public Ui::FrameEGIter
{
Q_OBJECT

public:
	explicit FrameEGIter(QWidget *parent = nullptr);
	~FrameEGIter() override;

private:
	matModel* model_eg;  //增广矩阵 model
	matModel* model_iter;//迭代矩阵 model


};


#endif //LEARN_NUM_FRAMEEGITER_H
