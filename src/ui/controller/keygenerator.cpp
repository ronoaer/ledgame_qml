#include "keygenerator.h"

#include <QRandomGenerator>

KeyGenerator::KeyGenerator(const QString &seed,
                           QObject *parent) :
    KeyGenInterface(parent),
    seed_(seed)
{

}

QString KeyGenerator::generateKey()
{
    int length = seed_.length();

    QString keys = "";

    for (int i = 0; i < length; i++) {
        int seed = QRandomGenerator::global()->bounded(length);

        keys = keys + seed_[seed];
    }

    return keys;
}

KeyGenInterface::KeyGenInterface(QObject *parent)
    : QObject{parent}
{

}
