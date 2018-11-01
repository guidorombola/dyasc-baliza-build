# Baliza de Build
[![Build Status](https://api.travis-ci.org/guidorombola/dyasc-baliza-build.svg?branch=master)](https://api.travis-ci.org/guidorombola/dyasc-baliza-build.svg?branch=master)

Baliza es un proyecto hardware-software para representar físicamente el estado de un servidor de integración continua.

### Hardware

| Cantidad | Componente |
| ------ | ------ |
| 1 | ESP-32  |
| 1 | Placa de soldadura experimental 10x5cm |
| 2 | Resistencia 220 OHM |
| 1 | Led rojo 3mm |
| 1 | Led verde 3mm |
| 1 | Cable USB a microUSB |

### Instalación entorno
El IDE utilizado para el desarollo fue [PlatformIO](https://platformio.org/). Por lo tanto al importarlo en esta plataforma, la misma se encargará de descargar las líbrerias necesarias
El proyecto fue desarrollado en un ambiente con sistema operativo Ubuntu. Para el 
mismo, se necesita tener las siguientes librerías:
- cmake
- build-essentials

Para ello:
```sh
$ sudo apt install cmake build-essentials
```

### Pruebas
Para correr las pruebas automatizadas, solo basta con ejecutar desde la raíz del proyecto:
```sh
$ ./test.sh
```
Este script se encargará de instalar las versiones necesarias de:
* [GTEST](https://github.com/google/googletest) - GoogleTest, librería de pruebas para C++ de Google

##### Fake Server
Para ejecutar las pruebas con un servidor local que genere un mock de las respuestas del servidor de integración continua es necesario instalar [json-server](https://github.com/typicode/json-server), para ello es necesario tener previamente instalado `NodeJS` v6+:
```sh
$ sudo apt install node
```
Para instalar *json-server*:
```sh
$ npm install -g json-server
```

Para iniciar el servidor solo basta entrar a la carpeta `fake-server`
```sh
$ cd fake-server
$ json-server --watch db.json
```

Para cambiar la respuesta sólo basta entrar a el archivo db.json y cambiar los datos.