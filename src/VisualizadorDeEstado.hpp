#ifndef VISUALIZADORDEESTADO_H
#define VISUALIZADORDEESTADO_H

#include "Estado.hpp"

class VisualizadorDeEstado {
    public:
        virtual Estado obtenerEstado() = 0;
};

#endif