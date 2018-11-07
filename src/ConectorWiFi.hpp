#ifndef CONECTORWIFI_H
#define CONECTORWIFI_H

#include "GestorDeConexion.hpp"
#include <WiFi.h>

class ConectorWiFi: public GestorDeConexion{
    public:
        ConectorWiFi(const char* ssid, const char* clave);
        virtual bool estaConectado();
        virtual void realizarConexion();
    private:
        const char* ssid;
        const char* clave;
};

#endif