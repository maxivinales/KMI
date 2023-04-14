/*************************************************************
 Menu interactivo:
 
 En este codigo podras navegar a traves de un menu usando los botones
 de la placa de interfaz. En el menu se visualizaran valores de
 luminosidad y temperatura. Tambien vas a poder controlar un buzzer.
 
  Nota:
  - Para realizar esta actividad se requiere las siguientes librerias:
    <OneWire.h>; <DallasTemperature.h>; <Adafruit_GFX.h>; <Adafruit_SSD1306.h> 
  - Es necesario tener la Placa Educativa conectada a su computadora,
   y haber seleccionado la placa correspondiente en herramientas.

  Año 2021
  http://www.faniot.com.ar
 
 *************************************************************
*/

// Se incluyen las librerías necesarias
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>            
#include <DallasTemperature.h>  

#define S_TEMP 19                 // Se define el pin del sensor de temperatura

OneWire oneWire(S_TEMP);                           
DallasTemperature sensors(&oneWire);

#define LDR 39                   // Definimos el Pin del sensor LDR, en este caso es el 39.
#define ZUM 14                   // Definimos el Pin del zumbador, en este caso es el 14.

#define B_IZQ 13                 // Definimos el Pin del boton Izquierdo, en este caso es el 13.
#define B_ENTER 15               // Definimos el Pin del boton Central, en este caso es el 15.
#define B_DER 23                 // Definimos el Pin del boton Derecho, en este caso es el 23.

#define ANCHO_OLED 128                                                      // Definimos el tamaño en Ancho de nuestro OLED
#define ALTO_OLED 32                                                        // Definimos el tamaño en Alto de nuestro OLED
Adafruit_SSD1306 display(ANCHO_OLED, ALTO_OLED, &Wire, -1);                 // Configuramos las caracteristicas de nuestra pantalla OLED

int B_IZQ_EST = 0;               // Variable para leer el estado del boton Izquierdo
int B_ENTER_EST = 0;             // Variable para leer el estado del boton Central
int B_DER_EST = 0;               // Variable para leer el estado del boton Derecho

const long interval = 1000;         // Se declaran las variables para controlar el delay en el BUZZER
unsigned long previousMillis = 0;
int ZUMState = LOW;
int menu = 0;
bool est = false;

void setup() {
  Serial.begin(115200);
  
  pinMode(B_IZQ, INPUT);            // Declaramos los botones como entradas y al BUZZER como salida
  pinMode(B_ENTER, INPUT);
  pinMode(B_DER, INPUT);
  pinMode(ZUM, OUTPUT);

  sensors.begin();
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Iniciamos la comunicacion con el OLED
  display.clearDisplay();                    // Limpiamos la pantalla
  display.setTextSize(2);                    // Configuramos el tamaño del texto que se va a mostrar
  display.setTextColor(WHITE);               // Configuramos el color del texto, en este caso es WHITE (Blanco)
  display.display();                         // Refrescamos el display

}

void loop() {
  
  sensors.requestTemperatures();                              // Solicitamos la lectura de temperatura al sensor
  int temperatura = sensors.getTempCByIndex(0);               // Guardamos la temperatura en una variable
  int luminosidad = map(analogRead(LDR), 1023, 0, 100, 0);    // Usamos analogRead apra conseguir los valores de luminosidad

  unsigned long currentMillis = millis();                     // Se usa la funcion millis y se la guarda para el delay en el buzzer
  
  if (digitalRead(B_IZQ) == LOW){                             // Se crean las condiciones para controlar el menu
    menu--;
    est = false;
    digitalWrite(ZUM, LOW);
    delay(50);
    }
  if(digitalRead(B_DER) == LOW){
    menu++;
    est = false;
    digitalWrite(ZUM, LOW);
    delay(50);
    }
  if(digitalRead(B_ENTER) == LOW){
    est = true;
    }
  if(menu > 3 || menu < 0){
    menu = 0;
    }
    
  switch(menu){                                // Se usa la funcion switch para navegar por el menu
    case 0:
    display.clearDisplay();                    // Limpiamos el display
    display.setCursor(20, 10);                 // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.println("KIT MAKER");              // Imprimimos en la pantalla "KIT MAKER"
    display.display();                         // Refrescamos el display
    break;

    case 1:
    display.clearDisplay();                    // Limpiamos el display
    display.setCursor(20, 10);                 // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.print("Temp: ");                   // Imprimimos en la pantalla "Temp: "
    display.print(temperatura);                // Imprimimos la temperatura en el display
    display.display();                         // Refrescamos el display
    break;

    case 2:
    display.clearDisplay();                    // Limpiamos el display
    display.setCursor(20, 10);                 // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.print("Lum: ");                    // Imprimimos en la pantalla "Lum: "
    display.print(luminosidad);                // Imprimimos el nivel de luminosidad en el display
    display.display();                         // Refrescamos el display
    delay(50);                                 // Pequeño delay para relentizar la lectura del LDR
    break;

    case 3:
    display.clearDisplay();
    display.setCursor(20, 10);                 // Configuramos la ubicacion en pantalla de nuestro texto (X;Y)
    display.println("Buz");                    // Imprimimos en la pantalla "Buz"
    display.display();                         // Refrescamos el display
    if (est == true){
      if (currentMillis - previousMillis >= interval) { // Delay para encender y apagar buzzer sin usar la funcion delay()
        previousMillis = currentMillis;
        if (ZUMState == LOW) {
          ZUMState = HIGH;
        }      
        else {
          ZUMState = LOW;
        }
    digitalWrite(ZUM, ZUMState);
      }
    }
    break;
  }
}
