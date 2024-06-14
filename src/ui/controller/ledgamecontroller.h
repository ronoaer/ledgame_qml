#ifndef LEDGAMECONTROLLER_H
#define LEDGAMECONTROLLER_H

#include <QObject>
#include <QSharedPointer>

class LedModel;
class ButtonModel;

class LedGameController : public QObject
{
    Q_OBJECT
public:
    explicit LedGameController(QSharedPointer<LedModel>& led_model,
                               QSharedPointer<ButtonModel>& button_model,
                               QObject *parent = nullptr);
    ~LedGameController();

public slots:
    void resetModel();
    void onButtonClicked(QString key);

signals:

private:
    void resetContext(int* press_index, const int max_count);
    void resetButtonsText();

    QSharedPointer<LedModel> led_model_;
    QSharedPointer<ButtonModel> button_model_;

    int num_press_index_;
};

#endif // LEDGAMECONTROLLER_H
