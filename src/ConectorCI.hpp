#ifndef CONECTORCI_H
#define CONECTORCI_H

#include "Estado.hpp"

class ConectorCI {
    private:
        Estado estado;
    public:
        virtual Estado obtenerEstado();
};

#endif