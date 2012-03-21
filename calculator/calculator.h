#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>

class Calculator : public QWidget
{
public:
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);

private:
    QLabel *result;
    QSpinBox *first;
    QSpinBox *second;
    QComboBox *operation;

private slots:
   void calculate(QString string);
   void update();
};

#endif // CALCULATOR_H
