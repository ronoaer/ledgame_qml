set(KEY_SRC
<<<<<<< HEAD
    keys.h
    keys.cpp
=======
    keysequence.h
    keysequence.cpp
>>>>>>> 7a335deed4432e3144ee132e3521665119e2a06a
    colorrule.h
    colorrule.cpp
    generatorinterface.h
    generatorinterface.cpp
)

add_library(key
    ${KEY_SRC}
)

target_link_libraries(key PRIVATE Qt6::Core Qt6::Gui)
