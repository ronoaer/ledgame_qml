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

    QColor keyMapColor(const QString& key, const int press_index) const;

    KeyPosition keyIndex(const QString& key, const int press_number);

    void reRandomKeySequence();

 private:
    bool invalidKeyOrIndex(const QString& key, const int press_index) const;

    GeneratorInterface* generator_;

    QString key_sequence_;
    ColorRule* yellow_rule_;
    ColorRule* green_rule_;
    ColorRule* red_rule_;
};

#endif  // KEYSEQUENCE_KEYSEQUENCE_H_
