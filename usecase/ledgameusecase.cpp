// Copyright 2023
// Author: LH
// this is ...
#include "ledgameusecase.h"

#include <QPushButton>

#include "../keysequence/keysequence.h"

LedGameUsecase::LedGameUsecase(KeySequence* key_sequence,
                               const QColor reset_color_flag) :
    key_sequence_(key_sequence),
    reset_color_flag_(reset_color_flag) {
    can_be_reset_ = true;
}

LedGameUsecase::~LedGameUsecase() {
    delete key_sequence_;
}

QColor LedGameUsecase::Presskey(const QString &key, const int press_index) {
    if (press_index == 0) {
        can_be_reset_ = true;
    }

    QColor color = key_sequence_->KeyMapColor(key, press_index);

    can_be_reset_ = (reset_color_flag_ == color) && can_be_reset_;

    return color;
}

bool LedGameUsecase::CanResetContext() {
    return can_be_reset_;
}

void LedGameUsecase::ResetContext() {
    key_sequence_->ReRandomKeySequence();
}
