#ifndef GESTORDECREDENCIALES_H
#define GESTORDECREDENCIALES_H

class GestorDeCredenciales{
    private:
        GestorDeCredenciales();

        static const char* ssid;
        static const char* clave;
        static bool actualizar;
    public:

        static bool hayCambios();
        static void establecerSsid(const char* ssid);
        static void establecerClave(const char* clave);
        static const char* obtenerSsid();
        static const char* obtenerClave();
};

#endif