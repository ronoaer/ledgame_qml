// Copyright 2023
// Author: LH
// this is ...
#ifndef LEDGAME_CONTROLLER_STEPCONTROLLER_H
#define LEDGAME_CONTROLLER_STEPCONTROLLER_H

#include <QObject>
#include <QColor>
#include <QString>

class StepInterface;
class KeySequence;

class StepController : public QObject {
    Q_OBJECT
 signals:
    void ResetSignal();
    void UpdateColor(QColor, int step_index);

 public:
    explicit StepController(QObject* parent, KeySequence* key_sequence,
                             const QColor reset_flag);
    virtual ~StepController();

    void GenerateKeySequence();

    void Trigger(const QString& key);

    void set_step(StepInterface* state) {
        step_ = state;
    }

    void ResetContext();

    StepInterface* step() {
        return step_;
    }

 public slots:
    void onLedButtonClicked();

 private:
    StepInterface* step_;

    QColor color_reset_flag_;

    KeySequence* key_sequence_;
};

class StepInterface {
 public:
    explicit StepInterface(bool can_reseet) :
         can_reset_(can_reseet) {
    }

    virtual ~StepInterface() {}
    virtual void Walk(StepController* context, bool right) = 0;

    void set_num_step_index(const int step_index) {
        num_step_index_ = step_index;
    }
    int num_step_index() { return num_step_index_; }

    void set_can_reset(bool right) {
        can_reset_ = right;
    }

    bool can_rset() {
        return can_reset_;
    }

 protected:
    int num_step_index_;
    bool can_reset_;
};

class StepFirst : public StepInterface {
 public:
    explicit StepFirst(bool can_right) : StepInterface(can_right) {
        num_step_index_ = 0;
    }

    virtual ~StepFirst() {}
    virtual void Walk(StepController* context, bool can_right);
};

class StepMiddle : public StepInterface {
 public:
    explicit StepMiddle(bool can_right) : StepInterface(can_right) {}
    virtual ~StepMiddle() {}
    virtual void Walk(StepController* context, bool can_right);
};

class StepLast : public StepInterface {
 public:
    explicit StepLast(bool can_right) : StepInterface(can_right) {}
    virtual ~StepLast() {}
    virtual void Walk(StepController* context, bool right);
};

#endif  // LEDGAME_CONTROLLER_STEPCONTROLLER_H
