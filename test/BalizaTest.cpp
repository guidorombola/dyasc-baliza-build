#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockConectorCI.cpp"
#include "MockControladorDeAlertas.cpp"
#include "MockConectorWiFi.cpp"
#include "MockServidorLocal.cpp"
#include "GestorDeCredenciales.cpp"
#include "Orquestador.hpp"
#include "Estado.hpp"

using ::testing::AtLeast;
using ::testing::Return;

/* Requerimiento 1 - Comunica cambio de estado */
TEST(prueba, orquestadorDevuelveEstadoSeteadoEnMock){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);

    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(1)
    .WillOnce(Return(true));

    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::OK));

    Estado estado = orquestador->obtenerEstado();

    ASSERT_EQ(Estado::OK, estado);
    
    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}

TEST(prueba, orquestadorIniciaEnEstadoIndefinidoLuegoRecibeEstadoFalloEInformaAlControladorDeLedQueComuniqueFallo){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);
    
    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(1)
    .WillOnce(Return(true));

    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::FALLO));

    EXPECT_CALL(*controladorAlertas, comunicarEstadoFallo())
    .Times(1);

    Estado estado = orquestador->obtenerEstado();
    ASSERT_EQ(Estado::FALLO, estado);
    
    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}

TEST(prueba, orquestadorIniciaEnEstadoIndefinidoLuegoRecibeEstadoOKEInformaAlControladorDeLedQueComuniqueOK){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);
    
    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(1)
    .WillOnce(Return(true));

    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::OK));

    EXPECT_CALL(*controladorAlertas, comunicarEstadoOK())
    .Times(1);

    Estado estado = orquestador->obtenerEstado();
    ASSERT_EQ(Estado::OK, estado);
    
    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}

TEST(prueba, orquestadorInformaAlControladorDeLedQuePaseDeEstadoFalloAOK){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);
    
    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(2)
    .WillRepeatedly(Return(true));

    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(2)
    .WillOnce(Return(Estado::FALLO))
    .WillOnce(Return(Estado::OK));

    EXPECT_CALL(*controladorAlertas, comunicarEstadoOK())
    .Times(1);

    Estado estadoFallo = orquestador->obtenerEstado();
    Estado estadoOK = orquestador -> obtenerEstado();
    ASSERT_EQ(Estado::OK, estadoOK);
    
    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}

TEST(prueba, orquestadorInformaAlControladorDeLedQuePaseDeEstadoOKAFallo){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);
    
    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(2)
    .WillRepeatedly(Return(true));

    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(2)
    .WillOnce(Return(Estado::OK))
    .WillOnce(Return(Estado::FALLO));

    EXPECT_CALL(*controladorAlertas, comunicarEstadoFallo())
    .Times(1);

    Estado estadoOK = orquestador->obtenerEstado();
    Estado estadoFallo = orquestador -> obtenerEstado();
    ASSERT_EQ(Estado::FALLO, estadoFallo);
    
    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}

TEST(prueba, orquestadorNoInformaCambioDeEstadoAlControladorDeAlertasSiElBuildContinuaEnElMismoEstadoAnteriorDeValorFallo){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);

    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(2)
    .WillRepeatedly(Return(true));

    EXPECT_CALL(*mockCI, obtenerEstado()).Times(2)
    .WillOnce(Return(Estado::FALLO))
    .WillOnce(Return(Estado::FALLO));

    EXPECT_CALL(*controladorAlertas, comunicarEstadoFallo()).Times(1);
    EXPECT_CALL(*controladorAlertas, comunicarEstadoOK()).Times(0);

    Estado estadoFallo = orquestador->obtenerEstado();
    Estado estadoFallo_2 = orquestador->obtenerEstado();

    ASSERT_EQ(Estado::FALLO, estadoFallo);
    ASSERT_EQ(Estado::FALLO, estadoFallo_2);

    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}
/* Fin requerimiento 1 */

/* Requerimiento 5 - Comunica aviso de desconexión */
TEST(prueba, SiHayProblemasEnLaComunicacionOrquestadorInformaAControladorDeAlertasQueIndiqueEstadoDesconexion){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);

    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(1)
    .WillOnce(Return(false));

    EXPECT_CALL(*mockCI, obtenerEstado()).Times(0);

    EXPECT_CALL(*controladorAlertas, comunicarEstadoDesconectado()).Times(1);

    Estado estadoDesconectado = orquestador->obtenerEstado();

    ASSERT_EQ(Estado::DESCONECTADO, estadoDesconectado);

    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}

TEST(prueba, SiEstaConectadoALaRedPeroHayProblemasEnLaComunicacionConElServidorOrquestadorInformaAControladorDeAlertasQueIndiqueEstadoDesconexion){
    MockConectorCI* mockCI = new MockConectorCI();
    MockControladorDeAlertas* controladorAlertas = new MockControladorDeAlertas();
    MockConectorWiFi* conectorWiFi = new MockConectorWiFi();
    MockServidorLocal* servidorLocal = new MockServidorLocal();
    Orquestador* orquestador = new Orquestador(mockCI, controladorAlertas, conectorWiFi, servidorLocal);
     
    EXPECT_CALL(*conectorWiFi, estaConectado())
    .Times(1)
    .WillOnce(Return(true));
     
    EXPECT_CALL(*mockCI, obtenerEstado())
    .Times(1)
    .WillOnce(Return(Estado::DESCONECTADO));
    
    EXPECT_CALL(*controladorAlertas, comunicarEstadoDesconectado()).
    Times(1);

    Estado estadoDesconectado = orquestador->obtenerEstado();
    ASSERT_EQ(Estado::DESCONECTADO, estadoDesconectado);

    delete mockCI;
    delete controladorAlertas;
    delete conectorWiFi;
    delete servidorLocal;
    delete orquestador;
}
/* Fin requerimiento 5 */

