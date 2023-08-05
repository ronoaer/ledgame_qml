#include "ledgame.h"

#include "uicomponent/ledgameui.h"
#include "controller/stepcontroller.h"
#include "keysequence/generatorinterface.h"
#include "keysequence/keysequence.h"

LedGame::~LedGame() {
    delete ui_;
    delete controller_;
}

LedGame *LedGame::NewInstance() {
    LedGame* game = new LedGame();

    if ((game == NULL) || (game->constructor() == false)) {
        delete game;
        return NULL;
    }

    return game;
}

void LedGame::Show() {
    if (ui_ == NULL) {
        return;
    }

    ui_->Show();
}

LedGame::LedGame() {
}

bool LedGame::constructor() {
    ui_ = LedGameUI::NewInstance();
    // initialize StepContoller and first step;
    QString str_initialize_keys("ABC");
    // initialize key sequence
    GeneratorInterface* key_generator = new KeySequenceGenerator(str_initialize_keys);
    KeySequence* key_sequence = new KeySequence(key_generator);
    controller_ = new StepController(key_sequence, Qt::green);

    ui_->set_usecase(controller_);

    return true;
}
