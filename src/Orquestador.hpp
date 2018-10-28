#ifndef ORQUESTADOR_H
#define ORQUESTADOR_H

#include "ConectorCI.hpp"

class Orquestador{
    public:
        Orquestador(ConectorCI* conector);
        Estado obtenerEstado();
    private:
        ConectorCI* con;
};

#endif
