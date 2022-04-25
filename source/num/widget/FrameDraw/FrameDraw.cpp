#include "FrameDraw.h"
#include <QPaintEvent>
#include <QPainter>
#include <QResizeEvent>
#include <QWheelEvent>
#include <QDebug>
FrameDraw::FrameDraw(QWidget *parent) : QFrame(parent), LMaxX(10), LMinX(-10), LMaxY(10), LMinY(-10),
										left(0), right(0), top(0), bottom(0)
{
}

FrameDraw::~FrameDraw()
{
}

void FrameDraw::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	//绘制背景
	QBrush bgBrush("#D3D3D3");
	painter.setBrush(bgBrush);
	painter.drawRect(event->rect());

	painter.setPen(QPen(Qt::blue, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
	painter.setFont(QFont("微软雅黑", 12));
	//绘制轴
	int Ox = LxtoDx(0);
	int Oy = LytoDy(0);
	if (Oy >= top && Oy <= bottom)
	{
		// x方向
		painter.drawLine(left, Oy, right + 10, Oy);
		painter.drawText(right + 10, Oy + 10, "X轴");
		painter.drawLine(right + 10, Oy, right - 5, Oy + 5);
		painter.drawLine(right + 10, Oy, right - 5, Oy - 5);
	}

	if (Ox >= left && Ox <= right)
	{
		// y方向
		painter.drawLine(Ox, top - 10, Ox, bottom);
		painter.drawText(Ox + 10, top - 10, "Y轴");
		painter.drawLine(Ox, top - 10, Ox + 5, top - 5);
		painter.drawLine(Ox, top - 10, Ox - 5, top - 5);
	}

	//绘制 点
	painter.setPen(QPen(Qt::red, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
	for (const auto &point : Points)
		painter.drawPoint(LxtoDx(point.first), LytoDy(point.second));

	//绘制 线
	painter.setPen(QPen(Qt::black, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
	for (auto line : xLines)
	{
		int x = LxtoDx(line);
		painter.drawLine(x, bottom, x, top);
	}

	painter.setPen(QPen(Qt::darkGray, 1.0, Qt::DashDotLine));
	painter.setFont(QFont("微软雅黑", 10));
	// x方向
	painter.drawLine(left, bottom, right, bottom);
	for (int i = left; i < right; i += 50)
	{
		painter.drawLine(i, bottom, i, bottom + 3);
		painter.drawText(i - 8, bottom + 10, QString::number(DxtoLx(i), 'f', 1));
	}
	QFrame::paintEvent(event);
}

void FrameDraw::resizeEvent(QResizeEvent *event)
{
	top = static_cast<int>(rect().bottom() * 0.05);
	bottom = static_cast<int>(rect().bottom() * 0.95);
	left = static_cast<int>(rect().right() * 0.05);
	right = static_cast<int>(rect().right() * 0.95);
	QWidget::resizeEvent(event);
}

void FrameDraw::mousePressEvent(QMouseEvent *event)
{
	px = event->x();
	pmaxX = LMaxX;
	pminX = LMinX;
	QFrame::mousePressEvent(event);
}

void FrameDraw::wheelEvent(QWheelEvent *event)
{
	double dx = 0.1 * event->angleDelta().y() / 120 * (LMaxX - LMinX); //当前增量
	double dr = dx * (right - event->position().x()) / (right - left);
	double MaxX = LMaxX + dr;
	double MinX = LMinX - dx + dr;
	if (dx > 0 || MaxX - MinX > 1)
	{
		LMaxX = MaxX;
		LMinX = MinX;
	}
	update();
	QFrame::wheelEvent(event);
}

void FrameDraw::mouseMoveEvent(QMouseEvent *event)
{
	double offsetX = (px - event->x()) * (LMaxX - LMinX) / (right - left);
	LMaxX = pmaxX + offsetX;
	LMinX = pminX + offsetX;
	update();
	QFrame::mouseMoveEvent(event);
}
void FrameDraw::addPoints(QVector<std::pair<double, double>> &ps)
{
	QMutexLocker locker(&mutex);
	this->Points.append(ps);
	this->update();
}

void FrameDraw::addXLine(double x)
{
	this->xLines.push_back(x);
	this->update();
}

void FrameDraw::clear()
{
	xLines.clear();
	LMaxX = 10;
	LMinX = -10;
	QMutexLocker locker(&mutex);
	Points.clear();
	update();
}

void FrameDraw::setRangeY(double min, double max)
{
	LMaxY=max;
	LMinY=min;
	update();
}
