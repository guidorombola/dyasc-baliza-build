#ifndef CONTROLADORDEALERTAS_H
#define CONTROLADORDEALERTAS_H

class ControladorDeAlertas{
    public:
        ControladorDeAlertas();
        virtual void comunicarEstadoOK();
        virtual void comunicarEstadoFallo();
};

#endif
