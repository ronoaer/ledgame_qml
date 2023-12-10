set(APP_SRC
    main.cpp
)

qt_add_executable(${PROJECT}
    ${APP_SRC}
    ../${QRC_SOURCE_FILES}
)

target_link_libraries(${PROJECT} PRIVATE ui key usecase ${LIBS})
