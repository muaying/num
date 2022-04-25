#include "FrameFunc.h"
#include "Equation/all.h"
#include <QMessageBox>

const char *TIPS_BISECTION =
	R"(当前算法： 二分法
需要输入：
1. 求解方程 f(x)
2. 求解区间[a0 a1]
)";

const char *TIPS_NEWTON =
	R"(当前算法： 牛顿迭代法
需要输入：
1. 求解方程 f(x)
2. 求导函数 φ(x)
3. 初值x0
)";
const char *TIPS_GENERALITERATE =
		R"(当前算法： 简单迭代法
需要输入：
1. 求解方程 f(x)
2. 求导迭代式 φ(x)
3. 初值x0
)";


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
	edt_x0->setText("1.5");
	edt_funcExpr->setText("2*x^3-x-1");
	edt_itExpr1->setText("((x+1)/2)^(1/3)");
	edt_itExpr2->setText("6*x^2-1");
	edt_curitcnt->setText("0");
	pedt_tips->setPlainText(TIPS_BISECTION);
	//算法
	Equation::setFrame(this);
	bisection = new Bisection();
	newton = new Newton();
	iterate=new GeneralIterate();
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
	connect(mSampling, &Samping::over, wdgPaint, &FrameDraw::addPoints);
	connect(this, &FrameFunc::doSampling, mSampling, &Samping::smaping);


	on_btn_equation1_clicked();
}

FrameFunc::~FrameFunc()
{
	delete bisection;
	delete newton;

	mThread->quit();
	mThread->wait();
	mThread->deleteLater();
}

void FrameFunc::on_btn_ready_clicked()
{
	QString expr = edt_funcExpr->text();
	expr::Postfix post;
	if (expr::getPostfix(expr, post))
	{
		if (equation->input(post))
		{
			wdgPaint->clear();
			pEdit_out->clear();
			readyed = true;
			edt_curitcnt->setText(QString("%1").arg(curitcnt = 0));
			emit doSampling(post);
		}else
		{
			QMessageBox::information(this, "错误", "导函数输入有误");
			readyed = false;
		}
	}
	else
	{
		QMessageBox::information(this, "错误", "输入有误");
		readyed = false;
	}

}

void FrameFunc::on_btn_next_clicked()
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

void FrameFunc::on_btn_equation1_clicked()
{
	equation = bisection;
	pedt_tips->setPlainText(TIPS_BISECTION);
	readyed = false;
}

void FrameFunc::on_btn_equation2_clicked()
{
	equation=iterate;
	pedt_tips->setPlainText(TIPS_GENERALITERATE);
	readyed = false;
}

void FrameFunc::on_btn_equation3_clicked()
{
	equation = newton;
	pedt_tips->setPlainText(TIPS_NEWTON);
	readyed = false;
}

//void FrameFunc::on_btn_equation4_clicked()
//{
//}
