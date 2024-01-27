set(APP_SRC
    main.cpp
<<<<<<< HEAD
    ledgameapplication.h
    ledgameapplication.cpp
=======
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
)

qt_add_executable(${PROJECT}
    ${APP_SRC}
<<<<<<< HEAD
    ../${QRC}
=======
    ../${QRC_SOURCE_FILES}
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
)

target_link_libraries(${PROJECT} PRIVATE ui key usecase ${LIBS})
