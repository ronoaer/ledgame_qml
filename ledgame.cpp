// Copyright 2023
// Author: LH
// this is implementing of class LedGame

#include "ledgame.h"

#include "uicomponent/ledgameui.h"
#include "usecase/ledgameusecase.h"
#include "keysequence/generatorinterface.h"
#include "keysequence/keysequence.h"

LedGame::~LedGame() {
    delete ui_;
    delete usecase_;
}

LedGame *LedGame::NewInstance() {
    LedGame* game = new LedGame();

    if ((game == NULL) || (game->constructor() == false)) {
        delete game;
        return NULL;
    }

    return game;
}

void LedGame::Show(const QPoint p) {
    int width = ui_->width();
    int height = ui_->height();
    ui_->resize(width, height);

    int x = (p.x() - ui_->width())/2;
    int y = (p.y() - ui_->height())/2;

    ui_->move(x, y);
    ui_->Show();
}

LedGame::LedGame() {
    ui_ = NULL;
}

bool LedGame::constructor() {
    ui_ = LedGameUI::NewInstance();

    // initialize StepContoller and first step;
    QString str_initialize_keys("ABC");

    // initialize key sequence
    GeneratorInterface* key_generator =
        new KeySequenceGenerator(str_initialize_keys);

    KeySequence* key_sequence = new KeySequence(key_generator);
    usecase_ = new LedGameUsecase(key_sequence, Qt::green);

    ui_->set_usecase(usecase_);

    return true;
}
