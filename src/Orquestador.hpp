#ifndef ORQUESTADOR_H
#define ORQUESTADOR_H

#include "VisualizadorDeEstado.hpp"
#include "ComunicadorDeEventos.hpp"
#include "ConectorWiFi.hpp"

class Orquestador{
    public:
        Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador, GestorDeConexion* conectorWiFi);
        Estado obtenerEstado();
        void conectarARedWiFi();
    private:
        VisualizadorDeEstado* con;
        ComunicadorDeEventos* control;
        GestorDeConexion* conectorWiFi;
        Estado ultimoEstado;
};

#endif
