// Copyright 2023
// Author: LH
// this is ...
#include "stepcontroller.h"

#include <QPushButton>

#include "../keysequence/keysequence.h"

StepController::StepController(KeySequence* key_sequence,
                               const QColor reset_color_flag) :
    key_sequence_(key_sequence),
    reset_color_flag_(reset_color_flag) {
    can_be_reset_ = true;
}

StepController::~StepController() {
    delete key_sequence_;
}

QColor StepController::Presskey(const QString &key, const int press_index) {
    if (press_index == 0) {
        can_be_reset_ = true;
    }

    QColor color = key_sequence_->KeyMapColor(key, press_index);

    can_be_reset_ = (reset_color_flag_ == color) && can_be_reset_;

    return color;
}

bool StepController::CanResetContext() {
    return can_be_reset_;
}

void StepController::ResetContext() {
    key_sequence_->ReRandomKeySequence();
}
