set(APP_SRC
    main.cpp
    ledgameapplication.h
    ledgameapplication.cpp
)

qt6_add_resources(QRC ${QRC} qml.qrc)

add_subdirectory(ui)

qt_add_executable(${PROJECT}
    ${APP_SRC}
    ${QRC}
)

target_link_libraries(${PROJECT} PRIVATE ui ${LIBS})
