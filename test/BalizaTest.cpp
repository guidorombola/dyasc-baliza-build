#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockConectorCI.cpp"
#include "MockControladorDeAlertas.cpp"
#include "Orquestador.hpp"

using ::testing::AtLeast;
using ::testing::Return;

TEST(prueba, orquestadorDevuelveEstadoSeteadoEnMock){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas);
    
    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::OK));

    Estado estado = orquestador->obtenerEstado();

    ASSERT_EQ(Estado::OK, estado);
    
    delete mockCI;
    delete controladorAlertas;
    delete orquestador;
}

TEST(prueba, orquestadorInformaAlControladorDeLedQuePaseDeEstadoOKAFallo){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas);
    
    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::FALLO));

    EXPECT_CALL(*controladorAlertas, comunicarEstadoFallo())
    .Times(1);

    Estado estado = orquestador->obtenerEstado();
    ASSERT_EQ(Estado::FALLO, estado);
    
    delete mockCI;
    delete controladorAlertas;
    delete orquestador;
}