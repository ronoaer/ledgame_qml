#include "widget.h"

#include <QApplication>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    Widget w;
    w.show();

    if (RUN_ALL_TESTS() == 1) {
        return 1;
    }

    return a.exec();
}
