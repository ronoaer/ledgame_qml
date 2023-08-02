#include "widget.h"
#include "ui_widget.h"

#include <QRandomGenerator>
#include <QGridLayout>

#include "ledbutton/ledbutton.h"
#include "ledindicator/ledindicator.h"
#include "controller/stepcontroller.h"
#include "keysequence/generatorinterface.h"
#include "keysequence/keysequence.h"

const int LedCount = 3;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // initialize StepContoller and first step;
    QString str_initialize_keys("ABC");
    // initialize key sequence
    GeneratorInterface* key_generator = new KeySequenceGenerator(str_initialize_keys);
    KeySequence* key_sequence = new KeySequence(key_generator);

    step_context_ = new StepController(this, key_sequence, Qt::green);
    connect(step_context_, SIGNAL(ResetSignal()),
            this, SLOT(onResetContext()));

    QGridLayout *layout = new QGridLayout;

    // initialize led && button by gridlayout
    GenerateLedIndicators(layout, LedCount);
    GenerateButtons(layout, LedCount);

    setLayout(layout);
}

Widget::~Widget() {
    delete step_context_;
    delete ui;
}

void Widget::onResetContext() {
    ResetButtonText(LedCount);
}

void Widget::ResetButtonText(const int count) {
    int seed = QRandomGenerator::global()->bounded(count);
    for (int i = 0; i < count; i++) {
        LedButton* button = led_buttons_[i];
        button->SetLimitText(seed);

        seed = reseed(seed, count);
    }
}

void Widget::GenerateButtons(QGridLayout* layout, const int count) {
    int seed = QRandomGenerator::global()->bounded(count);
    for (int i = 0; i < count; i++) {
        LedButton* button = new LedButton(this, seed);
        connect(button, SIGNAL(clicked()), step_context_, SLOT(onLedButtonClicked()));

        layout->addWidget(button, 1, i);
        led_buttons_.push_back(button);

        seed = reseed(seed, count);
    }
}

void Widget::GenerateLedIndicators(QGridLayout *layout, const int count) {
    int seed = QRandomGenerator::global()->bounded(count);
    for (int i = 0; i < count; i++) {
        LedIndicator* led = new LedIndicator(this, IndexToLedColor(seed));
        led->setText("Led " + QString::number(i+1));

        if (i > 0) {
            led->SetNextLed(led_indicators_[i-1]);
        }

        if (i == count-1) {
            QObject::connect(step_context_, SIGNAL(UpdateColor(QColor,int)), led, SLOT(onUpdateColor(QColor,int)));
        }

        layout->addWidget(led, 0, i);
        led_indicators_.push_back(led);

        seed = reseed(seed, count);
    }
}

int Widget::reseed(const int seed, const int count) {
    int tmpval = seed;
    tmpval++;
    tmpval = tmpval % count;

    return tmpval;
}

QColor Widget::IndexToLedColor(const int seed) {
    switch (seed) {
    case 0:
        return Qt::red;

    case 1:
        return Qt::yellow;

    case 2:
        return Qt::green;
    }

    return Qt::green;
}

