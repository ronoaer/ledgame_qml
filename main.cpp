// Copyright 2023
// Author: LH
// this is ...
#include "ledgame.h"
#include "uicomponent/ledgameui.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &a, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);


    LedGame* ld = LedGame::NewInstance();

    int ret = 0;
    if (ld != NULL) {
        engine.rootContext()->setContextProperty("LedGameUI", (QObject*)ld->ui());
        engine.load(url);

        if (RUN_ALL_TESTS() == 1) {
            return 1;
        }

        ret = a.exec();

        delete ld;
    }

    return ret;
}
