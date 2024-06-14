#include "colorcontroller.h"

#include <QColor>

ColorController::ColorController(QObject *parent)
    : QObject{parent}
{
    yellow_rule_ = new YellowRule(NULL, this);
    green_rule_ = new GreenRule(yellow_rule_, this);
    red_rule_ = new RedRule(green_rule_, this);
}

ColorController::~ColorController()
{

}

int ColorController::pressIndex()
{
    return press_index_;
}

int ColorController::keyIndex()
{
    return key_index_;
}

QColor ColorController::mapToColor(const int press_index,
                                   const int key_index)
{
    press_index_ = press_index;
    key_index_ = key_index;

    QColor color = red_rule_->handleRequest(this);

    return color;
}

ColorRule::ColorRule(QObject *parent) :
    QObject(parent)
{

}

GreenRule::GreenRule(ColorRule *rule, QObject *parent) :
    ColorRule(parent),
    next_rule_(rule)
{

}

QColor GreenRule::handleRequest(ColorController *request)
{
    if (request->keyIndex() == request->pressIndex()) {
        return Qt::green;
    }

    return next_rule_->handleRequest(request);
}

YellowRule::YellowRule(ColorRule *rule, QObject *parent) :
    ColorRule(parent),
    next_rule_(rule)
{

}

QColor YellowRule::handleRequest(ColorController *request)
{
    if (request->keyIndex() != request->pressIndex()) {
        return Qt::yellow;
    }

    return next_rule_->handleRequest(request);
}

RedRule::RedRule(ColorRule *rule, QObject *parent) :
    ColorRule(parent),
    next_rule_(rule)
{

}

QColor RedRule::handleRequest(ColorController *request)
{
    if (request->keyIndex() < 0 ||
        request->pressIndex() < 0) {
        return Qt::red;
    }

    return next_rule_->handleRequest(request);
}
