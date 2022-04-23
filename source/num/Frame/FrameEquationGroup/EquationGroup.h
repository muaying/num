//
// Created by 24100 on 2022/4/19.
//

#ifndef NUM_EQUATIONGROUP_H
#define NUM_EQUATIONGROUP_H

#include <QFrame>
#include "mat4Model.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class EquationGroup;
}
QT_END_NAMESPACE

class EquationGroup : public QFrame
{
Q_OBJECT

public:
	explicit EquationGroup(QWidget *parent = nullptr);
	~EquationGroup() override;

private:
	Ui::EquationGroup *ui;
	mat4Model* model;
};


#endif //NUM_EQUATIONGROUP_H
