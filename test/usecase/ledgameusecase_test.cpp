// Copyright 2023
// Author: LH
// this is ...
#include "ledgameusecase.h"

#include <QString>
#include <QColor>

#include <generatorinterface.h>
#include <keysequence.h>


#include <gtest/gtest.h>

namespace  StepController_test {
class MockGenerator : public GeneratorInterface {
public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};


TEST(StepController, Trigger) {
    GeneratorInterface* generator = new MockGenerator();
    KeySequence *seq = new KeySequence(generator);
    LedGameUsecase* contoller = new LedGameUsecase(seq, Qt::green);

    int press_index = 0;
    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::green);

    press_index = 1;
    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::green);

    press_index = 2;
    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::green);
    EXPECT_EQ(contoller->CanResetContext(), true);

    contoller->ResetContext();

    press_index = 0;
    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::green);

    press_index = 1;
    EXPECT_EQ(contoller->Presskey("C", press_index), Qt::red);

    press_index = 2;
    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::yellow);
    EXPECT_EQ(contoller->CanResetContext(), false);


    contoller->ResetContext();
    press_index = 0;
    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::yellow);

    press_index = 1;
    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::yellow);

    press_index = 2;
    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::green);
    EXPECT_EQ(contoller->CanResetContext(), false);

    delete contoller;
}

}  // namespace StepController_test
