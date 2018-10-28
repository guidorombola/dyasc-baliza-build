#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockConectorCI.cpp"
#include "Orquestador.hpp"

using ::testing::AtLeast;
using ::testing::Return;

TEST(prueba, orquestadorDevuelveEstadoSeteadoEnMock){
    MockConectorCI* mockCI = new MockConectorCI();
    Orquestador* orquestador = new Orquestador(mockCI);
    
    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::OK));

    Estado estado = orquestador->obtenerEstado();

    ASSERT_EQ(Estado::OK, estado);
    
    delete mockCI;
    delete orquestador;
}