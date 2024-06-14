// Copyright 2023
// Author: LH
// this is ...

#include "ledgameapplication.h"

//#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
    LedGameApplication app(argc, argv);

//    ::testing::InitGoogleTest(&argc, argv);

    app.init();

    return app.exec();
}
