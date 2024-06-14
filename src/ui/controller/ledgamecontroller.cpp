#include "ledgamecontroller.h"

#include <QRandomGenerator>

#include "../models/buttonmodel.h"
#include "../models/ledmodel.h"

LedGameController::LedGameController(QSharedPointer<LedModel>& led_model,
                                     QSharedPointer<ButtonModel>& button_model,
                                     QObject *parent)
    : QObject{parent},
    led_model_(led_model),
    button_model_(button_model)
{}

LedGameController::~LedGameController()
{

}

void LedGameController::resetModel()
{
    led_model_->resetDatas();
    button_model_->resetDatas();
}

void LedGameController::onButtonClicked(QString key)
{
    // QColor newest_color = usecase_->Presskey(key, num_press_index_);
    // num_press_index_++;

    // QString str_color = newest_color.name();

    // Q_EMIT updateLedsColor(num_press_index_, str_color);

    // ResetContext(&num_press_index_, LedCount);
}

void LedGameController::resetContext(int *press_index, const int max_count)
{
    if (*press_index < max_count) {
        return;
    }

    *press_index = 0;

    // if (!usecase_->CanResetContext()) {
    //     return;
    // }

    // // update UI.....
    // ResetButtonsText();

    // // update usecase....
    // usecase_->ResetContext();
}

void LedGameController::resetButtonsText()
{
    // int count = LedCount;
    // int seed = QRandomGenerator::global()->bounded(count);

    // for (int i = 0; i < count; i++) {
    //     QString key = IndexToText(seed);

    //     Q_EMIT UpdateButtonText(i, key);

    //     seed++;
    //     seed = seed % count;
    // }
}
