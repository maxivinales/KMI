/*
  Actividad N° 6 - Secuencia Neopixels

  Realiza una secuencia de distintos colores con los neopixels,
  haciendo un cambio en su tonalidad cada 2 segundos.

  Nota:
  - Se debe descargar la libreria NeoPixel en caso de no tenerla - Link: https://github.com/adafruit/Adafruit_NeoPixel
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  por FANIOT
  http://www.faniot.com.ar
  
*/

#define NEO 27  // Definimos el Pin del Neopixel, en este caso es el 27.
#define NUM 4   // Definimos el numero de Neopixels que tenemos, en este caso es 4.

#include <Adafruit_NeoPixel.h>  // Incluimos la libreria Neopixel 

// Le decimos cuantos pixeles tenemos, y que pin usar para enviar las señales.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, NEO, NEO_GRB + NEO_KHZ800);

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {
  
  //Inicializamos la libreria Neopixel 
  pixels.begin();
  //Ajustamos el nivel de brillo en un 20% (0-64)
  pixels.setBrightness(20);
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {

  // El ciclo "for" permite ejecutar sentencias una cantidad de veces definida,
  // en nuestro caso recorremos el numero de pixels (4) hasta lograr encenderlos a todos.
  for(int i = 0; i < NUM; i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0)); // Utilizando "pixels.Color" podemos setear distintos colores RGB,
                                                    // que van desde 0,0,0 a 255,255,255. En este caso se elige el color Rojo.                                          
    pixels.show();                                  // Enviamos la actualizacion de color
    delay(100);                                     // Esperamos 100 milisegundos
  } 

  delay(2000);                                      // Esperamos 2 segundos

  // Repetimos el ciclo anterior
  for(int i = 0; i < NUM; i++){
    pixels.setPixelColor(i, pixels.Color(0,255,0)); // Ahora seteamos el color Verde.                                       
    pixels.show();                                  // Enviamos la actualizacion de color
    delay(100);                                     // Esperamos 100 milisegundos
  }

  delay(2000);                                      // Esperamos 2 segundos

  // Repetimos nuevamente
  for(int i = 0; i < NUM; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255)); // Ahora seteamos el color Azul.                                       
    pixels.show();                                  // Enviamos la actualizacion de color
    delay(100);                                     // Esperamos 100 milisegundos
  }

  delay(2000);                                      // Esperamos 2 segundos

}
