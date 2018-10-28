add_library(baliza "")

target_sources(
    baliza
    PRIVATE
        ConectorCI.cpp
        Orquestador.cpp   
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/ConectorCI.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Orquestador.hpp
    )

target_include_directories(
    baliza
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
