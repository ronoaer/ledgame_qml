#ifndef KEYGENERATOR_H
#define KEYGENERATOR_H

#include <QObject>

class KeyGenInterface : public QObject {
    Q_OBJECT
public:
    KeyGenInterface(QObject *parent = nullptr);
    virtual ~KeyGenInterface() {}

    virtual QString generateKey() = 0;
};


class KeyGenerator : public KeyGenInterface
{
    Q_OBJECT
public:
    explicit KeyGenerator(const QString& seed,
                          QObject *parent = nullptr);

    virtual QString generateKey();

private:
    QString seed_;
};

#endif // KEYGENERATOR_H
