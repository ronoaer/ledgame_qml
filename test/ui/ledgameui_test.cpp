// Copyright 2023
// Author: LH
// this is ...
#include <ledgameui.h>
#include <generatorinterface.h>
#include <keys.h>
#include <usecase.h>
#include <keysequence.h>
#include <ledgameusecase.h>

#include <QSignalSpy>

#include <gtest/gtest.h>

namespace ledgameui_test {
class MockGenerator : public GeneratorInterface {
 public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};


    TEST(LedGameUI, NewInstance) {
    QString str_red(QColor(Qt::red).name());
    QString str_yello(QColor(Qt::yellow).name());
    QString str_green(QColor(Qt::green).name());

        // LedGameUI* lg_ui = LedGameUI::NewInstance();
        // EXPECT_TRUE(lg_ui != NULL);

        // Keys* sequence = new Keys(new MockGenerator());
        // LedGameUsecase* usecase = new LedGameUsecase(sequence, Qt::green);
        // lg_ui->set_usecase(usecase);

        // QSignalSpy spy_led_color(lg_ui, &LedGameUI::UpdateLedsColor);
        // QSignalSpy spy_btn_title(lg_ui, &LedGameUI::UpdateButtonText);

        // // index is right
        // lg_ui->onButtonClicked("A");
        // lg_ui->onButtonClicked("B");
        // lg_ui->onButtonClicked("B");

        // QVariantList arguments = spy_led_color.first();
        // EXPECT_EQ(1, arguments.at(0));
        // EXPECT_EQ(str_green, arguments.at(1));

        // spy_led_color.removeFirst();
        // arguments = spy_led_color.first();
        // EXPECT_EQ(2, arguments.at(0));
        // EXPECT_EQ(str_green, arguments.at(1));

        // spy_led_color.removeFirst();
        // arguments = spy_led_color.first();
        // EXPECT_EQ(3, arguments.at(0));
        // EXPECT_EQ(str_green, arguments.at(1));
        // spy_led_color.clear();


        // EXPECT_EQ(3, spy_btn_title.count());
        // spy_btn_title.clear();

        // // index is not right
        // lg_ui->onButtonClicked("B");
        // lg_ui->onButtonClicked("C");
        // lg_ui->onButtonClicked("A");
        // arguments = spy_led_color.first();
        // EXPECT_EQ(1, arguments.at(0));
        // EXPECT_EQ(str_yello, arguments.at(1));

        // spy_led_color.removeFirst();
        // arguments = spy_led_color.first();
        // EXPECT_EQ(2, arguments.at(0));
        // EXPECT_EQ(str_red, arguments.at(1));

        // spy_led_color.removeFirst();
        // arguments = spy_led_color.first();
        // EXPECT_EQ(3, arguments.at(0));
        // EXPECT_EQ(str_yello, arguments.at(1));
        // spy_led_color.clear();

        // EXPECT_EQ(0, spy_btn_title.count());
        // spy_btn_title.clear();


        // delete usecase;
        // delete lg_ui;
    }
}  // namespace ledgameui_test
