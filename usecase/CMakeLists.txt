set(US_SRC
    usinterface.h
    usecase.h
    usecase.cpp
)

add_library(usecase
    ${US_SRC}
)

target_link_libraries(usecase PRIVATE Qt::Core Qt::Gui)

