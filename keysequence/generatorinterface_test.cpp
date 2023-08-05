// Copyright 2023
// Author: LH
// this is ...
#include "generatorinterface.h"

#include <QString>

#include "gtest/gtest.h"

namespace charSequencecenerator_test {

    TEST(KeySequenceGenerator, GenerateKeySequence) {
        int length = 3;
        GeneratorInterface* generator = new KeySequenceGenerator("ABC");
        QString str = generator->GenerateKeySequence();
        EXPECT_EQ(length, str.length());

        delete generator;
    }

}  // namespace charSequencecenerator_test
