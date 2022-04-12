
#ifndef NUM_EQUATION_H
#define NUM_EQUATION_H

#include <cmath>
#include "expr/expr.h"
/**
 * 非线性方程求解 基类
 */
class FrameFunc;
class Equation
{
public:
    /**
     * @brief 迭代一次
     * @return
     * true  迭代结束 ，false
     */
    virtual bool next() = 0;
    /**
     * @brief 更新界面
     */
    virtual void output() = 0;
    /**
     * @brief 从界面获取数据
     */
    virtual void input(const expr::Postfix &post);
    static void setFrame(FrameFunc *frame);

protected:
    inline bool isEqual(double x1, double x2)
    {
        return abs(x1 - x2) < precision;
    }

protected:
    expr::Postfix mPost; //后缀表达式
    double precision;    //计算精度
    static FrameFunc *frame;

private:
};

#endif // NUM_EQUATION_H
