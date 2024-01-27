// Copyright 2023
// Author: LH
// this is ...
#ifndef KEYSEQUENCE_KEYSEQUENCE_H_
#define KEYSEQUENCE_KEYSEQUENCE_H_

#include <QString>
#include <QColor>

class GeneratorInterface;
class LedStrategyInterface;
class ColorRule;

enum class KeyPosition {
    NoKey,
    Wrong,
    Right
};

class Keys {
 public:
    explicit Keys(GeneratorInterface* generator);
    virtual ~Keys();

    QColor KeyMapColor(const QString& key, const int press_index) const;

    KeyPosition KeyIndex(const QString& key, const int press_number);

    void ReRandomKeySequence();

 private:
    bool InvalidKeyOrIndex(const QString& key, const int press_index) const;

    GeneratorInterface* generator_;

    QString key_sequence_;
    ColorRule* yellow_rule_;
    ColorRule* green_rule_;
    ColorRule* red_rule_;
};

#endif  // KEYSEQUENCE_KEYSEQUENCE_H_
