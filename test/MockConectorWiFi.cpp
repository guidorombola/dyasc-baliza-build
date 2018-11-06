#include <GestorDeConexion.hpp>
#include "gmock/gmock.h"

class MockConectorWiFi : public GestorDeConexion {
    public:
    MOCK_METHOD0(realizarConexion, void());
    MOCK_METHOD0(estaConectado, bool());
};