//
// Created by 24100 on 2022/4/25.
//

#include "IVSolution.h"

void IVSolution::setXYVec(const QVector<double> &vec_x, const QVector<double> &vec_y)
{
	m_vecX=vec_x;
	m_vecY=vec_y;
}

IVSolution::IVSolution(QObject *parent) : QObject(parent),interCount(0)
{
}
