#include <VisualizadorDeEstado.hpp>
#include "gmock/gmock.h"

class MockConectorCI : public VisualizadorDeEstado {
    public:
    MOCK_METHOD0(obtenerEstado, Estado());
};