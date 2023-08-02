// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_LEDINDICATOR_LEDINDICATOR_H_
#define LEDGAME_LEDINDICATOR_LEDINDICATOR_H_

#include <QColor>
#include <QLabel>
#include <QLayout>

class LedIndicators {
 public:
    LedIndicators(QLayout* layout, const int count);
};

class LedIndicator : public QLabel {
    Q_OBJECT
 public:
    LedIndicator(QWidget*parent, QColor color);
    ~LedIndicator() {}

    LedIndicator* SetNextLed(LedIndicator* led);

    void UpdateColor(const QColor& color, const int press_index);
    QColor Color() const;

 public slots:
    void onUpdateColor(QColor color, int press_index);

 private:
    void RepaintLed(const QColor& color);

 private:
    QColor color_;

    LedIndicator* next_led_;
};

#endif  // LEDGAME_LEDINDICATOR_LEDINDICATOR_H_
