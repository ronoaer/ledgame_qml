set(UI_SRC
    ledgameui.h
    ledgameui.cpp
<<<<<<< HEAD
    models/ledmodel.h
    models/ledmodel.cpp
    models/buttonmodel.h
    models/buttonmodel.cpp
=======
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
)

add_library(ui
    ${UI_SRC}
)

<<<<<<< HEAD
target_link_libraries(ui PRIVATE Qt::Core Qt::Gui Qt::Quick Qt::Svg Qt::QuickControls2)
=======
target_link_libraries(ui PRIVATE Qt::Core Qt::Gui)
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
