// Copyright 2023
// Author: LH
// this is declare of class LedGame,
// for compositing uicomponent(LedGameUI) and usecase(LedGameUsecase)
#ifndef LEDGAME_H_
#define LEDGAME_H_

class LedGameUI;
class LedGameUsecase;

class LedGame {
 public:
    ~LedGame();
    static LedGame *NewInstance();

    void Show();

 private:
    LedGame();
    bool constructor();

    LedGameUI* ui_;
    LedGameUsecase* usecase_;
};

#endif  // LEDGAME_H_
