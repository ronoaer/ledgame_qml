// Copyright 2023
// Author: LH
// this is ...
#include "ledgameapplication.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>

int main(int argc, char *argv[]) {
    LedGameApplication app(argc, argv);

    app.init();

    return app.exec();
}
