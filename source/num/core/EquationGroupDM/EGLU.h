//
// Created by 24100 on 2022/4/23.
//

#ifndef LEARN_NUM_EGLU_H
#define LEARN_NUM_EGLU_H

#include "EGSolution.h"
class EGLU :public EGSolution
{
public:
	EGLU();
	void ready() override;
	bool next() override;
	void output() override;
private:
	inline double  getLij(int i,int j) //获取 L 矩阵上对应 ij 位置的值
	{
		if(i==j)
			return 1;
		else if(i<j)
			return 0;
		else
			return (*mat)(i,j);
	}
	inline double  getUij(int i,int j) //获取 U 矩阵位置的值
	{
		if(i>j)
			return 0;
		else
			return (*mat)(i,j);
	}
private:
	int cur;//当前分解到哪里了
};


#endif //LEARN_NUM_EGLU_H
