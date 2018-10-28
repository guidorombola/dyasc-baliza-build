#ifndef ORQUESTADOR_H
#define ORQUESTADOR_H

#include "ConectorCI.hpp"

class Orquestador{
    public:
        Orquestador(ConectorCI* conector);
        bool obtenerEstado();
    private:
        ConectorCI* con;
};

#endif
