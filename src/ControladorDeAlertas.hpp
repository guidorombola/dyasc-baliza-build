#ifndef CONTROLADORDEALERTAS_H
#define CONTROLADORDEALERTAS_H

#include "ComunicadorDeEventos.hpp"

class ControladorDeAlertas : public ComunicadorDeEventos {
        public:
         ControladorDeAlertas();       
         virtual void comunicarEstadoOK();
         virtual void comunicarEstadoFallo();

        private:
         int ledRojo;
         int ledVerde;
         void parpadearLed(int led, int cantidadDeParpadeos);
};

#endif
