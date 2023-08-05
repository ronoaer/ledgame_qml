// Copyright 2023
// Author: LH
// this is ...
#include "ledgameui.h"

#include "ledindicator.h"

#include <QRandomGenerator>
#include <QGridLayout>

const int LedCount = 3;

LedGameUI::LedGameUI()
    : QWidget(NULL, Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint) {
    num_press_index_ = 0;
}

LedGameUI *LedGameUI::NewInstance() {
    LedGameUI* ui = new LedGameUI();
    if ((ui == NULL) || (ui->constructor() == false)) {
        delete ui;

        return NULL;
    }

    return ui;
}

LedGameUI::~LedGameUI() {
}

void LedGameUI::Show() {
    QWidget::show();
    setMinimumSize(QSize(400, 300));
}

void LedGameUI::set_usecase(LedGameInterface *interface) {
    usecase_ = interface;
}

LedGameInterface *LedGameUI::usecase() {
    return usecase_;
}

QList<LedIndicator *> LedGameUI::led_indicators() {
    return led_indicators_;
}

QList<QPushButton *> LedGameUI::led_buttons() {
    return led_buttons_;
}

void LedGameUI::onButtonClicked() {
    QPushButton *pb = reinterpret_cast<QPushButton*>(sender());
    QString key = pb->text();

    QColor newest_color = usecase_->Presskey(key, num_press_index_);
    num_press_index_++;

    UpdateLedsColor(newest_color, num_press_index_);
    ResetContext(&num_press_index_, LedCount);
}

bool LedGameUI::constructor() {
    bool result(true);

    int count = LedCount;

    // init buttons & labes;
    QGridLayout *layout = new QGridLayout;

    int seed = QRandomGenerator::global()->bounded(count);
    LedIndicator* prev = NULL;

    for (int i = 0; i < count; i++) {
        // initialize labels
        LedIndicator* led = new LedIndicator(this, IndexToColor(seed));
        led->setText("Led " + QString::number(i+1));
        led->SetNextLed(prev);
        layout->addWidget(led, 0, i);
        led_indicators_.push_back(led);
        prev = led;

        // initialize buttons
        QPushButton* button = new QPushButton(this);
        button->setFixedSize(QSize(60, 40));
        button->setText(IndexToText(seed));

        layout->addWidget(button, 1, i);
        connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
        led_buttons_.push_back(button);

        seed++;
        seed = seed % count;
    }

    setLayout(layout);

    return result;
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
    int count = led_buttons_.size();
    int seed = QRandomGenerator::global()->bounded(count);

    for (int i = 0; i < count; i++) {
        led_buttons_[i]->setText(IndexToText(seed));

        seed++;
        seed = seed % count;
    }
}

void LedGameUI::UpdateLedsColor(const QColor color, const int press_index) {
    int size = led_indicators_.size();
    if (size == 0) {
        return;
    }

    led_indicators_[size-1]->UpdateColor(color, press_index);
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
