// Copyright 2023
// Author: LH
// this is unit-test of class LedGame,
#include "ledgame.h"

#include "gtest/gtest.h"

namespace ledgame_test {
    TEST(LedGame, NewInstance) {
        LedGame* lg = LedGame::NewInstance();

        EXPECT_TRUE(lg != NULL);
        delete lg;
    }
}
