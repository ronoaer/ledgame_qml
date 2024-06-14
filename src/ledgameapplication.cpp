#include "ledgameapplication.h"

#include <QQmlContext>

#include "ui/models/buttonmodel.h"
#include "ui/models/ledmodel.h"
#include "ui/controller/ledgamecontroller.h"
#include "ui/controller/keygenerator.h"

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
    QString str_initialize_keys("ABC");

    KeyGenInterface* key_generator =
        new KeyGenerator(str_initialize_keys);

    controller_.reset(new LedGameController(led_model_,
                                            button_model_,
                                            key_generator,
                                            this));
    engine_->rootContext()->setContextProperty("LGController", controller_.get());
}

