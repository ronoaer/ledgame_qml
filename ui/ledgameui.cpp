// Copyright 2023
// Author: LH
// this is ...
#include "ledgameui.h"

#include "../usecase/usinterface.h"

#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QQmlContext>
#include <QQuickStyle>

#include <QObject>

#include <QDebug>

const int LedCount = 3;


LedGameUI::LedGameUI(USInterface *usecase, QObject *parent) :
    usecase_(usecase), QObject(parent)
{
    initEngine();
    initModels();
}

LedGameUI::~LedGameUI() {
    if (engine_) {
        QObject::disconnect(engine_, 0, 0, 0);
        delete engine_;
    }
}


void LedGameUI::onButtonClicked(QString key)
{
    QColor newest_color = usecase_->GetColorByKey(key);

    Q_EMIT updateLastLedColor(newest_color);
    usecase_->ResetContext();
}

void LedGameUI::initEngine()
{
    QQuickStyle::setStyle("Basic");

    engine_ = new QQmlApplicationEngine;
    const QUrl url(QStringLiteral("qrc:/ui/qml/main.qml"));
    QObject::connect(
        engine_, &QQmlApplicationEngine::objectCreated, this,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    initModels();

    engine_->rootContext()->setContextProperty("LedGameUI", this);

    engine_->load(url);
}

void LedGameUI::initModels()
{
    buttonModel_.reset(new ButtonModel(this));
    engine_->rootContext()->setContextProperty("ButtonModel", buttonModel_.get());

    ledModel_.reset(new LedModel(this));
    engine_->rootContext()->setContextProperty("LedModel", ledModel_.get());
}
