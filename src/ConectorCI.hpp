#ifndef CONECTORCI_H
#define CONECTORCI_H

#include <WiFi.h>
#include <HTTPClient.h>
#include "Estado.hpp"

class ConectorCI {
    private:
        Estado estado;
    public:
        virtual Estado obtenerEstado();
        void conectarARedWiFi();
};

#endif