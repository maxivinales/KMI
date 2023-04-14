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

  Año 2022
  http://www.faniot.com.ar
*/

// Datos de mi template, provistos por Blynk, necesarios para realizar la conexion
// Se deben cambiar estos datos, ya que estos nson solo de ejemplo
#define BLYNK_TEMPLATE_ID           "TMPLipoTw-Y8"      //TEMPLATE IDS
#define BLYNK_DEVICE_NAME           "placaEducativa"    //Nombre de mi template


#define LDR 39     // Definimos el Pin del sensor LDR, en este caso es el 39.
#define S_TEMP 19  // Definimos el Pin del sensor de temperatura, en este caso es el 19.

#define ZUM 14   // Definimos el Pin del zumbador, en este caso es el 14.

#define NEO 27  // Definimos el Pin del Neopixel, en este caso es el 27.
#define NUM 4   // Definimos el numero de Neopixels que tenemos, en este caso es 4.

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>  // Incluimos la libreria Neopixel 
#include <OneWire.h>            // Incluimos la libreria para trabajar con OneWire 
#include <DallasTemperature.h>

//  Adaptar estos valores a la red WiFi que nos conectemos y a nuestro proyecto de Blynk
char auth[] = "X2wwQmCk9TijuAayvPu6I3VhIW9mBUsh"; // Introducimos el Token de nuestro proyecto de Blynk
char ssid[] = "FAN-IOT";                          // Introducimos el nombre de nuestro WIFI
char pass[] = "f4n10t2020";                       // Introducimos la contraseÃ±a de nuestro WIFI


// Declaramos las variables a enviar
int luminosidad = 0;                              //variable luminosidad, para mandar a Blynk
float temperatura = 0;                            //variable temperatura, para mandar a Blynk
uint8_t R=0, G=0, B=0;                            //intensidad de colores rojo-verde-azul 
                                                  //que estan entre 0 y 255
bool buzzer=0;                                    //bit que indica si el buzzer debe encenderse

//Iniciamos los objetos de los pines de los sensores
OneWire oneWire(S_TEMP);
DallasTemperature sensors(&oneWire);

// Le decimos cuantos pixeles tenemos, y que pin usar para enviar las señales.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM, NEO, NEO_GRB + NEO_KHZ800);

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup()
{
  Blynk.begin(auth, ssid, pass);    //Inicializamos las configuraciones de Blynk  
  sensors.begin();                  //Inicializamos la libreria DallasTemperature.

  pixels.begin();                   //Inicializamos la libreria Neopixel
  pixels.setBrightness(20);         //Ajustamos el nivel de brillo en un 20% (0-64)

  pinMode(ZUM, OUTPUT);             //Inicializamos el pin digital del zumbador como salida.
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

  for(int i = 0; i < NUM; i++){
      pixels.setPixelColor(i, pixels.Color(R,G,B)); // Utilizando "pixels.Color" podemos setear distintos colores RGB,
                                                      // que van desde 0,0,0 a 255,255,255. En este caso se elige el color Rojo.                                          
      pixels.show();                                  // Enviamos la actualizacion de color
  } 

  if(buzzer==true){                                 //veo si el bit para activar el buzzer es verdadero
    digitalWrite(ZUM, !digitalRead(ZUM));           //entonces hago "parpadear" el buzzer
  }else{
    digitalWrite(ZUM, LOW);                         //de lo contrario lo dejo apagado
  }
    
  delay(5);                                        // Esperamos para enviar de nuevo los datos

}

BLYNK_WRITE(V2)       //lectura del pin virtual V2, que es el valor de R
{   
  R = param.asInt(); // tomo el valor
}

BLYNK_WRITE(V3)       //lectura del pin virtual V3, que es el valor de G
{   
  G = param.asInt(); // tomo el valor  
}

BLYNK_WRITE(V4)       //lectura del pin virtual V4, que es el valor de B
{   
  B = param.asInt(); // tomo el valor    
}

BLYNK_WRITE(V5)       //lectura del pin virtual V5, que comanda el buzzer
{   
  if(param.asInt()>0){  //si es mayor a cero 
    buzzer=true;        //hace que el bit del buzzer sea verdadero
  }else{                //si no
    buzzer=false;       //lo deja en falso
  }
}
