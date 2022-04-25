//
// Created by 24100 on 2022/4/25.
//

#ifndef LEARN_NUM_IVSOLUTION_H
#define LEARN_NUM_IVSOLUTION_H

#include <QObject>

class IVSolution : public QObject
{
Q_OBJECT
public:
	IVSolution(QObject* parent=nullptr);
	inline int getInterCount() const{return interCount;}
	virtual void ready()=0;
	void setXYVec(const QVector<double>& vec_x,const  QVector<double>& vec_y);
public slots:
	/**
	 * @brief 加入一个新的点
	 * 该函数会采样 -10 ~10 从而得到新的 插值曲线
	 * 是一个耗时操作 需要 开启线程
	 * 采样完毕 产生 sendPoints 信号 发送 采样得到的数据 ps
	 *
	 */
	virtual void next()=0;

signals:
	void sendPoints(QVector<std::pair<double, double>> &ps);

protected:
	QVector<double> m_vecX;
	QVector<double> m_vecY;
	int interCount;//已经加入的点数
};


#endif //LEARN_NUM_IVSOLUTION_H
