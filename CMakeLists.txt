cmake_minimum_required(VERSION 3.14)

set(PROJECT LedGame)
project(${PROJECT})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PACKAGES
    Core Gui Network Xml Widgets
    RemoteObjects Quick Svg QuickControls2
    Core5Compat Concurrent LinguistTools
)

find_package(Qt6 REQUIRED COMPONENTS ${PACKAGES})
qt_standard_project_setup()

set(LIBS ${LIBS}
    Qt6::Core Qt6::Gui Qt6::Widgets
    Qt6::Network Qt6::Xml Qt6::RemoteObjects
    Qt6::Quick Qt6::Svg Qt6::QuickControls2
    Qt6::Core5Compat Qt6::Concurrent
)

set(QRC
    ui.qrc
)


enable_testing()

add_subdirectory(app)
add_subdirectory(ui)
add_subdirectory(key)
add_subdirectory(usecase)

add_subdirectory(test)
