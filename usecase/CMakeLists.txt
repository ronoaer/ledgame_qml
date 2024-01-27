set(US_SRC
<<<<<<< HEAD
    usinterface.h
    usecase.h
    usecase.cpp
=======
    ledgameusecase.h
    ledgameusecase.cpp
    ledgame.cpp
    ledgame.h
    ledgameinterface.h
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
)

add_library(usecase
    ${US_SRC}
)

target_link_libraries(usecase PRIVATE Qt::Core Qt::Gui)

