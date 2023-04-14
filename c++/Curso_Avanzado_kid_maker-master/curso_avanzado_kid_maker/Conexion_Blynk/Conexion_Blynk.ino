/*************************************************************
 
 Conexion con el Blynk
 
 Este codigo permite conectar el KIT MAKER con la aplicacion BLYNK.
 Blynk permite al usuario controlar la placa Base desde cualquier
 dispositivo Android de una manera practica y simple!.

  Nota:
  - Para realizar esta actividad se requiere las siguientes librerias:
    <WiFi.h> ;<WiFiClient.h> ;<BlynkSimpleEsp32.h>.
  - Es necesario tener la Placa Educativa conectada a su computadora,
   y haber seleccionado la placa correspondiente en herramientas.

  Año 2022
  http://www.faniot.com.ar
 
 *************************************************************
*/
// Datos de mi template, provistos por Blynk, necesarios para realizar la conexion
// Se deben cambiar estos datos, ya que estos nson solo de ejemplo
#define BLYNK_TEMPLATE_ID           "TMPLipoTw-Y8"      //TEMPLATE IDS
#define BLYNK_DEVICE_NAME           "placaEducativa"    //Nombre de mi template


#define BLYNK_PRINT Serial //Definimos el objeto que es utilizado

// Incluimos las Librerias necesarias
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Dirijase a la aplicacion BLYNK para conseguir su TOKEN.
//  Adaptar estos valores a la red WiFi que nos conectemos y a nuestro proyecto de Blynk
char auth[] = "X2wwQmCk9TijuAayvPu6I3VhIW9mBUsh"; // Introducimos el Token de nuestro proyecto de Blynk
char ssid[] = "FAN-IOT";                          // Introducimos el nombre de nuestro WIFI
char pass[] = "f4n10t2020";                       // Introducimos la contraseÃ±a de nuestro WIFI


void setup()
{
  // Debug console
  Serial.begin(115200);               //Iniciamos la comunucacion serial

  Blynk.begin(auth, ssid, pass);    //Inicializamos las configuraciones de Blynk  
}
void loop()
{
  Blynk.run();//Iniciamos la rutina del Blynk
  //se puede ver si la conexión se realizo en el puerto serie
}
