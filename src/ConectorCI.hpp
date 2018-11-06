#ifndef CONECTORCI_H
#define CONECTORCI_H

#include <HTTPClient.h>
#include "VisualizadorDeEstado.hpp"

class ConectorCI : public VisualizadorDeEstado {
    public:
        ConectorCI();
        virtual Estado obtenerEstado();
    private:
        Estado estado;
        HTTPClient cliente;
        String realizarPeticion();
};

#endif