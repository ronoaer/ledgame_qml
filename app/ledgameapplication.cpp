#include "ledgameapplication.h"

#include "../ui/ledgameui.h"
#include "../key/keys.h"
#include "../key/generatorinterface.h"
#include "../usecase/usecase.h"


LedGameApplication::LedGameApplication(int &argc, char *argv[]) : QApplication(argc, argv)
{

}

LedGameApplication::~LedGameApplication()
{
//    if (engine_) {
//        QObject::disconnect(engine_, 0, 0, 0);
//        delete engine_;
//    }
}

void LedGameApplication::init()
{
    initUsecase();
    initUi();
}

int LedGameApplication::initUsecase()
{
    QString str_initialize_keys("ABC");

    // initialize key sequence
    GeneratorInterface* key_generator =
        new KeySequenceGenerator(str_initialize_keys);

    KeySequence* key_sequence = new KeySequence(key_generator);
    usecase_ = new Usecase(key_sequence, Qt::green);

    return 0;
}

void LedGameApplication::initUi()
{
    ui_ = new LedGameUI(usecase_, this);
}
