#ifndef GESTORDECONEXION_H
#define GESTORDECONEXION_H

class GestorDeConexion{
    public:
        virtual bool estaConectado() = 0;
        virtual void realizarConexion() = 0;
};

#endif