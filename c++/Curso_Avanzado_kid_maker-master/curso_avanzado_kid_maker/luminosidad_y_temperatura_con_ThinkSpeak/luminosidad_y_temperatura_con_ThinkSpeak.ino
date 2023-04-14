/*
  Actividad N° 4 - Luminosidad y Temperatura con ThinkSpeak

  Detecta cambios en el nivel de luz y de temperatura ambiental.
  Estos datos son eviados a traves de ThinkSpeak.

  Nota:
  - Se debe descargar la libreria OneWire y DallasTemperature en caso de
    no tenerlas:Link OneWire: https://www.arduinolibraries.info/libraries/one-wire
                Link DallasTemperature: https://www.arduinolibraries.info/libraries/dallas-temperature
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.

  Año 2022
  http://www.faniot.com.ar
*/

#define LDR 39     // Definimos el Pin del sensor LDR, en este caso es el 39.
#define S_TEMP 19  // Definimos el Pin del sensor de temperatura, en este caso es el 19.

// Incluimos las librerias necesarias
#include <WiFi.h>
#include "ThingSpeak.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// Configuramos la conexion a ThinkSpeak
char ssid[] = "FAN-IOT";                          // Introducimos el nombre de nuestro WIFI
char pass[] = "f4n10t2020";                       // Introducimos la contraseÃ±a de nuestro WIFI

/*
Para poder visualizar este programa es necesario crearnos una
cuenta en MathWorks y con ella acceder a ThingSpeak, para luego
crearnos un canal
*/
unsigned long myChannelNumber = 1404208;          // Introducimos el numero del canal que creamos
const char * myWriteAPIKey = "IRR3VJPF71PX4TS3";  // Introducimos la "API Key" de nuestro canal

// Declaramos las variables a enviar
int luminosidad = 0;
int temperatura = 0;

//Iniciamos los objetos de los pines de los sensores y del wifi
OneWire oneWire(S_TEMP);
DallasTemperature sensors(&oneWire);
WiFiClient  client;

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {

  //Inicializamos el monitor serial a 115200 Baudios
  Serial.begin(115200);
  //Inicializamos el modo Wifi
  WiFi.mode(WIFI_STA);
  //Inicializamos ThingSpeak
  ThingSpeak.begin(client);
  //Inicializamos la libreria DallasTemperature.
  sensors.begin();
}

void loop() {

  // Verificamos la conexion del WIFI y lo mostramos a traves del
  // monitor serial, esto nos permitira saber el estado en el que
  // se encuentra.
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("");
    Serial.print("Intentando conectarse al WIFI: ");
    Serial.print(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConexion exitosa!");
  }

  ThingSpeak.setField(1, luminosidad);     // Seteamos el canal 1 para imprimir la luminosidad
  ThingSpeak.setField(2, temperatura);     // Seteamos el canal 2 para imprimir la temperatura

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); // Escribimos en los canales de ThingSpeak

  if (x == 200) {
    Serial.println("Actualizacion enviada.");              // Verificamos que la actualizacion de datos
  }                                                        // se haya enviado correctamente.
  else {
    Serial.println("Error al enviar actualizacion!");
  }

  luminosidad = map(analogRead(LDR), 4095, 1200, 100, 0);  // Leemos el LDR, usamos la funcion "map" para convertir el valor analogico 
                                                           // de 1200-4095 a 0-100 el cual sera nuestro porcentaje, y lo guardamos en 
                                                           // una variable del tipo entero.
                                                             
  sensors.requestTemperatures();                           // Solicitamos la temperatura obtenida por el sensor
  temperatura = sensors.getTempCByIndex(0);                // Usando la funcion "sensors.getTempCByIndex(0)" obtenemos la temperatura
                                                           // y lo guardamos en una variable del tipo flotante.

  delay(15000); // Esperamos 15 segundos entre cada dato enviado
}
