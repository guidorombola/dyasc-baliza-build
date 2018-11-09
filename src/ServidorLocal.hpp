#ifndef SERVIDORLOCAL_H
#define SERVIDORLOCAL_H

#include "Servidor.hpp"
#include <Arduino.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>

class ServidorLocal: public Servidor{
    public:
        ServidorLocal();
        void iniciar();
};

#endif