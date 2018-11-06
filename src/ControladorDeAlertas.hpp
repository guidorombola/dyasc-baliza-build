#ifndef CONTROLADORDEALERTAS_H
#define CONTROLADORDEALERTAS_H

#include "ComunicadorDeEventos.hpp"

class ControladorDeAlertas : public ComunicadorDeEventos {
        public:
         ControladorDeAlertas();       
         virtual void comunicarEstadoOK();
         virtual void comunicarEstadoFallo();
         virtual void comunicarEstadoDesconectado();

        private:
         int ledRojo;
         int ledVerde;
         int ledAmarillo;
         void parpadearLed(int led, int cantidadDeParpadeos);
};

#endif
