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
private:
	MatrixXd di;//D(-1)
	VectorXd vecF;
};


#endif //LEARN_NUM_EGITERJACOBI_H
