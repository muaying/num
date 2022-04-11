#include <QApplication>
#include <QPushButton>
#include "Frame/MainWin.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWin w;
	w.show();
	return QApplication::exec();
}
