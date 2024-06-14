// Copyright 2023
// Author: LH
// this is ...
#include <generatorinterface.h>
#include <keys.h>

#include <gtest/gtest.h>

namespace keysequence_test {
class MockGenerator : public GeneratorInterface {
 public:
    virtual QString GenerateKeySequence() {
        return "ABB";
    }
};

    TEST(CharSequence, IndexOf) {
        GeneratorInterface* generator = new MockGenerator();
        Keys *seq = new Keys(generator);
        EXPECT_EQ(seq->keyMapColor("",  0), Qt::red);
        EXPECT_EQ(seq->keyMapColor("A", 0), Qt::green);
        EXPECT_EQ(seq->keyMapColor("B", 1), Qt::green);
        EXPECT_EQ(seq->keyMapColor("C", 2), Qt::red);
        EXPECT_EQ(seq->keyMapColor("A", 1), Qt::yellow);

        // invalid key || press_index
        EXPECT_EQ(seq->keyMapColor("",  0), Qt::red);
        EXPECT_EQ(seq->keyMapColor("A", -1), Qt::red);
        EXPECT_EQ(seq->keyMapColor("A", 4), Qt::red);

        delete seq;
    }
}  // namespace keysequence_test

