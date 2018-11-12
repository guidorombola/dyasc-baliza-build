#include <GestorDeCredenciales.hpp>
#include "gmock/gmock.h"

class MockGestorDeCredenciales : public GestorDeCredenciales {
    public:
    MOCK_METHOD0(hayCambios, bool());
};