#ifndef ORQUESTADOR_H
#define ORQUESTADOR_H

#include "VisualizadorDeEstado.hpp"
#include "ComunicadorDeEventos.hpp"
#include "GestorDeConexion.hpp"
#include "ServidorLocal.hpp"

class Orquestador{
    public:
        Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador, GestorDeConexion* conectorWiFi, ServidorLocal* servidor);
        Estado obtenerEstado();
        void conectarARedWiFi();
        void iniciarConexiones();
    private:
        VisualizadorDeEstado* conector;
        ComunicadorDeEventos* control;
        GestorDeConexion* conectorWiFi;
        Estado ultimoEstado;
        ServidorLocal* servidor;
};

#endif
