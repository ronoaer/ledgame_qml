// Copyright 2023
// Author: LH
// this is ...
#ifndef UICOMPONENT_LEDGAMEUI_H_
#define UICOMPONENT_LEDGAMEUI_H_

#include <QObject>

#include "models/ledmodel.h"
#include "models/buttonmodel.h"

class QQmlApplicationEngine;
class USInterface;

class LedGameUI : public QObject {
    Q_OBJECT

 public:
    LedGameUI(USInterface *usecase, QObject* parent=nullptr);
    virtual ~LedGameUI();

 signals:
    void updateLastLedColor(const QColor& color);

 public slots:
    void onButtonClicked(QString key);

 private:
    void initEngine();
    void initModels();

    USInterface* usecase_;

    QQmlApplicationEngine* engine_;

    QSharedPointer<LedModel> ledModel_;
    QSharedPointer<ButtonModel> buttonModel_;
};

#endif  // UICOMPONENT_LEDGAMEUI_H_
