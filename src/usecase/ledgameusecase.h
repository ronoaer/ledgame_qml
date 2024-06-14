// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_USECASE_LEDGAMEUSECASE_H
#define LEDGAME_USECASE_LEDGAMEUSECASE_H

#include "../usecase/ledgameinterface.h"

class StepInterface;
class Keys;


class LedGameUsecase : public LedGameInterface {
 public:
    explicit LedGameUsecase(Keys* keys, QColor reset_color_flag);
     virtual ~LedGameUsecase();

    virtual QColor Presskey(const QString& key, const int press_index);
    virtual bool CanResetContext();
    virtual void ResetContext();

 private:
    Keys* keys_;
    QColor reset_color_flag_;
    bool can_be_reset_;
};

#endif  // LEDGAME_USECASE_LEDGAMEUSECASE_H
