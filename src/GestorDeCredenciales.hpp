#ifndef GESTORDECREDENCIALES_H
#define GESTORDECREDENCIALES_H

class GestorDeCredenciales{
    private:
        const char* ssid;
        const char* clave;
    public:
        GestorDeCredenciales();
        void establecerSsid(const char* ssid);
        void establecerClave(const char* clave);
        const char* obtenerSsid();
        const char* obtenerClave();    
};

#endif