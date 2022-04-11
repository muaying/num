#ifndef NUM_FRAMEDRAW_H
#define NUM_FRAMEDRAW_H

#include <QFrame>



class FrameDraw : public QFrame
{
Q_OBJECT
public:
	explicit FrameDraw(QWidget *parent = nullptr);
	~FrameDraw() override;
	void paintEvent(QPaintEvent *event)override;
	void resizeEvent(QResizeEvent *event)override;
private:
	int LxtoDx(double x) const;//逻辑坐标转设备坐标
	int LytoDy(double y) const;
	double DxtoLx(int x) const;//设备坐标转逻辑坐标
	double DytoLy(int y) const;
	QVector<std::pair<double,double>> Points;
	QVector<double>  xLines;
private:
	int LMaxX;
	int LMaxY;
	int LMinX;
	int LMinY;
	int top;
	int bottom;
	int left;
	int right;
};


#endif //NUM_FRAMEDRAW_H
