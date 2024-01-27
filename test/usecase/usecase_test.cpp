// Copyright 2023
// Author: LH
// this is ...
#include "usecase.h"

#include <QString>
#include <QColor>

#include <generatorinterface.h>
#include <keys.h>


#include <gtest/gtest.h>

namespace  StepController_test {
class MockGenerator : public GeneratorInterface {
public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};


TEST(StepController, Trigger) {
    // key is not included in keys
    // key is included in keys, but index is not equals press number
    // key is includde in keys, and index is equals press number

//    GeneratorInterface* generator = new MockGenerator();
//    KeySequence *seq = new KeySequence(generator);
//    Usecase* contoller = new Usecase(seq, Qt::green);

//    int press_index = 0;
//    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::green);

//    press_index = 1;
//    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::green);

//    press_index = 2;
//    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::green);
//    EXPECT_EQ(contoller->CanResetContext(), true);

//    contoller->ResetContext();

//    press_index = 0;
//    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::green);

//    press_index = 1;
//    EXPECT_EQ(contoller->Presskey("C", press_index), Qt::red);

//    press_index = 2;
//    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::yellow);
//    EXPECT_EQ(contoller->CanResetContext(), false);


//    contoller->ResetContext();
//    press_index = 0;
//    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::yellow);

//    press_index = 1;
//    EXPECT_EQ(contoller->Presskey("A", press_index), Qt::yellow);

//    press_index = 2;
//    EXPECT_EQ(contoller->Presskey("B", press_index), Qt::green);
//    EXPECT_EQ(contoller->CanResetContext(), false);

//    delete contoller;
}

}  // namespace StepController_test
