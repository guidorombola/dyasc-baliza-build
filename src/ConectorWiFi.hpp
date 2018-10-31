#ifndef CONECTORWIFI_H
#define CONECTORWIFI_H

class ConectorWiFi{
    public:
        ConectorWiFi(const char* ssid, const char* clave);
        bool estaConectado();
        void realizarConexion();
    private:
        const char* ssid;
        const char* clave;
};

#endif