// Copyright 2023
// Author: LH
// this is ...
#include "keysequence.h"
#include "generatorinterface.h"
#include "colorrule.h"

KeySequence::KeySequence(GeneratorInterface* generator) :
    generator_(generator) {
    ReRandomKeySequence();

    yellow_rule_ = new YellowRule(NULL);
    green_rule_ = new GreenRule(yellow_rule_);
    red_rule_ = new RedRule(green_rule_);
}

KeySequence::~KeySequence() {
    delete generator_;

    delete yellow_rule_;
    delete green_rule_;
    delete red_rule_;
}

QColor KeySequence::KeyMapColor(const QString &key,
                                const int press_index) const {
    if (InvalidKeyOrIndex(key, press_index)) {
        return Qt::red;
    }

    int key_index = key_sequence_.indexOf(key);
    if (key_index >= 0) {
        QString tmpKey = (key_sequence_[press_index]);
        if (tmpKey == key) {
            key_index = press_index;
        }
    }

    ColorRequest *request = new ColorRequest(press_index, key_index);
    QColor color = red_rule_->HandleRequest(request);
    delete request;

    return color;
}

void KeySequence::ReRandomKeySequence() {
    key_sequence_ = generator_->GenerateKeySequence();
}

bool KeySequence::InvalidKeyOrIndex(const QString &key,
                                    const int press_index) const {
    if ((key.length() != 1) || (press_index < 0) ||
        (press_index >= key_sequence_.length())) {
        return true;
    }

    return false;
}
