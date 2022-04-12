#ifndef NUM_NEWTON_H
#define NUM_NEWTON_H
#include "Equation.h"
/**
 * @brief
 *
 * 牛顿迭代法
 */

class Newton :public  Equation
{
public:
	using Equation::Equation;
	bool next() override;
	void output() override;
	bool input(const expr::Postfix &post) override;
private:
	double x0;
	expr::Postfix  derivative;
};


#endif //NUM_NEWTON_H
