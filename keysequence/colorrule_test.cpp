// Copyright 2023
// Author: LH
// this is ...
#include "colorrule.h"

#include <QString>

#include "gtest/gtest.h"

namespace charSequencecenerator_test {

TEST(ColorRule, HandleRequest) {
    ColorRule* yellow_rule = new YellowRule(NULL);
    ColorRule* green_rule = new GreenRule(yellow_rule);
    ColorRule* red_rule = new RedRule(green_rule);


    int press_index = 0;
    int key_index = 0;
    ColorRequest *request = new ColorRequest(press_index, key_index);
    QColor color = red_rule->HandleRequest(request);
    delete request;
    EXPECT_EQ(color, Qt::green);

    press_index = -1;
    key_index = -1;
    request = new ColorRequest(press_index, key_index);
    color = red_rule->HandleRequest(request);
    delete request;
    EXPECT_EQ(color, Qt::red);

    press_index = -1;
    key_index = 0;
    request = new ColorRequest(press_index, key_index);
    color = red_rule->HandleRequest(request);
    delete request;
    EXPECT_EQ(color, Qt::red);

    press_index = 1;
    key_index = 0;
    request = new ColorRequest(press_index, key_index);
    color = red_rule->HandleRequest(request);
    delete request;
    EXPECT_EQ(color, Qt::yellow);

    delete yellow_rule;
    delete green_rule;
    delete red_rule;
}

}  // namespace charSequencecenerator_test
