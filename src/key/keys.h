// Copyright 2023
// Author: LH
// this is ...
#ifndef KEYSEQUENCE_KEYSEQUENCE_H_
#define KEYSEQUENCE_KEYSEQUENCE_H_

#include <QObject>
#include <QString>
#include <QColor>

class GeneratorInterface;
class LedStrategyInterface;
class ColorRule;


class Keys : public QObject {
    Q_OBJECT
 public:
    enum KeyPosition {
        NoKey,
        Wrong,
        Right
    };
    Q_ENUM(KeyPosition)

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
