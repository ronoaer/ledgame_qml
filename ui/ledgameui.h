// Copyright 2023
// Author: LH
// this is ...
#ifndef UICOMPONENT_LEDGAMEUI_H_
#define UICOMPONENT_LEDGAMEUI_H_

#include <QObject>

<<<<<<< HEAD
#include "models/ledmodel.h"
#include "models/buttonmodel.h"

class QQmlApplicationEngine;
class USInterface;
=======
class LedGameInterface;
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a

class LedGameUI : public QObject {
    Q_OBJECT

 public:
<<<<<<< HEAD
    LedGameUI(USInterface *usecase, QObject* parent=nullptr);
    virtual ~LedGameUI();

 signals:
    void updateLastLedColor(const QColor& color);
=======
    static LedGameUI* NewInstance();
    ~LedGameUI();

    void set_usecase(LedGameInterface *interface);
    LedGameInterface *usecase();

 signals:
    void UpdateLedsColor(const int press_index, const QString color);
    void UpdateButtonText(const int index, const QString& key);
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a

 public slots:
    void onButtonClicked(QString key);

 private:
<<<<<<< HEAD
    void initEngine();
    void initModels();

    USInterface* usecase_;

    QQmlApplicationEngine* engine_;

    QSharedPointer<LedModel> ledModel_;
    QSharedPointer<ButtonModel> buttonModel_;
=======
    LedGameUI();

    void ResetContext(int* press_index, const int max_count);
    void ResetButtonsText();

    // for initialize button and label
    QString IndexToText(const int index);
    QString IndexToColorString(const int index);

    LedGameInterface* usecase_;

    int num_press_index_;
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
};

#endif  // UICOMPONENT_LEDGAMEUI_H_
