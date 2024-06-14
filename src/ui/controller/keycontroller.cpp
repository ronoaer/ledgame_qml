#include "keycontroller.h"
#include "keygenerator.h"

KeyController::KeyController(KeyGenInterface* interface,
                             QObject *parent)
    : QObject{parent},
    key_generator_(interface)
{
    resetKey();
}

int KeyController::keyIndex(const QString& key, const int press_index)
{
    int key_index = keys_.indexOf(key);

    if (key_index >= 0) {
        QString tmpKey = (keys_[press_index]);

        if (tmpKey == key) {
            key_index = press_index;
        }
    }

    return key_index;
}

void KeyController::resetKey()
{
    keys_ = key_generator_->generateKey();
}

int KeyController::keyLength()
{
    return keys_.length();
}
