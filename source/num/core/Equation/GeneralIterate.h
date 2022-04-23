//
// 一般迭代法
//

#ifndef LEARN_NUM_GENERALITERATE_H
#define LEARN_NUM_GENERALITERATE_H

#include "Equation.h"

class GeneralIterate:public Equation
{
public:
	using Equation::Equation;
	bool next() override;
	void output() override;
	bool input(const expr::Postfix &post) override;
private:
	expr::Postfix iter;//迭代式
	double x0;
};


#endif //LEARN_NUM_GENERALITERATE_H
