#include "ledgamecontroller.h"

#include <QRandomGenerator>

#include "../models/buttonmodel.h"
#include "../models/ledmodel.h"
#include "colorcontroller.h"
#include "keycontroller.h"

LedGameController::LedGameController(QSharedPointer<LedModel>& led_model,
                                     QSharedPointer<ButtonModel>& button_model,
                                     KeyGenInterface* key_gen_interface,
                                     QObject *parent)
    : QObject{parent},
    led_model_(led_model),
    button_model_(button_model)
{
    press_index_ = 0;
    right_color_ = Qt::green;
    always_right_ = true;

    color_controller_ = new ColorController(this);
    key_controller_ = new KeyController(key_gen_interface, this);
}

LedGameController::~LedGameController()
{

}

void LedGameController::resetModel()
{
    led_model_->resetDatas();
    button_model_->resetDatas();
}

void LedGameController::onButtonClicked(const QString& key)
{
    int key_index = key_controller_->keyIndex(key, press_index_);
    QColor color = color_controller_->mapToColor(press_index_, key_index);
    ++ press_index_;

    led_model_->updateLed3Color(color);

    always_right_ = (right_color_ == color) && always_right_;
    resetContext();
}

void LedGameController::resetContext()
{
    if (press_index_ < key_controller_->keyLength()) {
        return;
    }

    press_index_ = 0;

    if (!always_right_) {
        always_right_ = true;
        return;
    }

    // resetContext;
    key_controller_->resetKey();
    always_right_ = true;
    resetModel();
}
