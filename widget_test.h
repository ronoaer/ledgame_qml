#ifndef LEDGAME_WIDGETTEST_H
#define LEDGAME_WIDGETTEST_H

#include <QtTest/QtTest>

class WidgetTest : public QObject {
    Q_OBJECT
 public:
    WidgetTest();

 private slots:
    void Test_LedButtonLeft();
    void Test_LedButtonMiddle();
    void Test_LedButtonRight();
};

#endif // LEDGAME_WIDGETTEST_H
