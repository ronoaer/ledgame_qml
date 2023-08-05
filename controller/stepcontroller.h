// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_CONTROLLER_STEPCONTROLLER_H
#define LEDGAME_CONTROLLER_STEPCONTROLLER_H

#include "ledgameinterface.h"

class StepInterface;
class KeySequence;


class StepController : public LedGameInterface {
 public:
    explicit StepController(KeySequence* key_sequence, QColor reset_color_flag);
    virtual ~StepController();

    virtual QColor Presskey(const QString& key, const int press_index);
    virtual bool CanResetContext();
    virtual void ResetContext();

 private:
    KeySequence* key_sequence_;
    QColor reset_color_flag_;
    bool can_be_reset_;
};

#endif  // LEDGAME_CONTROLLER_STEPCONTROLLER_H
