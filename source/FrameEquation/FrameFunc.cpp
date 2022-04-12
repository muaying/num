#include "FrameFunc.h"
#include "Equation/all.h"
FrameFunc::FrameFunc(QWidget *parent) : QFrame(parent)
{

	// ui 界面初始化
	setupUi(this);
	QDoubleValidator *doubleValidator = new QDoubleValidator(-10, 10, 3, this);
	edt_x0->setValidator(doubleValidator);
	edt_a1->setValidator(doubleValidator);
	edt_a2->setValidator(doubleValidator);
	edt_a1->setText("-10");
	edt_a2->setText("10");
	edt_x0->setText("0");
	edt_funcExpr->setText("x^2-1");

	//算法
	Equation::setFrame(this);
	bisection = new Bisection();
	equation = bisection;

	//绘图
	mThread = new QThread(this);
	mThread->start();
	mSampling = new Samping(this);
	mSampling->moveToThread(mThread);
	qRegisterMetaType<expr::Postfix>("expr::Postfix");
	qRegisterMetaType<QVector<std::pair<double, double>>>("QVector<std::pair<double,double>>&");

	//槽函数
	connect(btn_read, &QPushButton::clicked, this, &FrameFunc::onBtnReadClick);
	connect(mSampling, &Samping::over, wdgPaint, &FrameDraw::addPoints);
	connect(this, &FrameFunc::doSampling, mSampling, &Samping::smaping);
}

FrameFunc::~FrameFunc()
{
	delete bisection;
	mThread->quit();
	mThread->wait();
}

void FrameFunc::onBtnReadClick()
{
	QString expr = edt_funcExpr->text();
	expr::Postfix post;
	if (expr::getPostfix(expr, post))
	{
		qDebug() << post;
		equation->input(post);
		emit doSampling(post);
	}
}
