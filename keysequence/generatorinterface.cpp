#include "generatorinterface.h"

#include <QRandomGenerator>


GeneratorInterface::GeneratorInterface() {
}

KeySequenceGenerator::KeySequenceGenerator(const QString& seed) :
    seed_(seed) {
}

QString KeySequenceGenerator::GenerateKeySequence() {
    int length = seed_.length();

    QString str = "";

    for (int i = 0; i < length; i++) {
        int seed = QRandomGenerator::global()->bounded(length);

        str = str + seed_[seed];
    }

    return str;
}


