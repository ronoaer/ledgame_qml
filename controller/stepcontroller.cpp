// Copyright 2023
// Author: LH
// this is ...
#include "stepcontroller.h"

#include <QPushButton>

#include "../keysequence/keysequence.h"

StepController::StepController(QObject *parent, KeySequence* key_sequence,
                               const QColor reset_flag) :
    QObject(parent),
    color_reset_flag_(reset_flag) {
    key_sequence_ = key_sequence;

    step_ = new StepFirst(true);
}

StepController::~StepController() {
    delete step_;
    delete key_sequence_;
}

void StepController::Trigger(const QString& key) {
    int index = step_->num_step_index();

    QColor color = key_sequence_->KeyMapColor(key, index);

    // update LedIndicator color
    Q_EMIT UpdateColor(color, index);

    step_->Walk(this, color == color_reset_flag_);
}

void StepController::ResetContext() {
    key_sequence_->ReRandomKeySequence();

    Q_EMIT this->ResetSignal();
}

void StepController::onLedButtonClicked() {
    QPushButton *pb = reinterpret_cast<QPushButton*>(sender());
    QString key = pb->text();

    Trigger(key);
}

void StepFirst::Walk(StepController *context, bool can_right) {
    StepInterface* curr_step = context->step();
    StepInterface* step = new StepMiddle(curr_step->can_rset() && can_right);

    int index = curr_step->num_step_index()+1;
    step->set_num_step_index(index);

    context->set_step(step);

    delete curr_step;
}

void StepMiddle::Walk(StepController *context, bool can_right) {
    StepInterface* curr_step = context->step();
    StepInterface* step = new StepLast(curr_step->can_rset() && can_right);

    int index = curr_step->num_step_index()+1;
    step->set_num_step_index(index);

    context->set_step(step);

    delete curr_step;
}

void StepLast::Walk(StepController *context, bool can_right) {
    StepInterface* curr_step = context->step();
    bool breset_flag = curr_step->can_rset() && can_right;

    StepInterface* step = new StepFirst(true);
    context->set_step(step);

    if (breset_flag) {
        context->ResetContext();
    }

    delete curr_step;
}
