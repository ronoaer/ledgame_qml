// Copyright 2023
// Author: LH
// this is ...

#include "ledgameapplication.h"

int main(int argc, char *argv[]) {
    LedGameApplication app(argc, argv);

    app.init();

    return app.exec();
}
