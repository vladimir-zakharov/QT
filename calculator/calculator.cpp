#include<QComboBox>
#include<QLayout>
#include<QLabel>
#include<QSpinBox>

#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    resize(400, 40);
    move(500, 300);

    QLayout *layout = new QHBoxLayout(this);
    first = new QSpinBox(this);
    operation = new QComboBox(this);
    second = new QSpinBox(this);
    result = new QLabel(this);
    QLabel *equal = new QLabel(this);

    first->setMaximum(999);
    first->setMinimum(-999);

    second->setMaximum(999);
    second->setMinimum(-999);

    result->setNum(0);
    result->setStyleSheet("QLabel {background-color : white}");
    result->setMaximumHeight(25);

    equal->setText("=");
    equal->setMaximumWidth(10);

    operation->addItem("+", 0);
    operation->addItem("-", 1);
    operation->addItem("*", 2);

    layout->addWidget(first);
    layout->addWidget(operation);
    layout->addWidget(second);
    layout->addWidget(equal);
    layout->addWidget(result);

    connect(operation, SIGNAL(activated(QString)), this, SLOT(calculate(QString)));
    connect(first, SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect(second, SIGNAL(valueChanged(int)), this, SLOT(update()));
}

void Calculator::calculate(QString string) {
    if (string == "+") {
        result->setNum(first->value() + second->value());
    }
    if (string == "-") {
        result->setNum(first->value() - second->value());
    }
    if (string == "*") {
        result->setNum(first->value() * second->value());
    }
}

void Calculator::update() {
    if (operation->currentIndex() == 0) {
        result->setNum(first->value() + second->value());
    }
    if (operation->currentIndex() == 1) {
        result->setNum(first->value() - second->value());
    }
    if (operation->currentIndex() == 2) {
        result->setNum(first->value() * second->value());
    }
}
