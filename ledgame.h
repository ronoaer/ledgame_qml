#ifndef LEDGAME_LEDGAME_H_
#define LEDGAME_LEDGAME_H_

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

#endif // LEDGAME_LEDGAME_H_
