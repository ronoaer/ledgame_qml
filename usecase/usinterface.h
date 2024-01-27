// Copyright 2023
// Author: LH
// this is a abstract class, for descripting logic inteface
#ifndef USINTERFACE_H_
#define USINTERFACE_H_

#include <QString>
#include <QColor>

class USInterface {
 public:
    virtual ~USInterface() {}

    // get color when clicked button
    virtual QColor GetColorByKey(const QString& key) = 0;

    // reset when all right in a round
    virtual void ResetContext() = 0;
};


#endif  // USINTERFACE_H_
