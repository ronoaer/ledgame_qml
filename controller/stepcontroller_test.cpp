// Copyright 2023
// Author: LH
// this is ...
#include "stepcontroller.h"

#include <QString>
#include <QColor>

#include "keysequence/generatorinterface.h"
#include "keysequence/keysequence.h"
#include "ledindicator/ledindicator.h"


#include "gtest/gtest.h"
//#include "gmock/gmock.h"

namespace  StepController_test {
class MockGenerator : public GeneratorInterface {
public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};


TEST(StepController, Trigger) {
    LedIndicator* led1 = new LedIndicator(NULL, Qt::yellow);
    LedIndicator* led2  = new LedIndicator(NULL, Qt::red);
    LedIndicator* led3 = new LedIndicator(NULL, Qt::yellow);

    led3->SetNextLed(led2)->SetNextLed(led1);

    GeneratorInterface* generator = new MockGenerator();
    KeySequence *seq = new KeySequence(generator);
    StepController* contoller = new StepController(NULL, seq, Qt::green);
    QObject::connect(contoller, SIGNAL(UpdateColor(QColor,int)), led3, SLOT(onUpdateColor(QColor,int)));

    contoller->Trigger("A");
    contoller->Trigger("B");
    EXPECT_EQ(contoller->step()->can_rset(), true);
    contoller->Trigger("B");
    EXPECT_EQ(contoller->step()->can_rset(), true);

    contoller->Trigger("B");
    EXPECT_EQ(contoller->step()->can_rset(), false);
    contoller->Trigger("B");
    EXPECT_EQ(contoller->step()->can_rset(), false);
    contoller->Trigger("B");
    EXPECT_EQ(contoller->step()->can_rset(), true);

    contoller->Trigger("A");
    contoller->Trigger("C");
    EXPECT_EQ(contoller->step()->can_rset(), false);
    contoller->Trigger("B");
    EXPECT_EQ(contoller->step()->can_rset(), true);


    delete led3;
    delete led2;
    delete led1;
    delete contoller;
}

}  // namespace StepController_test
