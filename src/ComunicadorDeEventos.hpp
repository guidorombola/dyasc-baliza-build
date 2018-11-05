#ifndef COMUNICADORDEEVENTOS_H
#define COMUNICADORDEEVENTOS_H

class ComunicadorDeEventos{
    public:
        virtual void comunicarEstadoOK() = 0;
        virtual void comunicarEstadoFallo() = 0;
        virtual void comunicarEstadoDesconectado() = 0;
};

#endif
