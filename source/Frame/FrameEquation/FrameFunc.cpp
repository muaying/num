#include "FrameFunc.h"
#include "ui_FrameFunc.h"
#include "../expr/expr.h"
FrameFunc::FrameFunc(QWidget *parent) : QFrame(parent), ui(new Ui::FrameFunc)
{
	ui->setupUi(this);

	mThread = new QThread(this);
	mThread->start();
	mSampling = new Samping();
	mSampling->moveToThread(mThread);
	qRegisterMetaType<expr::Postfix>("expr::Postfix");
	qRegisterMetaType<QVector<std::pair<double, double>>>("QVector<std::pair<double,double>>&");

	connect(ui->btn_read, &QPushButton::clicked, this, &FrameFunc::onBtnReadClick);
	connect(mSampling, &Samping::over, ui->wdgPaint, &FrameDraw::addPoints);
	connect(this, &FrameFunc::doSampling, mSampling, &Samping::smaping);

	// ui 界面初始化

	QDoubleValidator *doubleValidator = new QDoubleValidator(-10, 10, 3, this);
	ui->edt_x0->setValidator(doubleValidator);
	ui->edt_a1->setValidator(doubleValidator);
	ui->edt_a2->setValidator(doubleValidator);

	ui->edt_funcExpr->setText("x^2-1");
}

FrameFunc::~FrameFunc()
{
	mThread->quit();
	mThread->wait();
	delete ui;
}

void FrameFunc::onBtnReadClick()
{
	QString expr = ui->edt_funcExpr->text();
	expr::Postfix post;
	if (expr::getPostfix(expr, post))
	{
		qDebug() << post;
		emit doSampling(post);
	}
}
