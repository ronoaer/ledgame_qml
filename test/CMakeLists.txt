project(LedGameTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(../src/ui/controller)

set(PACKAGES
    Core Gui Test
)

find_package(Qt6 REQUIRED COMPONENTS ${PACKAGES})
qt_standard_project_setup()
set(LIBS ${LIBS}
    Qt::Core Qt::Gui Qt6::Test
)

set(TEST_SRC ${TEST_SRC}
    main.cpp
    ../src/ui/controller/keygenerator.h
    ../src/ui/controller/keygenerator.cpp
    ../src/ui/controller/keycontroller.h
    ../src/ui/controller/keycontroller.cpp
    ../src/ui/controller/colorcontroller.h
    ../src/ui/controller/colorcontroller.cpp
    ./ui/keycontroller_test.cpp
    ./ui/colorcontroller_test.cpp
)

add_executable(LedGameTest
    ${TEST_SRC}
)

set (gtest_disable_ptheads on)
add_subdirectory(googletest-main)
config_compiler_and_linker()

target_link_libraries(LedGameTest PRIVATE gtest gmock  ${LIBS})

add_test(NAME LedGameTest
        COMMAND LedGameTest)
