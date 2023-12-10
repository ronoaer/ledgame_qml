set(US_SRC
    ledgameusecase.h
    ledgameusecase.cpp
    ledgame.cpp
    ledgame.h
    ledgameinterface.h
)

add_library(usecase
    ${US_SRC}
)

target_link_libraries(usecase PRIVATE Qt::Core Qt::Gui)

