#ifndef LEDGAMECONTROLLER_H
#define LEDGAMECONTROLLER_H

#include <QObject>
#include <QColor>

class ColorController;
class KeyController;
class KeyGenInterface;

class LedGameController : public QObject
{
    Q_OBJECT
public:
    explicit LedGameController(KeyGenInterface* key_gen_interface,
                               QObject *parent = nullptr);
    ~LedGameController();

public slots:
    void resetModel();
    void onButtonClicked(const QString& key);

signals:
    void updateLed3Color(const QColor& colo);
    void resetDataModel();

private:
    void resetContext();

    ColorController* color_controller_;
    KeyController* key_controller_;

    int press_index_;

    QStringList keys_;

    bool always_right_;
    QColor right_color_;
};

#endif // LEDGAMECONTROLLER_H
