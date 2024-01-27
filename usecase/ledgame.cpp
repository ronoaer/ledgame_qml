// Copyright 2023
// Author: LH
// this is implementing of class LedGame

#include "ledgame.h"

#include "../ui/ledgameui.h"
#include "ledgameusecase.h"
#include "../key/generatorinterface.h"
#include "../key/keysequence.h"

LedGame::~LedGame() {
    delete ui_;
    delete usecase_;
}

LedGame *LedGame::NewInstance() {
    LedGame* game = new LedGame();

    if ((game == nullptr) || (game->constructor() == false)) {
        delete game;
        return nullptr;
    }

    return game;
}

LedGame::LedGame() {
    ui_ = nullptr;
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
