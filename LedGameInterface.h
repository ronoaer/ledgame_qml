// Copyright 2023
// Author: LH
// this is a abstract class, for descripting logic inteface
#ifndef LEDGAME_LEDGAMEINTERFACE_H_
#define LEDGAME_LEDGAMEINTERFACE_H_

#include <QString>
#include <QColor>

class LedGameInterface {
public:
    virtual ~LedGameInterface() {}

    virtual QColor Presskey(const QString& key, const int press_index) = 0;

    virtual bool CanResetContext() = 0;

    virtual void ResetContext() = 0;
};


#endif // LEDGAME_LEDGAMEINTERFACE_H_
