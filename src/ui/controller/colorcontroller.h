#ifndef COLORCONTROLLER_H
#define COLORCONTROLLER_H

#include <QObject>

class ColorRule;

class ColorController : public QObject
{
    Q_OBJECT
public:
    explicit ColorController(QObject *parent = nullptr);
    ~ColorController();

    QColor mapToColor(const int press_index,
                      const int key_index);

    int pressIndex();
    int keyIndex();

private:
    int press_index_;
    int key_index_;

    ColorRule* yellow_rule_;
    ColorRule* green_rule_;
    ColorRule* red_rule_;
};

class ColorRule : public QObject {
    Q_OBJECT
public:
    explicit ColorRule(QObject *parent = nullptr);
    virtual ~ColorRule() {}
    virtual QColor handleRequest(ColorController* request) = 0;
};

class GreenRule : public ColorRule {
    Q_OBJECT
public:
    explicit GreenRule(ColorRule* rule, QObject *parent = nullptr);
    virtual QColor handleRequest(ColorController* request);

private:
    ColorRule* next_rule_;
};

class YellowRule : public ColorRule {
    Q_OBJECT
public:
    explicit YellowRule(ColorRule* rule, QObject *parent = nullptr);
    virtual QColor handleRequest(ColorController* request);

private:
    ColorRule* next_rule_;
};

class RedRule : public ColorRule {
    Q_OBJECT
public:
    explicit RedRule(ColorRule* rule, QObject *parent = nullptr);
    virtual QColor handleRequest(ColorController* request);

private:
    ColorRule* next_rule_;
};

#endif // COLORCONTROLLER_H
