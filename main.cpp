// Copyright 2023
// Author: LH
// this is ...
#include "ledgame.h"

#include <QApplication>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);

    LedGame* ld = LedGame::NewInstance();

    int ret = 0;
    if(ld != NULL) {
        ld->Show();

        if (RUN_ALL_TESTS() == 1) {
            return 1;
        }

        ret = a.exec();

        delete ld;
    }

    return ret;
}
