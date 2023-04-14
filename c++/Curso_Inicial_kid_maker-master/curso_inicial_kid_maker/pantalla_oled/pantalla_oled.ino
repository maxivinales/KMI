/*
  Actividad N° 9 - Pantalla OLED

  Imprime textos/parametros de cualquier tipo, a traves de la
  pantalla OLED que incorpora la Placa Educativa.

  Nota:
  - Se debe descargar la libreria Adafruit_GFX y Adafruit_SSD1306 en caso de
    no tenerlas, puede descargarse desde el gestor de librerias de Arduino o
    externamente.
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  por FANIOT
  http://www.faniot.com.ar
  
*/

#define ANCHO_OLED 128  // Definimos el tamaño en Ancho de nuestro OLED
#define ALTO_OLED 32    // Definimos el tamaño en Alto de nuestro OLED

#include <Wire.h>              // Incluimos la libreria Wire
#include <Adafruit_GFX.h>      // Incluimos la libreria Adafruit_GFX
#include <Adafruit_SSD1306.h>  // Incluimos la libreria Adafruit_SSD1306


//Iniciamos el objeto para el OLED, con el tamaño y la conexion por I2C.  
Adafruit_SSD1306 display(ANCHO_OLED, ALTO_OLED, &Wire, -1);


// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {
  
  //Inicializamos la comunicacion serial a 115200 bits por segundo:  
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Iniciamos la comunicacion con el OLED
  display.clearDisplay();                    // Limpiamos la pantalla
  display.setTextSize(2);                    // Configuramos el tamaño del texto que se va a mostrar
  display.setTextColor(WHITE);               // Configuramos el color del texto, en este caso es WHITE (Blanco)
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {

   display.clearDisplay();       // Limpiamos la pantalla del OLED
   display.setCursor(40, 10);    // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
   display.println("HOLA!");     // Imprimimos en la pantalla "HOLA!"
   display.display();            // Enviamos la actualizacion

     delay(1000);                // Esperamos 1 segundo
   

 for (int i = 1; i <= 50; i++){  // Realizamos un conteo del 1 al 50
    display.clearDisplay();      // y lo mostramos en el OLED.
    display.setCursor(60, 10);
    display.println(i);
    display.display(); 
    delay(100);
  }

     delay(1000);                //Esperamos 1 segundo
}
