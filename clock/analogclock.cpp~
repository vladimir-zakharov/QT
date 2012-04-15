 #include <QtGui>

 #include "analogclock.h"
 #include <QCheckBox>
 #include <QTime>

 AnalogClock::AnalogClock(QWidget *parent)
     : QWidget(parent)
 {
     QTimer *timer = new QTimer(this);
     gTime = new QCheckBox("Greenwich time", this);
     connect(gTime, SIGNAL(clicked(bool)), this, SLOT(newTime(bool)));
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     timer->start(1000);
     delta = 0;

     setWindowTitle(tr("Analog Clock"));
     setMinimumSize(350, 200);
 }

 void AnalogClock::newTime(bool state) {
     if (!state) {
        delta = 0;
     } else {
        delta = 4;
     }
 }

 void AnalogClock::paintEvent(QPaintEvent *)
 {
     static const QPoint hourHand[7] = {
         QPoint(1, 3),
         QPoint(-1, 3),
         QPoint(-1, -40),
         QPoint(-3, -40),
         QPoint(0, -45),
         QPoint(3, -40),
         QPoint(1, -40)
     };
     static const QPoint minuteHand[7] = {
         QPoint(1, 3),
         QPoint(-1, 3),
         QPoint(-1, -70),
         QPoint(-3, -70),
         QPoint(0, -75),
         QPoint(3, -70),
         QPoint(1, -70)
     };
     static const QPoint secHand[7] = {
         QPoint(1, 3),
         QPoint(-1, 3),
         QPoint(-1, -80),
         QPoint(-3, -80),
         QPoint(0, -85),
         QPoint(3, -80),
         QPoint(1, -80)
     };

     QTime time = QTime::currentTime();
     time = time.addSecs(-delta * 3600);

     QColor secColor(255, 0, 0);
     QColor minuteColor(55, 200, 200, 191);
     QColor hourColor(0, 64, 63);

     int side = qMin(width() - 150 , height());
     QPainter painter(this);
     painter.setRenderHint(QPainter::Antialiasing);
     painter.translate((width() - 150) / 2, height() / 2);
     painter.scale(side / 200.0, side / 200.0);

     gTime->move(width() - 150, height() / 2 - 10);

     painter.setPen(Qt::NoPen);
     painter.setBrush(hourColor);

     painter.save();
     painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
     painter.drawConvexPolygon(hourHand, 7);
     painter.restore();

     painter.setPen(hourColor);

     for (int i = 0; i < 12; ++i) {
         painter.drawLine(88, 0, 96, 0);
         painter.rotate(30.0);
     }

     painter.setPen(Qt::NoPen);
     painter.setBrush(minuteColor);

     painter.save();
     painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
     painter.drawConvexPolygon(minuteHand, 7);
     painter.restore();

     painter.setPen(minuteColor);

     for (int j = 0; j < 60; ++j) {
         if ((j % 5) != 0)
             painter.drawLine(92, 0, 96, 0);
         painter.rotate(6.0);
     }

     painter.setPen(Qt::NoPen);
     painter.setBrush(secColor);
     painter.save();
     painter.rotate(6.0 * (time.minute() + time.second()));
     painter.drawConvexPolygon(secHand, 7);
     painter.restore();

 }
