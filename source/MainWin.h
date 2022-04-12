//
// Created by 24100 on 2022/4/10.
//

#ifndef NUM_MAINWIN_H
#define NUM_MAINWIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class MainWin;
}
QT_END_NAMESPACE

class MainWin : public QWidget
{
	Q_OBJECT

public:
	explicit MainWin(QWidget *parent = nullptr);
	~MainWin() override;

private:
	Ui::MainWin *ui;
};

#endif // NUM_MAINWIN_H
