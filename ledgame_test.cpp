#include "ledgame.h"

#include "gtest/gtest.h"

namespace ledgame_test {
    TEST(LedGame, NewInstance) {
        LedGame* lg = LedGame::NewInstance();

        EXPECT_TRUE(lg != NULL);
        delete lg;
    }
}
