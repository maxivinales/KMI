/*
  Semaforo

  Creamos un Semaforo con los leds que incorpora la Placa Educativa.

  Nota:
  - No se requiere de librerias para realizar esta actividad.
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  http://www.faniot.com.ar
  
*/

int ledRojo = 32;     //Declaro en que pin se encuentra mi led Rojo
int ledAmarillo = 33; //Declaro en que pin se encuentra mi led Amarillo
int ledVerde = 25;    //Declaro en que pin se encuentra mi led Verde

void setup(){
              pinMode(ledRojo, OUTPUT);            // Inicializo mis Pines como Salidas 
              pinMode(ledAmarillo, OUTPUT);
              pinMode(ledVerde, OUTPUT);
             }//Final del setup

void loop(){
            digitalWrite(ledRojo, HIGH);//Damos un estado alto al led Rojo
            delay(5000);                //Generamos una espera de 5 segundos
            digitalWrite(ledRojo, LOW);//Damos un estado bajo al led Rojo
            digitalWrite(ledAmarillo, HIGH);//Damos un estado alto al led Amarillo
            delay(2000);                //Generamos una espera de 2 segundos
            digitalWrite(ledAmarillo, LOW);//Damos un estado bajo al led Amarillo
            digitalWrite(ledVerde, HIGH);//Damos un estado alto al led Verde
            delay(5000);                //Generamos una espera de 5 segundos
            digitalWrite(ledVerde, LOW);//Damos un estado bajo al led Verde
            digitalWrite(ledAmarillo, HIGH);//Damos un estado alto al led Amarillo
            delay(2000);                //Generamos una espera de 2 segundos
            digitalWrite(ledAmarillo, LOW);//Damos un estado bajo al led Amarillo
            }//Final de el loop 
