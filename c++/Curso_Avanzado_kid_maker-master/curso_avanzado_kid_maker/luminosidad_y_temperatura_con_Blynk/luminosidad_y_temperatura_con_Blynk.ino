/*
  - Luminosidad y Temperatura con Blynk

  Detecta cambios en el nivel de luz y de temperatura ambiental.
  Estos datos son eviados a traves de Blynk.

  Nota:
  - Se debe descargar la libreria OneWire, DallasTemperature y BlynkSimpleESP32 en caso de
    no tenerlas:Link OneWire: https://www.arduinolibraries.info/libraries/one-wire
                Link DallasTemperature: https://www.arduinolibraries.info/libraries/dallas-temperature
                Link BlynkSimpleESP32: https://github.com/blynkkk/blynk-library/releases/latest
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.

  AÃ±o 2022
  http://www.faniot.com.ar
*/

// Datos de mi template, provistos por Blynk, necesarios para realizar la conexion
// Se deben cambiar estos datos, ya que estos nson solo de ejemplo
#define BLYNK_TEMPLATE_ID           "TMPLipoTw-Y8"      //TEMPLATE IDS
#define BLYNK_DEVICE_NAME           "placaEducativa"    //Nombre de mi template


#define LDR 39     // Definimos el Pin del sensor LDR, en este caso es el 39.
#define S_TEMP 19  // Definimos el Pin del sensor de temperatura, en este caso es el 19.

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <OneWire.h>
#include <DallasTemperature.h>

//  Adaptar estos valores a la red WiFi que nos conectemos y a nuestro proyecto de Blynk
char auth[] = "X2wwQmCk9TijuAayvPu6I3VhIW9mBUsh"; // Introducimos el Token de nuestro proyecto de Blynk
char ssid[] = "FAN-IOT";                          // Introducimos el nombre de nuestro WIFI
char pass[] = "f4n10t2020";                       // Introducimos la contraseÃ±a de nuestro WIFI


// Declaramos las variables a enviar
int luminosidad = 0;
float temperatura = 0;
//int cont=0;

//Iniciamos los objetos de los pines de los sensores y del wifi
OneWire oneWire(S_TEMP);
DallasTemperature sensors(&oneWire);

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup()
{
  Blynk.begin(auth, ssid, pass);    //Inicializamos las configuraciones de Blynk  
  sensors.begin();                  //Inicializamos la libreria DallasTemperature.
}

// La funcion "loop" se ejecuta una y otra vez constantemente.
void loop()
{
  luminosidad = map(analogRead(LDR), 4095, 1200, 100, 0);  // Leemos el LDR, usamos la funcion "map" para convertir el valor analogico 
                                                           // de 1200-4095 a 0-100 el cual sera nuestro porcentaje, y lo guardamos en 
                                                           // una variable del tipo entero.
  
  sensors.requestTemperatures();                           // Solicitamos la temperatura obtenida por el sensor
  temperatura = sensors.getTempCByIndex(0);                // Usando la funcion "sensors.getTempCByIndex(0)" obtenemos la temperatura
                                                           // y lo guardamos en una variable del tipo flotante.
                                                           
  Blynk.run();                                             // Esta funcion es necesaria para procesar los comandos y mantener la conexion 

  Blynk.virtualWrite(V0, luminosidad);                     // Enviamos el dato de la luminosidad al puerto virtual V0 de Blynk
  Blynk.virtualWrite(V1, temperatura);                     // Enviamos el dato de la temperatura al puerto virtual V1 de Blynk

  delay(500);                                              // Esperamos 1 segundo para enviar de nuevo los datos

}
