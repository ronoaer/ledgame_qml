#ifndef LEDGAMEAPPLICATION_H
#define LEDGAMEAPPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>

class LedModel;
class ButtonModel;
class LedGameController;

class LedGameApplication : public QApplication
{
public:
    LedGameApplication(int &argc, char *argv[]);
    virtual ~LedGameApplication();

    void init();

private:
    void initModels();
    void initControllers();

    QQmlApplicationEngine *engine_ {};

    QSharedPointer<LedModel> led_model_;
    QSharedPointer<ButtonModel> button_model_;
    QSharedPointer<LedGameController> controller_;
};

#endif // LEDGAMEAPPLICATION_H
