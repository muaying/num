#ifndef LEARN_NUM_EGITERJACOBI_H
#define LEARN_NUM_EGITERJACOBI_H

#include "EGIterSolution.h"
/**
 * @brief
 * 雅可比迭代
 */
class EGIterJacobi :public EGIterSolution
{
public:
	void ready() override;
	bool next() override;
	void output() override;
};


#endif //LEARN_NUM_EGITERJACOBI_H
