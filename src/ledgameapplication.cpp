#include "ledgameapplication.h"

#include <QQmlContext>

#include "ui/ledgameui.h"
#include "key/keys.h"
#include "key/generatorinterface.h"
#include "ui/models/buttonmodel.h"
#include "ui/models/ledmodel.h"
#include "ui/controller/ledgamecontroller.h"


LedGameApplication::LedGameApplication(int &argc, char *argv[]) : QApplication(argc, argv)
{

}

LedGameApplication::~LedGameApplication()
{
    if (engine_) {
        QObject::disconnect(engine_, 0, 0, 0);
        delete engine_;
    }
}

void LedGameApplication::init()
{
    engine_ = new QQmlApplicationEngine;

    const QUrl url(QStringLiteral("qrc:/ui/qml/main.qml"));
    QObject::connect(
        engine_, &QQmlApplicationEngine::objectCreated, this,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    initModels();
    initControllers();

    engine_->load(url);
}

void LedGameApplication::initModels()
{
    led_model_.reset(new LedModel(this));
    engine_->rootContext()->setContextProperty("LedModel",
                                               led_model_.get());

    button_model_.reset(new ButtonModel(this));
    engine_->rootContext()->setContextProperty("ButtonModel",
                                               button_model_.get());
}

void LedGameApplication::initControllers()
{
    // QString str_initialize_keys("ABC");

    // // initialize key sequence
    // GeneratorInterface* key_generator =
    //     new KeySequenceGenerator(str_initialize_keys);

    // Keys* key_sequence = new Keys(key_generator);

    controller_.reset(new LedGameController(led_model_,
                                            button_model_,
                                            this));
    engine_->rootContext()->setContextProperty("LGController", controller_.get());
}

