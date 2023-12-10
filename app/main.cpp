// Copyright 2023
// Author: LH
// this is ...
#include "../usecase/ledgame.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/ui/qml/main.qml"));
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

        ret = a.exec();

        delete ld;
    }

    return ret;
}
