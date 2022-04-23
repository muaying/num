#include <QApplication>
#include <QPushButton>
#include "MainWin/MainWin.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWin w;
	w.show();
	return QApplication::exec();
}
