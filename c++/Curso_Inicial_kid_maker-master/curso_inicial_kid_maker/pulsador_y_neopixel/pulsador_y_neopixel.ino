/*
  Actividad N° 7 - Pulsadores y neopixels

  Permite intercambiar entre distintos colores los neopixels, 
  haciendo el uso de cuatro botones.

  Nota:
  - Se debe descargar la libreria NeoPixel en caso de no tenerla - Link: https://github.com/adafruit/Adafruit_NeoPixel
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  por FANIOT
  http://www.faniot.com.ar
  
*/

#define NEO 27      // Definimos el Pin del Neopixel, en este caso es el 27.
#define NUM 4       // Definimos el numero de Neopixels que tenemos, en este caso es 4.
#define B_IZQ 13    // Definimos el Pin del boton Izquierdo, en este caso es el 13.
#define B_ENTER 15  // Definimos el Pin del boton Central, en este caso es el 15.
#define B_DER 23    // Definimos el Pin del boton Derecho, en este caso es el 23.

#include <Adafruit_NeoPixel.h>  // Incluimos la libreria Neopixel 

int B_IZQ_EST = 0;    // Variable para leer el estado del boton Izquierdo
int B_ENTER_EST = 0;  // Variable para leer el estado del boton Central
int B_DER_EST = 0;    // Variable para leer el estado del boton Derecho

// Le decimos cuantos pixeles tenemos, y que pin usar para enviar las señales.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, NEO, NEO_GRB + NEO_KHZ800);

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {
  
  //Inicializamos la libreria Neopixel 
  pixels.begin();
  //Ajustamos el nivel de brillo en un 20% (0-64)
  pixels.setBrightness(5);
  //Inicializamos los pines digitales de los tres botones como entrada.
  pinMode(B_IZQ, INPUT);
  pinMode(B_ENTER, INPUT);
  pinMode(B_DER, INPUT);
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {

  B_IZQ_EST = digitalRead(B_IZQ);      // Leemos el estado del boton Izquierdo
  B_ENTER_EST = digitalRead(B_ENTER);  // Leemos el estado del boton Central
  B_DER_EST = digitalRead(B_DER);      // Leemos el estado del boton Derecho

// Comprobamos si se pulsa el boton Izquierdo. De ser asi, el estado es "LOW"
if (B_IZQ_EST == LOW){
  
  for(int i = 0; i < NUM; i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0)); // Utilizando "pixels.Color" podemos setear distintos colores RGB,
                                                    // que van desde 0,0,0 a 255,255,255. En este caso se elige el color Rojo.                                          
    pixels.show();                                  // Enviamos la actualizacion de color
    delay(100);                                     // Esperamos 100 milisegundos
  } 
}

// Comprobamos si se pulsa el boton Central. De ser asi, el estado es "LOW"
else if (B_ENTER_EST == LOW){

  for(int i = 0; i < NUM; i++){
    pixels.setPixelColor(i, pixels.Color(0,255,0)); // Seteamos el color Verde.                                       
    pixels.show();                                  // Enviamos la actualizacion de color
    delay(100);                                     // Esperamos 100 milisegundos
  }
}

// Comprobamos si se pulsa el boton Derecho. De ser asi, el estado es "LOW"
else if (B_DER_EST == LOW){

  for(int i = 0; i < NUM; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255)); // Seteamos el color Azul.                                       
    pixels.show();                                  // Enviamos la actualizacion de color
    delay(100);                                     // Esperamos 100 milisegundos
  }
}


}
