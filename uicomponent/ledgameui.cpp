// Copyright 2023
// Author: LH
// this is ...
#include "ledgameui.h"

#include <QRandomGenerator>
#include <QGridLayout>
#include <QQuickView>
#include <QObject>
#include <QQuickItem>

#include <QDebug>

const int LedCount = 3;

LedGameUI::LedGameUI()
    : QObject(NULL) {
    num_press_index_ = 0;

    ResetButtonsText();
}

LedGameUI *LedGameUI::NewInstance() {
    LedGameUI* ui = new LedGameUI();
    if (ui == NULL) {
        delete ui;

        return NULL;
    }

    return ui;
}

LedGameUI::~LedGameUI() {
}

void LedGameUI::set_usecase(LedGameInterface *interface) {
    usecase_ = interface;
}

LedGameInterface *LedGameUI::usecase() {
    return usecase_;
}

void LedGameUI::onButtonClicked(QString key) {
    QColor newest_color = usecase_->Presskey(key, num_press_index_);
    num_press_index_++;

    // for qml color
    QString str_color = "yellow";
    if (newest_color == Qt::green)  {
        str_color = "green";
    } else if  (newest_color == Qt::red) {
        str_color = "red";
    }

    Q_EMIT UpdateLedsColor(num_press_index_, str_color);

    ResetContext(&num_press_index_, LedCount);
}

void LedGameUI::initializeButtons() {
    ResetButtonsText();
}

void LedGameUI::ResetContext(int* press_index, const int max_count) {
    if (*press_index < max_count) {
        return;
    }

    *press_index = 0;

    if (!usecase_->CanResetContext()) {
        return;
    }

    // update UI.....
    ResetButtonsText();

    // update usecase....
    usecase_->ResetContext();
}

void LedGameUI::ResetButtonsText() {
    int count = LedCount;
    int seed = QRandomGenerator::global()->bounded(count);

    for (int i = 0; i < count; i++) {
        QString key = IndexToText(seed);

        Q_EMIT UpdateButtonText(i, key);

        seed++;
        seed = seed % count;
    }
}

QColor LedGameUI::IndexToColor(const int index) {
    switch (index) {
    case 0:
        return Qt::red;

    case 1:
        return Qt::yellow;

    case 2:
        return Qt::green;
    }

    return Qt::green;
}


QString LedGameUI::IndexToText(const int index) {
    switch (index) {
    case 0:
        return "A";

    case 1:
        return "B";

    case 2:
        return "C";
    }

    return "A";
}
