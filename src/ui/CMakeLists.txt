set(UI_SRC
    models/ledmodel.h
    models/ledmodel.cpp
    models/buttonmodel.h
    models/buttonmodel.cpp
    controller/ledgamecontroller.h
    controller/ledgamecontroller.cpp
    controller/colorcontroller.h
    controller/colorcontroller.cpp
    controller/keycontroller.h
    controller/keycontroller.cpp
    controller/keygenerator.h
    controller/keygenerator.cpp
)

add_library(ui
    ${UI_SRC}
)

target_link_libraries(ui PRIVATE Qt::Core Qt::Gui Qt::Quick Qt::Svg Qt::QuickControls2)
