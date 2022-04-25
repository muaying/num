#include "Sampling.h"

Samping::Samping(QObject *parent) : QObject(parent)
{
}

void Samping::smaping(const expr::Postfix &post, double minX, double maxX, int rate)
{
    QVector<std::pair<double, double>> ret;
    double step = (maxX - minX) / rate;
    double num = 0;
    ret.clear();
    for (double i = minX; i <= maxX; i += step)
    {
        expr::getResult(post, num, i);
        ret.push_back({i, num});
    }
    emit over(ret);
}