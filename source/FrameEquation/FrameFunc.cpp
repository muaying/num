#include "FrameFunc.h"
#include "Equation/all.h"
#include <QMessageBox>

FrameFunc::FrameFunc(QWidget *parent) : QFrame(parent)
{
	// ui 界面初始化
	setupUi(this);
	QRegExpValidator *validator = new QRegExpValidator(QRegExp("^(-?1?\\d((\\.\\d{0,3}))?)$"), this);
	edt_a1->setValidator(validator);
	edt_a2->setValidator(validator);
	edt_x0->setValidator(validator);
	edt_a1->setText("-10");
	edt_a2->setText("10");
	edt_x0->setText("0");
	edt_funcExpr->setText("x^5-x-1/5");
	edt_curitcnt->setText("0");
	//算法
	Equation::setFrame(this);
	bisection = new Bisection();
	equation = bisection;
	readyed = false;
	curitcnt = 0;
	//绘图
	mThread = new QThread(this);
	mThread->start();
	mSampling = new Samping();
	mSampling->moveToThread(mThread);
	qRegisterMetaType<expr::Postfix>("expr::Postfix");
	qRegisterMetaType<QVector<std::pair<double, double>>>("QVector<std::pair<double,double>>&");

	//槽函数
	connect(btn_read, &QPushButton::clicked, this, &FrameFunc::onBtnReadClick);
	connect(btn_next, &QPushButton::clicked, this, &FrameFunc::onBtnNextClick);
	connect(mSampling, &Samping::over, wdgPaint, &FrameDraw::addPoints);
	connect(this, &FrameFunc::doSampling, mSampling, &Samping::smaping);
}

FrameFunc::~FrameFunc()
{
	delete bisection;
	mThread->quit();
	mThread->wait();
	mThread->deleteLater();
}

void FrameFunc::onBtnReadClick()
{
	QString expr = edt_funcExpr->text();
	expr::Postfix post;
	if (expr::getPostfix(expr, post))
	{

		if (equation->input(post))
		{
			wdgPaint->clear();
			readyed = true;
			edt_curitcnt->setText(QString("%1").arg(curitcnt = 0));
			emit doSampling(post);
		}
	}
	else
	{
		QMessageBox::information(this, "错误", "输入有误");
		readyed = false;
	}
	qDebug() << post;
}

void FrameFunc::onBtnNextClick()
{
	if (readyed)
	{
		if (!equation->next())
		{
			equation->output();
			edt_curitcnt->setText(QString("%1").arg(++curitcnt));
		}
		else
		{
			QMessageBox::information(this, "提示", "迭代结束");
			readyed = false;
			curitcnt = 0;
		}
	}
}