//
// Created by 24100 on 2022/4/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FrameInterValue.h" resolved

#include <QMessageBox>
#include "FrameInterValue.h"

FrameInterValue::FrameInterValue(QWidget *parent) : QFrame(parent)
{
	setupUi(this);
	xyModel = new XYModel(this);
	tableView->setModel(xyModel);
	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	lagrange = new IVLagrange();
	m_thread = new QThread(this);
	m_thread->start();
	lagrange->moveToThread(m_thread);

	connect(lagrange, &IVLagrange::sendPoints, frameDraw, &FrameDraw::addPoints);
	connect(this, &FrameInterValue::doNext, lagrange, &IVLagrange::next);

	frameDraw->setRangeY(-100, 100);

	info->setPlainText("当前方法： 拉格朗日插值法\n"
					   "输入要求: 输入不少于4个点的互异点\n"
					   "默认值为 斐波那契数列");
}

FrameInterValue::~FrameInterValue()
{
	m_thread->quit();
	m_thread->wait();
	m_thread->deleteLater();

	delete lagrange;
}

void FrameInterValue::on_btn_ready_clicked()
{
	lagrange->ready();
	lagrange->setXYVec(xyModel->vec_x, xyModel->vec_y);
	frameDraw->clear();
}

void FrameInterValue::on_btn_next_clicked()
{
	if (!lagrange->isOver())
	{
		frameDraw->clear();
		emit doNext();
		output->appendPlainText(QString("已经对前%1个点进行插值").arg(lagrange->getInterCount() + 1));
	}
	else
		QMessageBox::information(this, "提示", "所有顶点以添加");
}

void FrameInterValue::on_spinBox_valueChanged(int i)
{
	xyModel->setCount(i);
}
