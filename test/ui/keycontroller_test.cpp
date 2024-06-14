#include <gtest/gtest.h>

#include <keygenerator.h>
#include <keycontroller.h>

namespace keycontroller_test {
class MockGenerator : public KeyGenInterface {
public:
    MockGenerator(QObject* parent=nullptr) : KeyGenInterface(parent){}
    virtual QString generateKey() {
        return "ABB";
    }
};

TEST(KeyController, keyIndex) {
    KeyGenInterface* generator = new MockGenerator();
    KeyController *controller = new KeyController(generator);
    EXPECT_EQ(controller->keyIndex("",  0), -1);
    EXPECT_EQ(controller->keyIndex("A", 0), 0);
    EXPECT_EQ(controller->keyIndex("B", 1), 1);
    EXPECT_EQ(controller->keyIndex("C", 2), -1);
    EXPECT_EQ(controller->keyIndex("A", 1), 0);

    delete controller;
    delete generator;
}
}  // namespace keycontroller_test
