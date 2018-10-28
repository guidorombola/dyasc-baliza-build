#ifndef CONECTORCI_H
#define CONECTORCI_H

class ConectorCI {
    private:
        bool estado;
    public:
        virtual bool obtenerEstado();
};

#endif