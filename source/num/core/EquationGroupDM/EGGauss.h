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
	EGGauss();
	virtual void ready()override;
	virtual bool next()override;
	void output() override;

private:
	int curX;//当前xiao元位置
	int maxIndex;//列选主元
};


#endif //LEARN_NUM_EGGAUSS_H
