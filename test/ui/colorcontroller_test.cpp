#include <gtest/gtest.h>

#include <QColor>
#include <colorcontroller.h>

namespace colorcontroller_test {

TEST(ColorRule, handleRequest) {
    ColorController* controller = new ColorController();

    int press_index = 0;
    int key_index = 0;
    QColor color = controller->mapToColor(press_index, key_index);
    EXPECT_EQ(color, Qt::green);

    press_index = -1;
    key_index = -1;
    color = controller->mapToColor(press_index, key_index);
    EXPECT_EQ(color, Qt::red);

    press_index = -1;
    key_index = 0;
    color = controller->mapToColor(press_index, key_index);
    EXPECT_EQ(color, Qt::red);

    press_index = 1;
    key_index = 0;
    color = controller->mapToColor(press_index, key_index);
    EXPECT_EQ(color, Qt::yellow);

    delete controller;
}

}  // namespace colorcontroller_test
