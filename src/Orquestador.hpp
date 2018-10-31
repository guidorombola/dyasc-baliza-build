#ifndef ORQUESTADOR_H
#define ORQUESTADOR_H

#include "VisualizadorDeEstado.hpp"
#include "ComunicadorDeEventos.hpp"

class Orquestador{
    public:
        Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador);
        Estado obtenerEstado();
    private:
        VisualizadorDeEstado* con;
        ComunicadorDeEventos* control;
        Estado ultimoEstado;
};

#endif
