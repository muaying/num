//
// Created by 24100 on 2022/4/25.
//

#ifndef LEARN_NUM_IVLAGRANGE_H
#define LEARN_NUM_IVLAGRANGE_H
#include "IVSolution.h"

class IVLagrange: public IVSolution
{
	Q_OBJECT
public:
	using IVSolution :: IVSolution;
	void ready() override;
	inline bool isOver()const {return interCount==m_vecX.size();}
public slots:
	void next() override;
};


#endif //LEARN_NUM_IVLAGRANGE_H
