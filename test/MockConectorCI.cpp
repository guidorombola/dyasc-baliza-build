#include <ConectorCI.hpp>
#include "gmock/gmock.h"

class MockConectorCI : public ConectorCI {
    public:
    MOCK_METHOD0(obtenerEstado, bool());
};