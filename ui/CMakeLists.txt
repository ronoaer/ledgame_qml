set(UI_SRC
    ledgameui.h
    ledgameui.cpp
    models/ledmodel.h
    models/ledmodel.cpp
    models/buttonmodel.h
    models/buttonmodel.cpp
)

add_library(ui
    ${UI_SRC}
)

target_link_libraries(ui PRIVATE Qt::Core Qt::Gui Qt::Quick Qt::Svg Qt::QuickControls2)
