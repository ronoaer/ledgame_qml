project(LedGameTest LANGUAGES CXX)

include_directories(../ui)
include_directories(../key)
include_directories(../usecase)

find_package(Qt6 COMPONENTS Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(TEST_SRC ${TEST_SRC}
    main.cpp
    ui/ledgameui_test.cpp
    key/keysequence_test.cpp
    key/colorrule_test.cpp
    usecase/ledgame_test.cpp
    usecase/ledgameusecase_test.cpp
    usecase/generatorinterface_test.cpp
)

add_executable(LedGameTest
    ${TEST_SRC}
)

set (gtest_disable_ptheads on)
add_subdirectory(googletest-main)
config_compiler_and_linker()

target_link_libraries(LedGameTest PRIVATE gtest gmock ui usecase key Qt::Gui Qt::Core Qt6::Test)

add_test(NAME LedGameTest
         COMMAND LedGameTest)
