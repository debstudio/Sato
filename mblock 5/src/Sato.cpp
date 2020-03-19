#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Wire.h>
#include "IRReadOnlyRemote.h" 
#include "Sato.h"
#include "Adafruit_NeoPixel.h"
#include "ServoTimer2.h"



IRReadOnlyRemote irrecv(IR_PIN);


unsigned long key_value = 0;

ServoTimer2 servo; 
int tempSerie;
bool isLeidoIR=false;
String lastKeyPress;
Adafruit_NeoPixel pixels(CANTIDAD_PIXEL,PIN_LED , NEO_GRB + NEO_KHZ800);
unsigned long tiempoUltimoMovServo=0;
int counterRS=0;

//Serie
void serieInicializa()
{
	Serial.begin(SERIAL_BAUDRATE);
}
int serieDatosDisponibles(){
	int disponible=0;
	int c;
	tempSerie=0;
	if(Serial.available())
	{
		disponible=1;
		
		c=Serial.read();
		tempSerie=c;
	}
	return disponible;
}
char serieCaracter(){
	return char(tempSerie);
}
int serieNumero(){
	return tempSerie;
}
int seriePrint(String val){
	 Serial.print(val);
}
int seriePrintLn(String val){
	 Serial.println(val);
}
int serieValorCodigo(){
	return Serial.readStringUntil(10).toInt();
}///

void setVelocidad(int pin,int velocidad)
{

 analogWrite(pin,velocidad);

}

void adelante(const int pinMotor[3], int speed){
    if(speed > 0){
        digitalWrite(pinMotor[0], 1);
		analogWrite(pinMotor[1], 255-speed);
	}
    else{
       digitalWrite(pinMotor[0], 0);
	   analogWrite(pinMotor[1], 0);
	}    
}
void atras(const int pinMotor[3], int speed){
     if(speed > 0){
        digitalWrite(pinMotor[0],0);
        analogWrite(pinMotor[1], speed);
	}
    else
    {
       digitalWrite(pinMotor[0], 0);
       analogWrite(pinMotor[1], 0);
	}
}  

void run(const int pinMotor[3], int speed){
	 if (speed > VELOCIDAD_MAX)
	 {
		 speed=250;
	 }
	 if (speed < -1*VELOCIDAD_MAX)
	 {
		 speed= -1*VELOCIDAD_MAX;
	 }
     if (speed >= 0){
		adelante(pinMotor,speed);
		}
     else{
		atras(pinMotor,-1*speed);
	}
}
int potenciaAVelocidad(double potencia)
{
	int speed;
	if(potencia<=0)
	{
		speed=0;
	}
	else
	{
		speed=VELOCIDAD_MIN+(VELOCIDAD_MAX-VELOCIDAD_MIN) * potencia/100.0;
	}
	return speed;
}
void muevePotencia(int direccion, double potencia)
{
	int speed;
	speed=potenciaAVelocidad(potencia);
	move(direccion,speed);
}
void para()
{
	move(1,0);
}

void move(int direction, int speed){

     int leftSpeed = 0;
     int rightSpeed = 0;
	 if(direction == 1){
		leftSpeed = speed;
		rightSpeed = speed;
		}
	 else if(direction == 2){
		 leftSpeed = -speed;
		 rightSpeed = -speed;
		}
	 else if(direction == 4){
		 leftSpeed = speed;
		 rightSpeed = -speed;
		}
	 else if(direction == 3){
		leftSpeed = -speed;
		rightSpeed = speed;
		}

    run(pinMotor1,leftSpeed);
	run(pinMotor2,rightSpeed);
}
void establecerVelocidad(const int pinMotor[3],int speed){

	run(pinMotor,speed);
}
void establecerVelocidadPotencia(const int pinMotor[3],int potencia,int direccion){
	int speed;
	speed=potenciaAVelocidad(potencia);
	if(direccion=2)
	{
		speed=-1*speed;
	}
	run(pinMotor,speed);
}
void iniMotor(){
  pinMode(pinMotor1[0], OUTPUT);
  pinMode(pinMotor1[1], OUTPUT);

  pinMode(pinMotor2[0], OUTPUT);
  pinMode(pinMotor2[1], OUTPUT);

  TCCR1B = TCCR1B & B11111000 | B00000101; 


}
void iniServo()
{
	 posicionaServo(90);
}
void posicionaServo(int angulo)
{
	if(!servo.attached())
	{
		servo.attach(PIN_SERVO);
	}
	double rango=MAX_PULSE_WIDTH-MIN_PULSE_WIDTH;
	double pasoAngulo=rango*1.0/MAX_ANGULO*1.0;
	double paso=(angulo-MIN_ANGULO)*pasoAngulo+MIN_PULSE_WIDTH;
	servo.write(paso);
	tiempoUltimoMovServo=millis();
	//servo.write(angulo);
}
void servoLoop() //Libera servo para ahorro de energía
{
	if(servo.attached()&& (millis()-tiempoUltimoMovServo)>MAX_TIEMPO_ATTACHED)
	{
		servo.detach();
	}

}
void iniLuz()
{
	pinMode(PIN_LED,OUTPUT);
    establecerLuz(0,0,0,0,0);
}

void establecerLuz(int nluz,int rojo,int verde,int azul,int brillo){
	
	pixels.setBrightness(brillo);
	if (nluz==0)
	{
		int i;
		for (i=0;i<CANTIDAD_PIXEL;i++){
			pixels.setPixelColor(i, pixels.Color(rojo, verde, azul));
		}
	}
	else{
	pixels.setPixelColor(nluz-1, pixels.Color(rojo, verde, azul));
	}
	pixels.show(); 
}
void establecerLuzColor(int nluz,char scolor[],int brillo)
{
   char *ptr;
   unsigned long color=strtoul( scolor+2, &ptr, 16);
   int r = color >> 16;
   int g = color >> 8 & 0xFF;
   int b = color & 0xFF;
	establecerLuz(nluz,r,g,b,brillo);
}

int leerSigueLinea()
{
  int estado;
  bool sigDer = digitalRead(PIN_SIG_DER);
  bool sigIzq = digitalRead(PIN_SIG_IZQ);
  estado = ( (1 & sigDer) << 1) | sigIzq;
  return(estado);
}

void beepRS(int note, int duration)
{
  //Play //tone on buzzerPin
  //tone(PIN_BUZZER, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counterRS % 2 == 0)
  {
    digitalWrite(A1, HIGH);
    delay(duration);
    digitalWrite(A1, LOW);
  }else
  {
    digitalWrite(A3, HIGH);
    delay(duration);
    digitalWrite(A3, LOW);
  }
 
  //Stop //tone on buzzerPin
  //notone(PIN_BUZZER);
 
  delay(50);
 
  //Increment counter
  counterRS++;
}
void iniIR()
{

}
String irBotonPresionado()
{
  String keyPress="N";
  if(!isLeidoIR)
  {
	  // delay(100);
	  unsigned long data = irrecv.read();
	  if (data != 0){

			if (data== 0XFFFFFFFF)
			  data= key_value;

			switch(data){
			  case 0xFFA25D:
			  keyPress= "1";
			  break;
			  case 0xFF629D:
			  keyPress= "2";
			  break;
			  case 0xFFE21D:
			  keyPress= "3";
			  break;
			  case 0xFF22DD:
			  keyPress="4";
			  break;
			  case 0xFF02FD:
			  keyPress= "5";
			  break ;  
			  case 0xFFC23D:
			  keyPress= "6";
			  break ;               
			  case 0xFFE01F:
			  keyPress= "7";
			  break ;  
			  case 0xFFA857:
			  keyPress= "8";
			  break ;  
			  case 0xFF906F:
			  keyPress= "9";
			  break ;  
			  case 0xFF6897:
			  keyPress= "*";
			  break ;  
			  case 0xFF9867:
			  keyPress= "0";
			  break ;
			  case 0xFFB04F:
			  keyPress= "#";
			  break ;
			  case 0xFF18E7:
			  keyPress= "↑";
			  break ;
			  case 0xFF10EF:
			  keyPress= "←";
			  break ;
			  case 0xFF38C7:
			  keyPress= "OK";
			  break ;
			  case 0xFF5AA5:
			  keyPress= "→";
			  break ;
			  case 0xFF4AB5:
			  keyPress= "↓";
			  break ;   
			}
			key_value = data;
		    
			lastKeyPress=keyPress;
	  }
 
  }
  else
  {
	  keyPress=lastKeyPress;
  }
  lastKeyPress=keyPress;
  isLeidoIR=true;
  return keyPress;
}
void irLoop()
{
	isLeidoIR=false;
}
float obtieneDistancia(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}
void suena(int frecuencia,int duracion)
{
	TimerFreeTone(PIN_BUZZER,frecuencia,duracion);
}
void tocarNota(int nota,int duracion)
{
	TimerFreeTone(PIN_BUZZER,nota,duracion);
	delay(20);
}
void tocarNotaConSilencio(int nota,int duracion,int silencio)
{
	TimerFreeTone(PIN_BUZZER,nota,duracion);
	delay(silencio);
}
void tonoCurvo(float iniFrecuencia, float finFrecuencia, float proporcion, long duracion, int silencio)
{

  if(silencio==0){silencio=1;}

  if(iniFrecuencia < finFrecuencia)
  {
      for (int i=iniFrecuencia; i<finFrecuencia; i=i*proporcion) {
          tocarNotaConSilencio(i, duracion, silencio);
      }

  } else{

      for (int i=iniFrecuencia; i>finFrecuencia; i=i/proporcion) {
          tocarNotaConSilencio(i, duracion, silencio);
      }
  }
}
void starwarRS(double i){
	int c = 261;
	int d = 294;
	int e = 329;
	int f = 349;
	int g = 391;
	int gS = 415;
	int a = 440;
	int aS = 455;
	int b = 466;
	int cH = 523;
	int cSH = 554;
	int dH = 587;
	int dSH = 622;
	int eH = 659;
	int fH = 698;
	int fSH = 740;
	int gH = 784;
	int gSH = 830;
	int aH = 880;
	if (i==1)
	  beepRS(a, 500);
	if (i==2)
	  beepRS(a, 500);
	if (i==3)
	  beepRS(a, 500);
	if (i==4)
	  beepRS(f, 350);
	if (i==5)
	  beepRS(cH, 150);  
	if (i==6)
	  beepRS(a, 500);
	if (i==7)
	  beepRS(f, 350);
	if (i==8)
	  beepRS(cH, 150);
	if (i==9)
	  beepRS(a, 650);
	if (i==10)
	  delay(500);
	if (i==11) 
	  beepRS(eH, 500);
	if (i==12)
	  beepRS(eH, 500);
	if (i==13)
	  beepRS(eH, 500);  
	if (i==14)
	  beepRS(fH, 350);
	if (i==15)
	  beepRS(cH, 150);
	if (i==1)
	  beepRS(gS, 500);
	if (i==16)
	  beepRS(f, 350);
	if (i==17)
	  beepRS(cH, 150);
	if (i==18)
	  beepRS(a, 650);
	if (i==19)
	  delay(500);
	
}
