#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QCheckBox>
#include <QTime>

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QCheckBox *gTime;
    int delta;

private slots:
    void newTime(bool state);
};

#endif
