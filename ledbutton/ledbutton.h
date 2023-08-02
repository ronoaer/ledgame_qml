// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_LEDBUTTON_LEDBUTTON_H_
#define LEDGAME_LEDBUTTON_LEDBUTTON_H_

#include <QPushButton>


class LedButton : public QPushButton {
 public:
    explicit LedButton(QWidget* parent, const int value);

    void SetLimitText(const int value);

 private:
    QString IndexToText(const int value);
};

#endif  // LEDGAME_LEDBUTTON_LEDBUTTON_H_
