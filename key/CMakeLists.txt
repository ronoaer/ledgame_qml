set(KEY_SRC
    keys.h
    keys.cpp
    keysequence.h
    keysequence.cpp
    colorrule.h
    colorrule.cpp
    generatorinterface.h
    generatorinterface.cpp
)

add_library(key
    ${KEY_SRC}
)

target_link_libraries(key PRIVATE Qt6::Core Qt6::Gui)
