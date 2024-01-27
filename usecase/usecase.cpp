// Copyright 2023
// Author: LH
// this is ...
#include "usecase.h"
#include "../key/keys.h"

#include <QDebug>

Usecase::Usecase(Keys* keys,
                               const QColor reset_color_flag) :


    keys_(keys),
    reset_color_flag_(reset_color_flag) {

    resetRound();
}

Usecase::~Usecase() {
    delete keys_;
}

QColor Usecase::GetColorByKey(const QString &key) {
    KeyPosition kp = keys_->KeyIndex(key, press_numbers_);

    QColor color = getColorByPosition(kp);

    updateResetCondition(color);

    return color;
}

void Usecase::ResetContext() {
    if (canBeReset()) {
        keys_->ReRandomKeySequence();
        resetRound();
    }
}

QColor Usecase::mapPositionToColor(const KeyPosition &kp)
{
    QColor color(Qt::red);
    if (kp == KeyPosition::)
}

void Usecase::updateResetCondition(const QColor &curColor)
{
    colors_equal_flag_ &= (reset_color_flag_ == curColor);
    press_numbers_++;
}

bool Usecase::canBeReset()
{
    if (roundEnd() && colors_equal_flag_) {
        return true;
    }

    if (roundEnd()) {
        resetRound();
    }

    return false;
}

bool Usecase::roundEnd()
{
    return press_numbers_ == 3;
}

void Usecase::resetRound()
{
    press_numbers_ = 0;
    colors_equal_flag_ = true;
}
