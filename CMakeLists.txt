cmake_minimum_required(VERSION 3.14)

set(PROJECT LedGame)
project(${PROJECT})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PACKAGES
    Core Gui Widgets
    SVG Quick  QuickControls2
)

find_package(Qt6 REQUIRED COMPONENTS ${PACKAGES})
qt_standard_project_setup()

set(LIBS ${LIBS}
    Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Svg
    Qt6::Quick  Qt6::QuickControls2
)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
