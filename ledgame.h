// Copyright 2023
// Author: LH
// this is declare of class LedGame,
// for compositing uicomponent(LedGameUI) and usecase(LedGameUsecase)
#ifndef LEDGAME_H_
#define LEDGAME_H_

#include <QPoint>

class LedGameUI;
class LedGameUsecase;

class LedGame {
 public:
    ~LedGame();
    static LedGame *NewInstance();

    void Show(const QPoint p);

 private:
    LedGame();
    bool constructor();

    LedGameUI* ui_;
    LedGameUsecase* usecase_;
};

#endif  // LEDGAME_H_
