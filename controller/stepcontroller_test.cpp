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
    GeneratorInterface* generator = new MockGenerator();
    KeySequence *seq = new KeySequence(generator);
    StepController* contoller = new StepController(seq, Qt::green);

//    contoller->Key("A");
//    contoller->Key("B");
//    EXPECT_EQ(contoller->step()->can_rset(), true);
//    contoller->Key("B");
//    EXPECT_EQ(contoller->step()->can_rset(), true);

//    contoller->Key("B");
//    EXPECT_EQ(contoller->step()->can_rset(), false);
//    contoller->Key("B");
//    EXPECT_EQ(contoller->step()->can_rset(), false);
//    contoller->Key("B");
//    EXPECT_EQ(contoller->step()->can_rset(), true);

//    contoller->Key("A");
//    contoller->Key("C");
//    EXPECT_EQ(contoller->step()->can_rset(), false);
//    contoller->Key("B");
//    EXPECT_EQ(contoller->step()->can_rset(), true);

    delete contoller;
}

}  // namespace StepController_test
