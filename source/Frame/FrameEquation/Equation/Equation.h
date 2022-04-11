#ifndef NUM_EQUATION_H
#define NUM_EQUATION_H

#include "../FrameFunc.h"
#include <cmath>
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
    virtual void update() = 0;
    /**
     * @brief 从界面获取数据
     */
    virtual void input(expr::Postfix &&post)
    {
        this->mPost = std::move(post);
    }
    static void setFrame(FrameFunc *frame) //和界面沟通的桥梁
    {
        Equation::frame = frame;
    }

protected:
    inline bool isEqual(double x1, double x2)
    {
        return abs(x1 - x2) < precision;
    }

protected:
    static FrameFunc *frame; //和界面沟通的桥梁
    expr::Postfix mPost;
    double precision;
};
FrameFunc *Equation::frame = nullptr;
#endif