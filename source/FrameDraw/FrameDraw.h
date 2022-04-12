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
	void wheelEvent(QWheelEvent *event) override;
public slots:
	//添加 清除数据
	void addPoints(QVector<std::pair<double, double>> &ps);
	void addXLine(double x);
	void clear();

private:
	int LxtoDx(double x) const; //逻辑坐标转设备坐标
	int LytoDy(double y) const;
	double DxtoLx(int x) const; //设备坐标转逻辑坐标
	double DytoLy(int y) const;
	QVector<std::pair<double, double>> Points;
	QVector<double> xLines;

private:
	double LMaxX;
	double LMaxY;
	double LMinX;
	double LMinY;
	int top;
	int bottom;
	int left;
	int right;
	QMutex mutex;
};

#endif // NUM_FRAMEDRAW_H
