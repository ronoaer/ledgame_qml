#include "colorrule.h"

ColorRequest::ColorRequest(const int press_index, const int key_index) :
    press_index_(press_index),
    key_index_(key_index) {
}

GreenRule::GreenRule(ColorRule *rule) :
    rule_(rule) {
}

QColor GreenRule::HandleRequest(ColorRequest *request) {
    if (request->key_index() == request->press_index()) {
        return Qt::green;
    }

    return rule_->HandleRequest(request);
}

QColor YellowRule::HandleRequest(ColorRequest *request) {
    if (request->key_index() != request->press_index()) {
        return Qt::yellow;
    }

    return rule_->HandleRequest(request);
}

QColor RedRule::HandleRequest(ColorRequest *request) {
    if (request->key_index() < 0 || request->press_index() < 0) {
        return Qt::red;
    }

    return rule_->HandleRequest(request);
}
