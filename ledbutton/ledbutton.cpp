// Copyright 2023
// Author: LH
// this is ...
#include "ledbutton.h"

LedButton::LedButton(QWidget* parent, const int value) :
    QPushButton(parent) {
    setMaximumSize(60, 40);
    SetLimitText(value);
}

void LedButton::SetLimitText(const int value) {
    setText(IndexToText(value));
}

QString LedButton::IndexToText(const int index) {
    switch (index) {
    case 0:
        return "A";

    case 1:
        return "B";

    case 2:
        return "C";
    }

    return "A";
}


