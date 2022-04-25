//
// Created by 24100 on 2022/4/25.
//

#ifndef LEARN_NUM_FRAMEINTERVALUE_H
#define LEARN_NUM_FRAMEINTERVALUE_H

#include <QFrame>
#include "ui_FrameInterValue.h"
#include "XYModel/XYModel.h"
#include <QThread>
#include "InterValue/IVLagrange.h"
class FrameInterValue : public QFrame, public Ui::FrameInterValue
{
Q_OBJECT

public:
	explicit FrameInterValue(QWidget *parent = nullptr);
	~FrameInterValue() override;

	signals:
	void doNext();
private slots:
	void on_btn_ready_clicked();
	void on_btn_next_clicked();
	void on_spinBox_valueChanged(int i);

private:
	IVLagrange* lagrange;
	XYModel* xyModel;
	QThread* m_thread;
};


#endif //LEARN_NUM_FRAMEINTERVALUE_H
