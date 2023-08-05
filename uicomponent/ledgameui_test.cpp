#include "ledgameui.h"
#include "../keysequence/generatorinterface.h"
#include "../keysequence/keysequence.h"
#include "../usecase/ledgameusecase.h"
#include "ledindicator.h"

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

        QList<QPushButton*> buttons = lg_ui->led_buttons();
        buttons[0]->setText("A");
        buttons[1]->setText("B");
        buttons[2]->setText("C");

        QList<LedIndicator*> leds = lg_ui->led_indicators();

        // the key is ABB
        // the index of button is A B C
        // the color (led1..3) (Qt::red, Qt::red, Qt::red)
        // the index of press is A B B
        buttons[0]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::green);


        buttons[1]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::green);
        EXPECT_EQ(leds[1]->Color(), Qt::green);

        buttons[1]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::green);
        EXPECT_EQ(leds[1]->Color(), Qt::green);
        EXPECT_EQ(leds[0]->Color(), Qt::green);


        buttons[0]->setText("A");
        buttons[1]->setText("B");
        buttons[2]->setText("C");

        // the key is ABB
        // the index of button is A B C
        // the color (led1..3) (Qt::green, Qt::green, Qt::green)
        // the index of press is C C C
        buttons[2]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::red);
        EXPECT_EQ(leds[1]->Color(), Qt::green);
        EXPECT_EQ(leds[0]->Color(), Qt::green);

        buttons[2]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::red);
        EXPECT_EQ(leds[1]->Color(), Qt::red);
        EXPECT_EQ(leds[0]->Color(), Qt::green);

        buttons[2]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::red);
        EXPECT_EQ(leds[1]->Color(), Qt::red);
        EXPECT_EQ(leds[0]->Color(), Qt::red);

        // the key is ABB
        // the index of button is A B C
        // the color (led1..3) (Qt::red, Qt::red, Qt::red)
        // the index of press is B A B
        buttons[1]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::yellow);
        EXPECT_EQ(leds[1]->Color(), Qt::red);
        EXPECT_EQ(leds[0]->Color(), Qt::red);

        buttons[0]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::yellow);
        EXPECT_EQ(leds[1]->Color(), Qt::yellow);
        EXPECT_EQ(leds[0]->Color(), Qt::red);

        buttons[1]->clicked();
        EXPECT_EQ(leds[2]->Color(), Qt::green);
        EXPECT_EQ(leds[1]->Color(), Qt::yellow);
        EXPECT_EQ(leds[0]->Color(), Qt::yellow);

        delete usecase;
        delete lg_ui;
    }
}
