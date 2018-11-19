#ifndef CONECTORWIFI_H
#define CONECTORWIFI_H

#include "GestorDeConexion.hpp"
#include "GestorDeCredenciales.hpp"
#include <WiFi.h>

class ConectorWiFi: public GestorDeConexion{
    public:
        ConectorWiFi();
        virtual bool estaConectado();
        virtual void realizarConexion();
        virtual void iniciarAP();
        virtual void apagarAP();
};

#endif