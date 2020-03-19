#include <SoftwareSerial.h>
#include "TimerFreeTone.h"

//Pin Motores puente H
const int B1A_PWN =10; //Motor B B-1A
const int B1B_DIR = 11;//Motor B  B-2A
const int A1A_PWN = 9; //Motor A A-1A
const int A1B_DIR = 8; //Motor A-1B

//Minimo y máximo para el cálculo de potencia;
const int VELOCIDAD_MIN=70;
const int VELOCIDAD_MAX=200;

// Pin Servo
const int PIN_SERVO = 3;
const double MIN_ANGULO=0;
const double MAX_ANGULO=180;
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
const int CANTIDAD_PIXEL=4;
//Sigue lineas 
const int PIN_SIG_IZQ=4;
const int PIN_SIG_DER=7;
//IR
const int IR_PIN = 2;

//DefMotor
const int pinMotor2[3] = { B1B_DIR, B1A_PWN,0};
const int pinMotor1[3] = { A1B_DIR,A1A_PWN,1};

const long SERIAL_BAUDRATE=115200;

void serieInicializa();
int serieDatosDisponibles();
char serieCaracter();
int serieNumero();
int seriePrint(String val);
int seriePrintLn(String val);
int serieValorCodigo();
void run(const int pinMotor[3], int speed);
void adelante(const int pinMotor[3], int speed);
void atras(const int pinMotor[3], int speed);
void move(int direction, int speed);
void muevePotencia(int direccion, double potencia);
void para();
void iniMotor();
void iniServo();
void posicionaServo(int angulo);
void establecerVelocidad(const int pinMotor[3],int speed);
void establecerVelocidadPotencia(const int pinMotor[3],int potencia,int direccion);
void tocarNota(int nota,int duracion);
void suena(int frecuencia,int duracion);
void starwarRS(double i);
void iniLuz();
void establecerLuz(int luz,int rojo,int verde,int azul,int brillo);
void establecerLuzColor(int nluz,char scolor[],int brillo);
void movermm(int direccion,int velocidad,double mm);
int leerSigueLinea();
void iniIR();
String irBotonPresionado();
void irLoop();
void servoLoop();
float obtieneDistancia(int trig,int echo);
void tonoCurvo(float iniFrecuencia, float finFrecuencia, float proporcion, long duracion, int silencio);