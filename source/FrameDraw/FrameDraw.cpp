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
		painter.drawText(i - 8, bottom + 10, QString::asprintf("%.2f", DxtoLx(i)));
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
	oldx = DxtoLx(event->x());
	QFrame::mousePressEvent(event);
}

void FrameDraw::wheelEvent(QWheelEvent *event)
{
	double min = this->LMinX;
	double max = this->LMaxX;
	double d = event->angleDelta().y() / 40;
	//当放大到差值 小于等于 1的时候停止放大
	if (d < 0 || max - min > 1)
	{

		max -= d * 0.1;
		min += d * 0.1;

		if (max < 10 && min > -10)
		{
			LMinX = min;
			LMaxX = max;
			update();
		}
	}

	QFrame::wheelEvent(event);
}

void FrameDraw::mouseMoveEvent(QMouseEvent *event)
{
	double offset = oldx - DxtoLx(event->x());
	double min = LMinX + offset;
	double max = LMaxX + offset;
	if (min > -10 && max <= 10)
	{
		LMinX = min;
		LMaxX = max;
		update();
	}
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

int FrameDraw::LxtoDx(double x) const
{
	return static_cast<int>(left + (x - LMinX) * (right - left) / (LMaxX - LMinX));
}

double FrameDraw::DxtoLx(int x) const
{
	return LMinX + (x - left) * (LMaxX - LMinX) / (right - left);
}
int FrameDraw::LytoDy(double y) const
{
	return static_cast<int>(bottom - (y - LMinY) * (bottom - top) / (LMaxY - LMinY));
}

double FrameDraw::DytoLy(int y) const
{
	return LMinY + (bottom - y) * (LMaxY - LMinY) / (bottom - top);
}
