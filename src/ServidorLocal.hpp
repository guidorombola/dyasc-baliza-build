#ifndef SERVIDORLOCAL_H
#define SERVIDORLOCAL_H

#include <Arduino.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>

class ServidorLocal{
    public:
        ServidorLocal();
        void iniciar();
};

#endif