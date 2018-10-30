#include <ComunicadorDeEventos.hpp>
#include "gmock/gmock.h"

class MockControladorDeAlertas : public ComunicadorDeEventos {
    public:
    MOCK_METHOD0(comunicarEstadoOK, void());
    MOCK_METHOD0(comunicarEstadoFallo, void());
};