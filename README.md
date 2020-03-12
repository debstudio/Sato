# Sato extensión mBlock
### Sato 

[Sato](https://github.com/debstudio/Sato/wiki) es un robot basado en Arduino, con propósito educativo, programable a través de mBlock. 

### mBlock

[mBlock](https://www.mblock.cc/)  es un entorno gráfico de programación basado en el editor Scratch 2.0 para que escuelas y centros de formación pueda introducir la robótica de forma sencilla y enseñar a programar robots basados en Arduino.

### Sato y mBlock

Este repositorio contiene los archivos necesarios para agregar a Sato como un dispositivo de mBlock con funciones específicas para la configuración del robot.
 
### Instalación :computer:
1. Descargue el software [mBlock 5](https://www.mblock.cc/en-us/download/) desde su página oficial.
2. Ejecute la aplicación. Cambie el idioma en la parte superior izquierda de la pantalla a español.
3. En la pestaña "Dispositivos" haga clic en "añadir".
4. Busque la extensión "Sato" y haga clic en "Nuevo Dispositivo".
>>Es posible que deba esperar a la actualización de los dispositivos soportados.
5. Una vez descargada la extensión haga clic sobre la misma y presione aceptar. Puede hacer clic sobre la estrella para configurar a Sato como el dispositivo por defecto.

- [Instalación Online](https://github.com/debstudio/Sato/wiki/Instalaci%C3%B3n-Online)


### Instalación Offline:dvd:

1. Descargue el software [mBlock 5](https://www.mblock.cc/en-us/download/) desde su página oficial.
2. Descargue el archivo  [sato.mext](https://github.com/debstudio/Sato/raw/master/mblock%205/sato.mext).
3. Ejecute mBlock y arrastre el archivo sato.mext sobre el IDE.
4. mBlock nos avisará que el nuevo dispositivo está instalado.

- [Instalación Offline](https://github.com/debstudio/Sato/wiki/Instalaci%C3%B3n-Offline)

## Comenzando 🚀
1. Utilice el cable USB para conectar ***Sato*** a la pc.
2. Haga clic en *Conectar* y aparecerá un listado con los puertos disponibles para la conección, seleccionamos el correcto y hacemos clic nuevamente en *Conectar*. Si el puerto no aparece pruebe con hacer clic en *mostrar todos los dispositivos conectables*.

> **IMPORTANTE: Debido a que el dispositivo bluetooth se encuentra conectado a los pines 0 y 1 de arduino el mismo debe permanecer apagado mientras se conecta con mBlock.**

Una vez desarrollado el código en mBlock debemos conectar el robot para subir el programa.

3. Haga clic en subir. mBlock cargará el programa en el dispositivo y mostrará un mensaje de finalización.
4. Ya puede desconectar a **Sato**.


### Hardware🔧

Sato esta basado en Arduino Uno y su extención necesita una distribución específica de pines que se definen en el archivo "Sato.h"

```
//Pin Motores puente H
const int B1A_PWN =10; //Motor B B-1A
const int B1B_DIR = 11;//Motor B  B-2A
const int A1A_PWN = 9; //Motor A A-1A
const int A1B_DIR = 8; //Motor A-1B
// Pin Servo
const int PIN_SERVO = 3;
const double MIN_ANGULO=10;
const double MAX_ANGULO=170;
const unsigned long MAX_TIEMPO_ATTACHED=1000;
//Pin Zumbador
const int PIN_BUZZER=6;
//Pin Ultrasonido
const int PIN_ECHO=A3;
const int PIN_TRIGGER=A2;
//Pin Sensor de Luz
const int PIN_LDR=A0;
//Pin Pulsador
const int PIN_PULSADOR=A1;
//PIN LUCES
const int PIN_LED=5;
const int CANTIDAD_PIXEL=2;
//Sigue lineas 
const int PIN_SIG_IZQ=4;
const int PIN_SIG_DER=7;
//IR
const int IR_PIN = 2;

//DefMotor
const int pinMotor2[3] = { B1B_DIR, B1A_PWN,0};
const int pinMotor1[3] = { A1B_DIR,A1A_PWN,1};

const long SERIAL_BAUDRATE=115200;
```

## Contenido🚀

El repositorio los siguientes directorios:
- **mblock 3:** Contiene el código fuente de la extensión para mBlock 3

  - Para utilizar esta extensión solo se debe comprimir el directorio Sato en un archivo zip y subirlo con el administrador de extenciones de mBlock 3.0. 

  - Para mas información puede consultar la documentación de mBlock [http://download.makeblock.com/mblock/mblock_extension_guide.pdf](http://download.makeblock.com/mblock/mblock_extension_guide.pdf)

- **mBlock 5:** Contiene el código fuente de la extensión para mBlock 5

  - El archivo [sato.mext](https://github.com/debstudio/Sato/raw/master/mblock%205/sato.mext) se corresponde con la exportación del [generador de extensiones de mblock](https://ext.mblock.cc/) para mas información consulte la documentación oficial: https://www.mblock.cc/doc/en/developer-documentation/developer-documentation.html.
  
  - El directorio src contien los archivos fuentes de arduino utilizados en la extensión.
  

## Desarrollado con 🛠️

* [mBlock](https://www.mblock.cc/en-us/) 
* [Arduino](https://www.arduino.cc/) 


## Contribuyendo 🖇️

Cosas con las que contribuir al proyecto
- Ejercicios de Ejemplo
- Documentación
- Nuevos Bloques para Nuevos Sensores

## Wiki 📖

Puedes encontrar mucho más de cómo utilizar este proyecto en nuestra [Wiki](https://github.com/debstudio/Sato/wiki)


## Autores ✒️


**debStudio S.A.**  - [www.debstudio.com.ar](http://www.debstudio.com.ar/)

Ademas se tomaron como base proyectos libres de robotica como mblock y otto.

## Licencia 📄

Este proyecto está bajo la Licencia (GNU GPLv3) - mira el archivo [LICENSE.md](LICENSE.md) para detalles

---
