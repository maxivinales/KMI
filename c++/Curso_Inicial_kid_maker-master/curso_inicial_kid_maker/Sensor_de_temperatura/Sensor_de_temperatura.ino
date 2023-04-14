/*
  Actividad N° 8 - Sensor de temperatura

  Hace una lectura de datos proveniente del sensor de temperatura,
  lo muestra por el Monitor Serial y alerta cuando esta excede los
  30°C encendiendo el zumbador.

  Nota:
  - Se debe descargar la libreria OneWire y DallasTemperature en caso de
    no tenerla: Link OneWire: https://www.arduinolibraries.info/libraries/one-wire
                Link DallasTemperature: https://www.arduinolibraries.info/libraries/dallas-temperature
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  por FANIOT
  http://www.faniot.com.ar
  
*/

#define ZUM 14     // Definimos el Pin del zumbador, en este caso es el 14.
#define S_TEMP 19  // Definimos el Pin del sensor de temperatura, en este caso es el 19.

#include <OneWire.h>            // Incluimos la libreria OneWire
#include <DallasTemperature.h>  // Incluimos la libreria DallasTemperature


//Iniciamos los objetos donde estara definido el Pin del sensor    
OneWire oneWire(S_TEMP);                           
DallasTemperature sensors(&oneWire);


// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {
  
  //Inicializamos la comunicacion serial a 115200 bits por segundo:  
  Serial.begin(115200);
  //Inicializamos la libreria DallasTemperature.
  sensors.begin();
  //Inicializamos el pin digital del zumbador como salida.
  pinMode(ZUM, OUTPUT);
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {
  
  sensors.requestTemperatures();                   // Solicitamos la temperatura obtenida por el sensor

  float temperatura = sensors.getTempCByIndex(0);  // Usando la funcion "sensors.getTempCByIndex(0)" obtenemos la temperatura
                                                   // y lo guardamos en una variable del tipo flotante.

  if (temperatura > 30){                           // Evaluamos la variable "temperatura", y si esta es mayor a 30
    digitalWrite(ZUM, HIGH);                       // enviamos una señal "HIGH" que hara sonar el zumbador.
  }else                                                      
    digitalWrite(ZUM, LOW);                        // De no cumplirse la condicion, detenemos el sonido.             
                                      
  Serial.print("Temperatura ambiental: ");         // Imprimimos el texto "Temperatura ambiental:"                                          
  Serial.print(temperatura);                       // Imprimimos la variable
  Serial.println("°C");                            // Imprimimos el simbolo de centigrados, y hacemos un salto de linea
  delay(500);                                      // Esperamos 500 milisegundos por cada lectura
}
