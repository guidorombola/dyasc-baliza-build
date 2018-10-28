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
    .WillOnce(Return(true));

    bool valor = orquestador->obtenerEstado();

    ASSERT_TRUE(valor);
    
    delete mockCI;
    delete orquestador;
}