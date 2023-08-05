#include "ledgameui.h"

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

void LedGameUI::onButtonClicked() {
    QPushButton *pb = reinterpret_cast<QPushButton*>(sender());
    QString key = pb->text();

    QColor newest_color = usecase_->Presskey(key, num_press_index_);
    num_press_index_++;

    UpdateLedsColor(newest_color, num_press_index_);
    ResetContext(num_press_index_, LedCount);
}

bool LedGameUI::constructor() {
    bool result(true);

    int count = LedCount;

    // init buttons & labes;
    QGridLayout *layout = new QGridLayout;

    int seed = QRandomGenerator::global()->bounded(count);
    for (int i = 0; i < count; i++) {
        // initialize labels
        QLabel* led = new QLabel(this);
        led->setFixedSize(QSize(40, 40));
        led->setText("Led " + QString::number(i+1));
        UpdateLedColor(led, IndexToColor(i));

        layout->addWidget(led, 0, i);
        led_indicators_.push_back(led);

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

void LedGameUI::ResetContext(int &press_index, const int max_count) {
    if (press_index < max_count) {
        return;
    }

    press_index = 0;

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


void LedGameUI::UpdateLedColor(QLabel* led, const QColor color) {
    QPalette palette;
    palette.setColor(QPalette::Window, color);

    led->setAutoFillBackground(true);
    led->setPalette(palette);
}

void LedGameUI::UpdateLedsColor(const QColor color, const int press_index) {
    QColor newest_color = color;

    int need_update_count = 0;
    for (int i=led_indicators_.size() - 1; i >= 0; i--) {
        if (need_update_count >= press_index) {
            return;
        }

        QColor old_color = led_indicators_[i]->palette().color(QPalette::Window);
        UpdateLedColor(led_indicators_[i], newest_color);
        newest_color = old_color;

        need_update_count++;
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
