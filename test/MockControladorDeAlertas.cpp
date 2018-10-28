#include <ControladorDeAlertas.hpp>
#include "gmock/gmock.h"

class MockControladorDeAlertas : public ControladorDeAlertas {
    public:
    MOCK_METHOD0(comunicarEstadoOK, void());
    MOCK_METHOD0(comunicarEstadoFallo, void());
};