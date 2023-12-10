set(UI_SRC
    ledgameui.h
    ledgameui.cpp
)

add_library(ui
    ${UI_SRC}
)

target_link_libraries(ui PRIVATE Qt::Core Qt::Gui)
