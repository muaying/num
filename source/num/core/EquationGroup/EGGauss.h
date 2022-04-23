//
// Created by 24100 on 2022/4/23.
//

#ifndef LEARN_NUM_EGGAUSS_H
#define LEARN_NUM_EGGAUSS_H
#include "EGSolution.h"
/**
 * @brief 列选主元的高斯解法
 *
 */
class EGGauss :public EGSolution
{
public:
	virtual void ready();
	virtual bool next();
private:
	int curX;//当前xiao元位置
};


#endif //LEARN_NUM_EGGAUSS_H
