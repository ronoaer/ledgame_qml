#ifndef KEYCONTROLLER_H
#define KEYCONTROLLER_H

#include <QObject>

class KeyGenInterface;

class KeyController : public QObject
{
    Q_OBJECT
public:
    explicit KeyController(KeyGenInterface* interface,
                           QObject *parent = nullptr);
    ~KeyController() {}

    int keyIndex(const QString& key, const int press_index);
    void resetKey();
    int keyLength();

signals:

private:
    KeyGenInterface* key_generator_;
    QString keys_;
};

#endif // KEYCONTROLLER_H
