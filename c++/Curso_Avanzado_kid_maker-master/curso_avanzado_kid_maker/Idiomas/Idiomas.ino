/*
  Actividad N° 1 - Hola!

  Imprime un "Hola!" en 3 diferentes idiomas a traves de
  la pantalla OLED, haciendo uso de los botones que incorpora la
  Placa Educativa.


  Nota:
  - Se debe descargar la libreria NeoPixel en caso de no tenerla - Link: https://github.com/adafruit/Adafruit_NeoPixel
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.

  Año 2022
  http://www.faniot.com.ar
*/

#define NEO 27          // Definimos el Pin del Neopixel, en este caso es el 27.
#define NUM 4           // Definimos el numero de Neopixels que tenemos, en este caso es 4.
#define B_IZQ 13        // Definimos el Pin del boton Izquierdo, en este caso es el 13.
#define B_ENTER 15      // Definimos el Pin del boton Central, en este caso es el 15.
#define B_DER 23        // Definimos el Pin del boton Derecho, en este caso es el 23.
#define ZUM 14          // Definimos el Pin del zumbador, en este caso es el 14.
#define ANCHO_OLED 128  // Definimos el tamaño en Ancho de nuestro OLED
#define ALTO_OLED 32    // Definimos el tamaño en Alto de nuestro OLED

#include <Adafruit_NeoPixel.h>  // Incluimos la libreria Neopixel
#include <Wire.h>               // Incluimos la libreria Wire
#include <Adafruit_GFX.h>       // Incluimos la libreria Adafruit_GFX
#include <Adafruit_SSD1306.h>   // Incluimos la libreria Adafruit_SSD1306

int B_IZQ_EST = 0;    // Variable para leer el estado del boton Izquierdo
int B_ENTER_EST = 0;  // Variable para leer el estado del boton Central
int B_DER_EST = 0;    // Variable para leer el estado del boton Derecho

// Le decimos cuantos pixeles tenemos, y que pin usar para enviar las señales.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, NEO, NEO_GRB + NEO_KHZ800);

//Iniciamos el objeto para el OLED, con el tamaño y la conexion por I2C.
Adafruit_SSD1306 display(ANCHO_OLED, ALTO_OLED, &Wire, -1);

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
  //Inicializamos el pin digital del zumbador como salida.
  pinMode(ZUM, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Iniciamos la comunicacion con el OLED
  display.clearDisplay();                    // Limpiamos la pantalla
  display.setTextSize(2);                    // Configuramos el tamaño del texto que se va a mostrar
  display.setTextColor(WHITE);               // Configuramos el color del texto, en este caso es WHITE (Blanco)
}


// La funcion "loop" se ejecuta una y otra vez constantemente.
void loop() {

  B_IZQ_EST = digitalRead(B_IZQ);      // Leemos el estado del boton Izquierdo
  B_ENTER_EST = digitalRead(B_ENTER);  // Leemos el estado del boton Central
  B_DER_EST = digitalRead(B_DER);      // Leemos el estado del boton Derecho

  // Comprobamos si se pulsa el boton Izquierdo. De ser asi, el estado es "LOW"
  if (B_IZQ_EST == LOW) {

    display.clearDisplay();       // Limpiamos la pantalla del OLED
    display.setCursor(40, 10);    // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.println("HOLA!");     // Imprimimos en la pantalla "HOLA!"
    display.display();            // Enviamos la actualizacion

    digitalWrite(ZUM, HIGH);                               // Enviamos una señal "HIGH" que hara sonar el zumbador
    delay(100);                                            // Esperamos 100 milisegundos
    digitalWrite(ZUM, LOW);                                // Apagamos el zumbador

    pixels.clear();                                        // Limpiamos los Neopixels
    pixels.setPixelColor(0, pixels.Color(0, 255, 255));    // Seteamos los colores para formar la bandera de Argentina
    pixels.setPixelColor(1, pixels.Color(255, 255, 255));
    pixels.setPixelColor(2, pixels.Color(255, 255, 255));
    pixels.setPixelColor(3, pixels.Color(0, 255, 255));
  }

  // Comprobamos si se pulsa el boton Central. De ser asi, el estado es "LOW"
  else if (B_ENTER_EST == LOW) {

    display.clearDisplay();       // Limpiamos la pantalla del OLED
    display.setCursor(40, 10);    // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.println("HELLO!");    // Imprimimos en la pantalla "HELLO!"
    display.display();            // Enviamos la actualizacion

    digitalWrite(ZUM, HIGH);                           // Enviamos una señal "HIGH" que hara sonar el zumbador
    delay(100);                                        // Esperamos 100 milisegundos
    digitalWrite(ZUM, LOW);                            // Apagamos el zumbador

    pixels.clear();                                    // Limpiamos los Neopixels
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Seteamos los colores para formar la bandera de Estados Unidos
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));
  }

  // Comprobamos si se pulsa el boton Derecho. De ser asi, el estado es "LOW"
  else if (B_DER_EST == LOW) {

    display.clearDisplay();       // Limpiamos la pantalla del OLED
    display.setCursor(40, 10);    // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.println("HALLO!");    // Imprimimos en la pantalla "HELLO!"
    display.display();            // Enviamos la actualizacion

    digitalWrite(ZUM, HIGH);                            // Enviamos una señal "HIGH" que hara sonar el zumbador
    delay(100);                                         // Esperamos 100 milisegundos
    digitalWrite(ZUM, LOW);                             // Apagamos el zumbador

    pixels.clear();                                     // Limpiamos los Neopixels
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));   // Seteamos los colores para formar la bandera de Alemania
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 255, 0));
    pixels.setPixelColor(3, pixels.Color(255, 255, 0));

  }
  pixels.show();                                        // Enviamos la actualizacion de color
}
