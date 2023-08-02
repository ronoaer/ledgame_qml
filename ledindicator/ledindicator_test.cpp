// Copyright 2023
// Author: LH
// this is ...
#include "ledindicator.h"

#include "gtest/gtest.h"

namespace ledinicator_test {
    TEST(LedIndicatorFunctionTest, UpdateColor) {
            LedIndicator* led1 = new LedIndicator(NULL, Qt::yellow);
            LedIndicator* led2  = new LedIndicator(NULL, Qt::red);
            LedIndicator* led3 = new LedIndicator(NULL, Qt::yellow);

            led3->SetNextLed(led2)->SetNextLed(led1);

            // led3 always
            led3->UpdateColor(Qt::green, 0);
            EXPECT_EQ(led3->Color(), Qt::green);
            EXPECT_EQ(led2->Color(), Qt::red);
            EXPECT_EQ(led1->Color(), Qt::yellow);

            led3->UpdateColor(Qt::red, 1);
            EXPECT_EQ(led3->Color(), Qt::red);
            EXPECT_EQ(led2->Color(), Qt::green);
            EXPECT_EQ(led1->Color(), Qt::yellow);

            led3->UpdateColor(Qt::yellow, 2);
            EXPECT_EQ(led3->Color(), Qt::yellow);
            EXPECT_EQ(led2->Color(), Qt::red);
            EXPECT_EQ(led1->Color(), Qt::green);

            // next_led_ is empty
            led3->UpdateColor(Qt::red, 3);
            EXPECT_EQ(led3->Color(), Qt::red);
            EXPECT_EQ(led2->Color(), Qt::yellow);
            EXPECT_EQ(led1->Color(), Qt::red);

            delete led3;
            delete led2;
            delete led1;
    }
}  // namespace ledinicator_test
