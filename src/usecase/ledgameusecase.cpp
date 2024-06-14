// Copyright 2023
// Author: LH
// this is ...
#include "ledgameusecase.h"
#include "../key/keys.h"

#include <QDebug>

LedGameUsecase::LedGameUsecase(Keys* key_sequence,
                               const QColor reset_color_flag) :


    keys_(key_sequence),
    reset_color_flag_(reset_color_flag) {

    can_be_reset_ = true;
}

LedGameUsecase::~LedGameUsecase() {
    delete keys_;
}

QColor LedGameUsecase::Presskey(const QString &key, const int press_index) {
    if (press_index == 0) {
        can_be_reset_ = true;
    }

    QColor color = keys_->keyMapColor(key, press_index);


    can_be_reset_ = (reset_color_flag_ == color) && can_be_reset_;

    return color;
}

bool LedGameUsecase::CanResetContext() {
    return can_be_reset_;
}

void LedGameUsecase::ResetContext() {
    keys_->reRandomKeySequence();
}
