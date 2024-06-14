#ifndef LEDGAMECONTROLLER_H
#define LEDGAMECONTROLLER_H

#include <QObject>
#include <QSharedPointer>
#include <QColor>

class LedModel;
class ButtonModel;
class ColorController;
class KeyController;
class KeyGenInterface;

class LedGameController : public QObject
{
    Q_OBJECT
public:
    explicit LedGameController(QSharedPointer<LedModel>& led_model,
                               QSharedPointer<ButtonModel>& button_model,
                               KeyGenInterface* key_gen_interface,
                               QObject *parent = nullptr);
    ~LedGameController();

public slots:
    void resetModel();
    void onButtonClicked(const QString& key);

signals:

private:
    void resetContext();

    QSharedPointer<LedModel> led_model_;
    QSharedPointer<ButtonModel> button_model_;

    ColorController* color_controller_;
    KeyController* key_controller_;

    int press_index_;

    QStringList keys_;

    bool always_right_;
    QColor right_color_;
};

#endif // LEDGAMECONTROLLER_H
