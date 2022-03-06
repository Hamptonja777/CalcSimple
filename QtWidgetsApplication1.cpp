#include "QtWidgetsApplication1.h"
#include <qdebug.h>
#include <QMessageBox>
#include <QStyle>


double calcVal_A = 0;
bool val_A = false;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;



QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.Display_1->setText(QString::number(calcVal_A));
	connect(ui.Button_0, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_1, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_2, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_3, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_4, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_5, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_6, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_7, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_8, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_9, &QPushButton::clicked, this, &QtWidgetsApplication1::onClicked);
	connect(ui.Button_Addition, &QPushButton::clicked, this, &QtWidgetsApplication1::MathButtonPressed);
	connect(ui.Button_Substract, &QPushButton::clicked, this, &QtWidgetsApplication1::MathButtonPressed);
	connect(ui.Button_Multiply, &QPushButton::clicked, this, &QtWidgetsApplication1::MathButtonPressed);
	connect(ui.Button_Divide, &QPushButton::clicked, this, &QtWidgetsApplication1::MathButtonPressed);
	connect(ui.Button_Reset, &QPushButton::clicked, this, &QtWidgetsApplication1::Reset);
	connect(ui.Button_Equal, &QPushButton::clicked, this, &QtWidgetsApplication1::EqualButton);

}

void QtWidgetsApplication1::onClicked()
{
	QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
	QString butval = buttonSender->text();
	QString displayVal = ui.Display_1->text();

	if ((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)) {
		ui.Display_1->setText(butval);
	}
	else {
		QString newVal = displayVal + butval;
		double dblnewValue = newVal.toDouble();
		ui.Display_1->setText(QString::number(dblnewValue, 'g', 16));
	}

	buttonSender->setProperty("clicked", true);
	buttonSender->style()->unpolish(buttonSender);
	buttonSender->style()->polish(buttonSender);

}

void QtWidgetsApplication1::MathButtonPressed() {
	divTrigger = false;
	multTrigger = false;
	addTrigger = false;
	subTrigger = false;

	QString displayVal = ui.Display_1->text();
	calcVal_A = displayVal.toDouble();
	QPushButton* buttonSender = (QPushButton*)sender();
	QString butVal = buttonSender->text();
	if (QString::compare(butVal, "/", Qt::CaseInsensitive) == 0) {
		divTrigger = true;
	}
	else if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0) {
		addTrigger = true;
	}
	else if (QString::compare(butVal, "-", Qt::CaseInsensitive) == 0) {
		subTrigger = true;
	}
	else if (QString::compare(butVal, "*", Qt::CaseInsensitive) == 0) {
		multTrigger = true;
	}
	ui.Display_1->setText("");
}


void QtWidgetsApplication1::EqualButton() {
	double result = 0.0;
	QString displayVal = ui.Display_1->text();
	double dblDisplayVal = displayVal.toDouble();
	if (addTrigger || subTrigger || multTrigger || divTrigger) {
		if (addTrigger) {
			result = calcVal_A + dblDisplayVal;
		}
		else if (subTrigger) {
			result = calcVal_A - dblDisplayVal;
		}
		else if (multTrigger) {
			result = calcVal_A * dblDisplayVal;
		}
		else if (addTrigger) {
			result = calcVal_A / dblDisplayVal;
		}
		
	}
	ui.Display_1->setText(QString::number(result));
}

void QtWidgetsApplication1::Reset() {
	ui.Display_1->setText(0);
}