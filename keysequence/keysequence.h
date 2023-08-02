// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_KEYSEQUENCE_KEYSEQUENCE_H_
#define LEDGAME_KEYSEQUENCE_KEYSEQUENCE_H_

#include <QString>
#include <QColor>
#include <QMap>

class GeneratorInterface;
class LedStrategyInterface;
class YellowRule;
class GreenRule;
class RedRule;

class KeySequence {
 public:
    explicit KeySequence(GeneratorInterface* generator);
    virtual ~KeySequence();

    QColor KeyMapColor(const QString& key, const int press_index) const;

    void ReRandomKeySequence();

 private:
    bool InvalidKeyOrIndex(const QString& key, const int press_index) const;

    GeneratorInterface* generator_;

    QString key_sequence_;
    YellowRule* yellow_rule_;
    GreenRule* green_rule_;
    RedRule* red_rule_;
};

#endif  // LEDGAME_SEQUENCE_KEYSEQUENCE_H_
