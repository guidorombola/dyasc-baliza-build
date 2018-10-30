#ifndef CONECTORCI_H
#define CONECTORCI_H

#include "VisualizadorDeEstado.hpp"

class ConectorCI : public VisualizadorDeEstado {
    public:
        virtual Estado obtenerEstado();
        void conectarARedWiFi();
    private:
        Estado estado;
};

#endif