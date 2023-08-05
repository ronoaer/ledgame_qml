// Copyright 2023
// Author: LH
// this is ...
#include "ledindicator.h"

LedIndicator::LedIndicator(QWidget* parent, QColor color) :
    QLabel(parent),
    color_(color),
    next_led_(NULL) {
    setMaximumSize(60, 40);
    setAlignment(Qt::AlignCenter);

    UpdateColor(color_, 0);
}

LedIndicator* LedIndicator::SetNextLed(LedIndicator *led) {
    next_led_ = led;

    return next_led_;
}

void LedIndicator::UpdateColor(const QColor &color, const int press_index) {
    RepaintLed(color);

    if (((press_index - 1) >= 0) && (next_led_ != NULL)) {
        next_led_->UpdateColor(color_, press_index - 1);
    }

    color_ = color;
}

QColor LedIndicator::Color() const {
    return color_;
}

void LedIndicator::onUpdateColor(QColor color, int step_index)
{
    UpdateColor(color, step_index);
}

void LedIndicator::RepaintLed(const QColor &color) {
    QPalette palette;
    palette.setColor(QPalette::Window, color);
    setAutoFillBackground(true);
    setPalette(palette);
}
