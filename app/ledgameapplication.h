#ifndef LEDGAMEAPPLICATION_H
#define LEDGAMEAPPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>

class LedGameUsecase;
class LedGameUI;

class LedGameApplication : public QApplication
{
public:
    LedGameApplication(int &argc, char *argv[]);
    virtual ~LedGameApplication();

    void init();

private:
    int initUsecase();
    void initUi();

    QQmlApplicationEngine *engine_ {};

    QSharedPointer<LedGameUsecase> usecase_;
    QSharedPointer<LedGameUI> ui_;
};

#endif // LEDGAMEAPPLICATION_H
