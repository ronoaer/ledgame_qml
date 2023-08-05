// Copyright 2023
// Author: LH
// this is ...
#include "generatorinterface.h"
#include "keysequence.h"

#include "gtest/gtest.h"

namespace keysequence_test {
class MockGenerator : public GeneratorInterface {
 public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};

    TEST(CharSequence, IndexOf) {
        GeneratorInterface* generator = new MockGenerator();
        KeySequence *seq = new KeySequence(generator);
        EXPECT_EQ(seq->KeyMapColor("",  0), Qt::red);
        EXPECT_EQ(seq->KeyMapColor("A", 0), Qt::green);
        EXPECT_EQ(seq->KeyMapColor("B", 1), Qt::green);
        EXPECT_EQ(seq->KeyMapColor("C", 2), Qt::red);
        EXPECT_EQ(seq->KeyMapColor("A", 1), Qt::yellow);

        // invalid key || press_index
        EXPECT_EQ(seq->KeyMapColor("",  0), Qt::red);
        EXPECT_EQ(seq->KeyMapColor("A", -1), Qt::red);
        EXPECT_EQ(seq->KeyMapColor("A", 4), Qt::red);

        delete seq;
    }
}  // namespace keysequence_test

