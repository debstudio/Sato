# Sato extención mBlock
## Sato 

Sato es un robot basado en arduino con propositos educativos programable a travez de mBlock.

## mBlock

[mBlock](https://www.mblock.cc/)  es un entorno gráfico de programación basado en el editor Scratch 2.0 para que escuelas y centros de formación pueda introducir la robótica de forma sencilla y enseñar a programar robots basados en Arduino.
## Sato y mBlock

 Este repositorio contiene las extenciones necesarias para agregar a mBlock bloques específicos de **Sato**.
 
### Instalación 🔧
1. Descargue el software [mBlock 5](https://www.mblock.cc/en-us/download/) desde su página oficial.
2. Ejecute la aplicación. (Puede cambiar el idioma en la parte superior izquierda de de la pantalla a español).
3. En la pestaña "Dispositivos" haga clic en "añadir".
4. Busque la extensión "Sato" y haga clic en "Nuevo Dispositivo". (Es posible que deba esperar a la actualización de los dispositivos soportados.) En caso de no poseer una conexión a internet, es posible descargar la extensión he instalarla en modo offline. Ese procedimiento se describe más adelante.
5. Una vez descargada la extensión haga clic sobre la misma y presione aceptar. Puede hacer clic sobre la estrella para configurar a Sato como el dispositivo por defecto.

[Instalación](https://raw.githubusercontent.com/debstudio/Sato/prueba/doc/img/instalacion.png)

### Instalación Offline🔧

1. Descargue el software [mBlock 5](https://www.mblock.cc/en-us/download/) desde su página oficial.
2. Descargue el archivo sato.mext.
3. Ejecute mBlock y arrastre el archivo sato.mext sobre el IDE.
4. mBlock nos avisará que el nuevo dispositivo esta instalado.

[Offline](https://raw.githubusercontent.com/debstudio/Sato/prueba/doc/img/offline.png)

## Comenzando 🚀
1. Utilice el cable USB para conectar ***Sato*** a la pc.
2. Haga clic en *Conectar* y aparecerá un listado con los puertos disponibles para la conección, seleccionamos el correcto y hacemos clic nuevamente en *Conectar*. Si el puerto no aparece pruebe con hacer clic en *mostrar todos los dispositivos conectables*.

**IMPORTANTE: DEBIDO A QUE EL DISPOSITIVO BLUETOOTH ESTA CONECTADO A LOS PINES 0 Y 1 DE ARDUINO EL MISMO DEBE PERMANECER APAGADO MIENTRAS SE CONECTA CON MBLOCK**

Una vez desarrollado el código en mBlock debemos conectar el robot para subir el programa.

3. Haga clic en subir. mBlock cargará el programa en el dispositivo y mostrará un mensaje de finalización.
4. Ya puede desconectar a **Sato**.


### Hardware🔧

Sato esta basado en Arduino Uno y su extención necesita una distribución específica de pines que se definen en el archivo "Sato.h"

```

const int B1A_PWN =10;   //Motor B B-1A
const int B1B_DIR = 11; //Motor B  B-2A
const int A1A_PWN = 9; //Motor A A-1A
const int A1B_DIR = 8;  //Motor A-1B

const int PIN_SERVO = 3; // Pin Servo
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
//DefMotor
const int pinMotor2[3] = { B1B_DIR, B1A_PWN,0};
const int pinMotor1[3] = { A1B_DIR,A1A_PWN,1};
//IR
const int IR_PIN = 2;
const long SERIAL_BAUDRATE=115200;
```

## Comenzando 🚀

_El software de Sato


```
Da un ejemplo
```

### Instalación 🔧

_Una serie de ejemplos paso a paso que te dice lo que debes ejecutar para tener un entorno de desarrollo ejecutandose_

_Dí cómo será ese paso_

```
Da un ejemplo
```

_Y repite_

```
hasta finalizar
```

_Finaliza con un ejemplo de cómo obtener datos del sistema o como usarlos para una pequeña demo_

## Ejecutando las pruebas ⚙️

_Explica como ejecutar las pruebas automatizadas para este sistema_

### Analice las pruebas end-to-end 🔩

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

### Y las pruebas de estilo de codificación ⌨️

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

## Despliegue 📦

_Agrega notas adicionales sobre como hacer deploy_

## Construido con 🛠️

_Menciona las herramientas que utilizaste para crear tu proyecto_

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - El framework web usado
* [Maven](https://maven.apache.org/) - Manejador de dependencias
* [ROME](https://rometools.github.io/rome/) - Usado para generar RSS

## Contribuyendo 🖇️

Por favor lee el [CONTRIBUTING.md](https://gist.github.com/villanuevand/xxxxxx) para detalles de nuestro código de conducta, y el proceso para enviarnos pull requests.

## Wiki 📖

Puedes encontrar mucho más de cómo utilizar este proyecto en nuestra [Wiki](https://github.com/tu/proyecto/wiki)

## Versionado 📌

Usamos [SemVer](http://semver.org/) para el versionado. Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/tu/proyecto/tags).

## Autores ✒️

_Menciona a todos aquellos que ayudaron a levantar el proyecto desde sus inicios_

* **Andrés Villanueva** - *Trabajo Inicial* - [villanuevand](https://github.com/villanuevand)
* **Fulanito Detal** - *Documentación* - [fulanitodetal](#fulanito-de-tal)

También puedes mirar la lista de todos los [contribuyentes](https://github.com/your/project/contributors) quíenes han participado en este proyecto. 

## Licencia 📄

Este proyecto está bajo la Licencia (Tu Licencia) - mira el archivo [LICENSE.md](LICENSE.md) para detalles

## Expresiones de Gratitud 🎁





---
