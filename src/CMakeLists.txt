add_library(baliza "")

target_sources(
    baliza
    PRIVATE
        
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/guido.h
    )

target_include_directories(
    baliza
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
