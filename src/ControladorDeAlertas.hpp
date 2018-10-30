#ifndef CONTROLADORDEALERTAS_H
#define CONTROLADORDEALERTAS_H

#include "ComunicadorDeEventos.hpp"

class ControladorDeAlertas : public ComunicadorDeEventos {
        public:
         ControladorDeAlertas();       
         virtual void comunicarEstadoOK();
         virtual void comunicarEstadoFallo();
};

#endif
