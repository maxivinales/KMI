/*
  Actividad N° 2 - Preguntas y respuestas

  Imprime en la pantalla del OLED preguntas al azar, y permite
  seleccionar por medio de los botones cual es la correcta.
  Ademas, al finalizar el juego muestra en pantalla la cantidad
  de preguntas correctas e incorrectas.

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
int preguntas, puntosC, puntosI, i; // Variables para realizar distintas accciones dentro del programa

// Variables para el buzzer
int freq = 2000;
int channel = 0;
int resolution = 8;

// Le decimos cuantos pixeles tenemos, y que pin usar para enviar las señales.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, NEO, NEO_GRB + NEO_KHZ800);

//Iniciamos el objeto para el OLED, con el tamaño y la conexion por I2C.
Adafruit_SSD1306 display(ANCHO_OLED, ALTO_OLED, &Wire, -1);

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {

  //Inicializamos la libreria Neopixel
  pixels.begin();
  //Ajustamos el nivel de brillo en un 5% (0-64)
  pixels.setBrightness(5);

  //Inicializamos los pines digitales de los tres botones como entrada.
  pinMode(B_IZQ, INPUT);
  pinMode(B_ENTER, INPUT);
  pinMode(B_DER, INPUT);

  //Inicializamos las configuraciones del zumbador.
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(ZUM, channel);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Iniciamos la comunicacion con el OLED
  display.clearDisplay();                    // Limpiamos la pantalla
  display.setTextColor(WHITE);               // Configuramos el color del texto, en este caso es WHITE (Blanco)
  display.setTextSize(1);                    // Configuramos el tamaño del texto que se va a mostrar
  preguntas = 0;                             // Seteamos la variable "preguntas" en 0
}

void loop() {

  // Con esta condicion mantenemos encendido los Neopixels 1 y 4
  // mientras la variable "preguntas" sea distinta de 5 y 0.
  if (preguntas != 5 && preguntas != 0) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));
    pixels.show();
  }

  B_IZQ_EST = digitalRead(B_IZQ);      // Leemos el estado del boton Izquierdo
  B_ENTER_EST = digitalRead(B_ENTER);  // Leemos el estado del boton Central
  B_DER_EST = digitalRead(B_DER);      // Leemos el estado del boton Derecho


  // Con esta funcion controlaremos todo el flujo de nuestro programa y
  // a partir del valor de la variable "preguntas" mostraremos las preguntas,
  // como asi tambien las acciones ante cada respuesta elegida.
  switch (preguntas) {
    case 0:
      pixels.clear();
      display.setCursor(20, 10);         // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
      display.print("INICIANDO JUEGO");  // Escribimos la pregunta con los espacios necesarios para ajustar a la pantalla.
      display.display();

      for (int j = 0; j < 4; j++) {
        pixels.setPixelColor(j, pixels.Color(0, 0, 255));
        pixels.show();
        ledcWrite(channel, 20);
        delay(10);
        ledcWrite(channel, 0);
        delay(1000);
      }

      preguntas++;
      break;

    case 1: //PREGUNTA 1
      pixels.clear();
      display.clearDisplay();                                 // Limpiamos la pantalla del OLED
      display.setCursor(0, 5);                                // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
      display.print("  C02 ES DIOXIDO DE          CARBONO");  // Escribimos la pregunta con los espacios necesarios para ajustar a la pantalla.
      display.setCursor(110, 25);
      display.print("1/4");
      display.display();                                      // Enviamos la actualizacion

      if (B_IZQ_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(40, 12);
        display.print("VERDADERO");
        display.setCursor(110, 25);
        display.print("1/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(0, 255, 0));
        pixels.setPixelColor(2, pixels.Color(0, 255, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosC = puntosC + 1;
        preguntas ++;
      }
      else if (B_DER_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(50, 12);
        display.print("FALSO");
        display.setCursor(110, 25);
        display.print("1/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(255, 0, 0));
        pixels.setPixelColor(2, pixels.Color(255, 0, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosI = puntosI + 1;
        preguntas ++;
      }
      break;

    case 2: //PREGUNTA 2
      pixels.clear();
      display.clearDisplay();
      display.setCursor(3, 5);
      display.print(" EGIPTO SE ENCUENTRA AL NORESTE DE AFRICA ");
      display.setCursor(110, 25);
      display.print("2/4");
      display.display();

      if (B_IZQ_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(40, 12);
        display.print("VERDADERO");
        display.setCursor(110, 25);
        display.print("2/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(0, 255, 0));
        pixels.setPixelColor(2, pixels.Color(0, 255, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosC = puntosC + 1;
        preguntas ++;
      }
      else if (B_DER_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(50, 12);
        display.print("FALSO");
        display.setCursor(110, 25);
        display.print("2/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(255, 0, 0));
        pixels.setPixelColor(2, pixels.Color(255, 0, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosI = puntosI + 1;
        preguntas ++;
      }

      break;

    case 3: //PREGUNTA 3
      pixels.clear();
      display.clearDisplay();
      display.setCursor(3, 5);
      display.print("LA FLOR ES UN ORGANO REPRODUCTOR DE LAS          PLANTAS ");
      display.setCursor(110, 25);
      display.print("3/4");
      display.display();

      if (B_IZQ_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(40, 12);
        display.print("VERDADERO");
        display.setCursor(110, 25);
        display.print("3/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(0, 255, 0));
        pixels.setPixelColor(2, pixels.Color(0, 255, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosC = puntosC + 1;
        preguntas ++;
      }
      else if (B_DER_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(50, 12);
        display.print("FALSO");
        display.setCursor(110, 25);
        display.print("3/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(255, 0, 0));
        pixels.setPixelColor(2, pixels.Color(255, 0, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosI = puntosI + 1;
        preguntas ++;
      }

      break;

    case 4: //PREGUNTA 4
      pixels.clear();
      display.clearDisplay();
      display.setCursor(3, 0);  // Taipéi
      //display.print("    TOMAR ALCOHOL    DESTRUYE TUS CELULAS      CEREBRALES ");
      display.print("    TAIPEI ES LA      CAPITAL DE TAIWAN ");
      display.setCursor(110, 25);
      display.print("4/4");
      display.display();

      if (B_IZQ_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(40, 12);
        display.print("VERDADERO");
        display.setCursor(110, 25);
        display.print("4/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(0, 255, 0));
        pixels.setPixelColor(2, pixels.Color(0, 255, 0));  
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosC = puntosC + 1;
        preguntas ++;

      }
      else if (B_DER_EST == LOW) {
        ledcWrite(channel, 30);
        delay(20);
        ledcWrite(channel, 0);
        display.clearDisplay();
        display.setCursor(50, 12);
        display.print("FALSO");
        display.setCursor(110, 25);
        display.print("4/4");
        display.display();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(255, 0, 0));
        pixels.setPixelColor(2, pixels.Color(255, 0, 0));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));
        pixels.show();
        delay(3000);
        puntosI = puntosI + 1;
        preguntas ++;
      }

      break;

    case 5: //FINALIZAMOS
      pixels.clear();
      display.clearDisplay();
      display.setCursor(21, 0);
      display.print("JUEGO TERMINADO");
      display.setCursor(0, 15);
      display.print("CORRECTAS: ");
      display.print(puntosC);
      display.setCursor(0, 25);
      display.print("INCORRECTAS: ");
      display.print(puntosI);
      display.display();

      for (i = 0; i < puntosC; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      }

      for (i = i; i <=  3; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      }

      pixels.show();
      break;
  }

}
