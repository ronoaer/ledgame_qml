// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_KEYSEQUENCE_GENERATORINTERFACE_H_
#define LEDGAME_KEYSEQUENCE_GENERATORINTERFACE_H_

#include <QString>

class GeneratorInterface {
 public:
    GeneratorInterface();
    virtual ~GeneratorInterface() {}

    virtual QString GenerateKeySequence() = 0;
};

class KeySequenceGenerator : public GeneratorInterface {
 public:
    explicit KeySequenceGenerator(const QString& seed);
    virtual ~KeySequenceGenerator() {}

    virtual QString GenerateKeySequence();

 private:
    QString seed_;
};

#endif  // LEDGAME_SEQUENCE_GENERATORINTERFACE_H_
