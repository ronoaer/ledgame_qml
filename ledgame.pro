QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

include(../../googletest-main/gtest_dependency.pri)
include($$PWD/keysequence/keysequence.pri)
include($$PWD/ledindicator/ledindicator.pri)
include($$PWD/ledbutton/ledbutton.pri)
include($$PWD/controller/controller.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp \
    widget_test.cpp

HEADERS += \
    widget.h \
    widget_test.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

