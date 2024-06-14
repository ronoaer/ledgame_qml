set(APP_SRC
    main.cpp
    ledgameapplication.h
    ledgameapplication.cpp
)

qt_add_executable(${PROJECT}
    ${APP_SRC}
    ../${QRC}
)

target_link_libraries(${PROJECT} PRIVATE ui key usecase ${LIBS})
