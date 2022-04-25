#ifndef NUM_FRAMEDRAW_H
#define NUM_FRAMEDRAW_H

#include <QFrame>
#include <QMutex>

class FrameDraw : public QFrame
{
	Q_OBJECT

public:
	explicit FrameDraw(QWidget *parent = nullptr);
	~FrameDraw() override;
	void paintEvent(QPaintEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;
	void mousePressEvent(QMouseEvent *event);		  //记录放大时按下的位置
	void wheelEvent(QWheelEvent *event) override;	  //放大
	void mouseMoveEvent(QMouseEvent *event) override; //鼠标拖动
	void setRangeY(double min ,double max);
public slots:
	//添加 清除数据
	void addPoints(QVector<std::pair<double, double>> &ps);
	void addXLine(double x);
	void clear();

private:
	inline int LxtoDx(double x) const //逻辑坐标转设备坐标
	{
		return static_cast<int>(left + (x - LMinX) * (right - left) / (LMaxX - LMinX));
	}
	inline int LytoDy(double y) const
	{

		return static_cast<int>(bottom - (y - LMinY) * (bottom - top) / (LMaxY - LMinY));
	}
	inline double DxtoLx(int x) const //设备坐标转逻辑坐标
	{
		return LMinX + (x - left) * (LMaxX - LMinX) / (right - left);
	}

	inline double DytoLy(int y) const
	{
		return LMinY + (bottom - y) * (LMaxY - LMinY) / (bottom - top);
	}
	QVector<std::pair<double, double>> Points;
	QVector<double> xLines;

private:
	double LMaxX;
	double LMaxY;
	double LMinX;
	double LMinY;
	int px;
	double pminX;
	double pmaxX;
	int top;
	int bottom;
	int left;
	int right;
	QMutex mutex;
};

#endif // NUM_FRAMEDRAW_H
