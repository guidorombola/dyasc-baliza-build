#include <Servidor.hpp>
#include "gmock/gmock.h"

class MockServidorLocal : public Servidor {
    public:
    MOCK_METHOD0(iniciar, void());
};