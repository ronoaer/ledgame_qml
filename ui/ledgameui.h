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
class LedGameInterface;

class LedGameUI : public QObject {
    Q_OBJECT

 public:
    static LedGameUI* NewInstance();
    ~LedGameUI();

    void set_usecase(LedGameInterface *interface);
    LedGameInterface *usecase();

 signals:
    void UpdateLedsColor(const int press_index, const QString color);
    void UpdateButtonText(const int index, const QString& key);

 public slots:
    void onButtonClicked(QString key);

 private:
    void initEngine();
    void initModels();

    LedGameInterface* usecase_;

    QQmlApplicationEngine* engine_;

    QSharedPointer<LedModel> ledModel_;
    QSharedPointer<ButtonModel> buttonModel_;

    LedGameUI();

    void ResetContext(int* press_index, const int max_count);
    void ResetButtonsText();

    // for initialize button and label
    QString IndexToText(const int index);
    QString IndexToColorString(const int index);


    int num_press_index_;
};

#endif  // UICOMPONENT_LEDGAMEUI_H_
