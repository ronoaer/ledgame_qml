// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_USECASE_LEDGAMEUSECASE_H
#define LEDGAME_USECASE_LEDGAMEUSECASE_H

#include "usinterface.h"

class StepInterface;
class Keys;
class KeyPosition;


class Usecase : public USInterface {
 public:
    explicit Usecase(Keys* keys, QColor reset_color_flag);
    virtual ~Usecase();

    virtual QColor GetColorByKey(const QString& key) override;
    virtual void ResetContext() override;

 private:
    QColor mapPositionToColor(const KeyPosition& kp);
    void updateResetCondition(const QColor& curColor);
    bool canBeReset();
    bool roundEnd();
    void resetRound();

    Keys* keys_;
    QColor reset_color_flag_;
    bool colors_equal_flag_;
    int press_numbers_;
};

#endif  // LEDGAME_USECASE_LEDGAMEUSECASE_H
