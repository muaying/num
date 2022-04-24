#include "MainWin.h"
#include "ui_MainWin.h"

MainWin::MainWin(QWidget *parent) : QWidget(parent), ui(new Ui::MainWin)
{
	ui->setupUi(this);
	ui->swdg->setCurrentIndex(0);
}

MainWin::~MainWin()
{
	delete ui;
}

void MainWin::on_btn_menu1_clicked()
{
	ui->swdg->setCurrentIndex(0);
}

void MainWin::on_btn_menu2_clicked()
{
	ui->swdg->setCurrentIndex(1);
}

void MainWin::on_btn_menu3_clicked()
{
	ui->swdg->setCurrentIndex(2);
}

void MainWin::on_btn_menu4_clicked()
{
	ui->swdg->setCurrentIndex(3);
}

