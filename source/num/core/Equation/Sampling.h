#ifndef NUM_SAMPLING_H
#define NUM_SAMPLING_H

#include <QObject>
#include "expr/expr.h"
/**
 * @brief 曲线采样
 */

class Samping : public QObject
{
    Q_OBJECT
public:
    Samping(QObject *parent = nullptr);
public slots:
    void smaping(const expr::Postfix &post, double minX, double maxX, int rate);
signals:
    void over(QVector<std::pair<double, double>> &ret);

private:

};

#endif // NUM_SAMPLING_H