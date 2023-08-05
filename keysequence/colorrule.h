// Copyright 2023
// Author: LH
// this is ...
#ifndef KEYSEQUENCE_COLORRULE_H_
#define KEYSEQUENCE_COLORRULE_H_

#include <QColor>

class ColorRequest {
 public:
    ColorRequest(const int press_index, const int key_index);

    int press_index() const {
        return press_index_;
    }

    int key_index() const {
        return key_index_;
    }

 private:
    int press_index_;
    int key_index_;
};

class ColorRule {
 public:
    virtual ~ColorRule() {}
    virtual QColor HandleRequest(ColorRequest* request) = 0;
};

class GreenRule : public ColorRule {
 public:
    explicit GreenRule(ColorRule* rule);
    virtual QColor HandleRequest(ColorRequest* request);

 private:
    ColorRule* rule_;
};

class YellowRule : public ColorRule {
 public:
    explicit YellowRule(ColorRule* rule) : rule_(rule) {}
    virtual QColor HandleRequest(ColorRequest *request);

 private:
    ColorRule* rule_;
};

class RedRule : public ColorRule {
 public:
    explicit RedRule(ColorRule* rule) : rule_(rule) {}
    virtual QColor HandleRequest(ColorRequest* request);

 private:
    ColorRule* rule_;
};

#endif  // KEYSEQUENCE_COLORRULE_H_
