#ifndef CONECTORCI_H
#define CONECTORCI_H

#include "VisualizadorDeEstado.hpp"
#include "ConectorWiFi.hpp"

class ConectorCI : public VisualizadorDeEstado {
    public:
        ConectorCI();
        virtual Estado obtenerEstado();
        void conectarARedWiFi();
    private:
        Estado estado;
        ConectorWiFi* wifi;
};

#endif