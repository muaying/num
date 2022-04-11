#include "MainWin.h"
#include "ui_MainWin.h"

MainWin::MainWin(QWidget *parent) : QWidget(parent), ui(new Ui::MainWin)
{
	ui->setupUi(this);
	ui->swdg->setCurrentIndex(0);
	QString hello = "你好 qt";
	connect(ui->btn_menu1, &QPushButton::clicked, this, [this]()
			{ ui->swdg->setCurrentIndex(0); });
	connect(ui->btn_menu2, &QPushButton::clicked, this, [this]()
			{ ui->swdg->setCurrentIndex(1); });
}

MainWin::~MainWin()
{
	delete ui;
}
