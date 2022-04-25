//
// Created by 24100 on 2022/4/25.
//

#include "IVLagrange.h"
#include <QDebug>
void IVLagrange::ready()
{
	interCount = 2;
}

void IVLagrange::next()
{
	if (interCount == m_vecX.size())
		return;
	// qDebug() << "开始采样";
	++interCount;
	QVector<std::pair<double, double>> ps;
	double numerator;	//分子
	double denominator; //分母
	QVector<double> Ln; //基函数
	double y;
	for (double step = -10; step < 10; step += 0.0001)
	{
		y = 0;
		// step = 5;
		Ln.clear();
		for (int i = 0; i < interCount; ++i)
		{
			//求解基函数
			numerator = 1;
			denominator = 1;
			for (int j = 0; j < interCount; ++j)
				if (i != j)
				{
					numerator *= (step - m_vecX[j]);
					denominator *= (m_vecX[i] - m_vecX[j]);
				}
			Ln.push_back(numerator / denominator);
		}

		for (int i = 0; i < interCount; ++i)
			y += m_vecY[i] * Ln[i];
		// qDebug()<<"y"<<y;
		if (y < 100 && y > -100)
		{
			// qDebug() << y;
			ps.push_back(std::make_pair(step, y));
		}
	}

	emit sendPoints(ps);
	// qDebug() << "采样完成";
}
