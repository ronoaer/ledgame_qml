// Copyright 2023
// Author: LH
// this is ...
#include "ledgameui.h"
#include "../keysequence/generatorinterface.h"
#include "../keysequence/keysequence.h"
#include "../usecase/ledgameusecase.h"

#include "gtest/gtest.h"

namespace ledgameui_test {
class MockGenerator : public GeneratorInterface {
 public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};


    TEST(LedGameUI, NewInstance) {
        LedGameUI* lg_ui = LedGameUI::NewInstance();
        EXPECT_TRUE(lg_ui != NULL);

        KeySequence* sequence = new KeySequence(new MockGenerator());
        LedGameUsecase* usecase = new LedGameUsecase(sequence, Qt::green);
        lg_ui->set_usecase(usecase);

       // lg_ui->UpdateButtonText()


        // the key is ABB
        // the index of button is A B C
        // the color (led1..3) (Qt::red, Qt::red, Qt::red)
        // the index of press is A B B

        delete usecase;
        delete lg_ui;
    }
}  // namespace ledgameui_test
