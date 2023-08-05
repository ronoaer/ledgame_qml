#ifndef LEDGAME_LEDGAME_H_
#define LEDGAME_LEDGAME_H_

class LedGameUI;
class StepController;

class LedGame {
public:
    ~LedGame();
    static LedGame *NewInstance();

    void Show();

private:
    LedGame();
    bool constructor();

    LedGameUI* ui_;
    StepController* controller_;
};

#endif // LEDGAME_LEDGAME_H_
