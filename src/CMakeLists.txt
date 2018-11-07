add_library(baliza "")

target_sources(
    baliza
    PRIVATE
        Orquestador.cpp
          
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/VisualizadorDeEstado.hpp
        ${CMAKE_CURRENT_LIST_DIR}/ComunicadorDeEventos.hpp
        ${CMAKE_CURRENT_LIST_DIR}/GestorDeConexion.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Orquestador.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Estado.hpp
    )

target_include_directories(
    baliza
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
