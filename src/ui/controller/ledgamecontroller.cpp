#include "ledgamecontroller.h"

#include <QRandomGenerator>

#include "colorcontroller.h"
#include "keycontroller.h"

const int initial_position = 0;

LedGameController::LedGameController(KeyGenInterface* key_gen_interface,
                                     QObject *parent)
    : QObject{parent}
{
    press_index_ = initial_position;
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
    emit resetDataModel();
}

void LedGameController::onButtonClicked(const QString& key)
{
    int key_index = key_controller_->keyIndex(key, press_index_);
    QColor color = color_controller_->mapToColor(press_index_, key_index);
    ++ press_index_;

    emit updateLed3Color(color);

    always_right_ = (right_color_ == color) && always_right_;
    resetContext();
}

void LedGameController::resetContext()
{
    if (press_index_ < key_controller_->keyLength()) {
        return;
    }

    press_index_ = initial_position;

    if (!always_right_) {
        always_right_ = true;
        return;
    }

    key_controller_->resetKey();
    always_right_ = true;

    emit resetDataModel();
}
