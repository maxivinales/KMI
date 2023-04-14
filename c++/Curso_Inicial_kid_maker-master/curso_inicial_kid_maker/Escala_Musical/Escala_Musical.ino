/*
  Escala Musical.

  Con el Zumbador incluido en nuestra placa, y una libreria reproduciremos
  las diferentes notas musicales. 

  Nota:
  - Es necesaria incluir la libreria <Tone32.h> para esta actividad.
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
 
  http://www.faniot.com.ar
  
*/
#include <Tone32.h>   //Incluimos la libreria necesaria para esta actividad

#define BUZZER_PIN 14 //Definimos el pin donde esta conectado el zumbador y su canal
#define BUZZER_CHANNEL 0

void setup() {}

void loop() {
  //tone(*pin donde esta el buzzer*, *nota*, *tiempo en ms*, *canal del buzzer*)
  tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL); //Encendemos el zumbador a la frecuencia definda
  noTone(BUZZER_PIN, BUZZER_CHANNEL);            //Apagamos el zumbador
  tone(BUZZER_PIN, NOTE_D4, 500, BUZZER_CHANNEL);//Repetimos la tarea anterior, cambiando de nota
  noTone(BUZZER_PIN, BUZZER_CHANNEL);           //Apagamos nuevamente el zumbador
  tone(BUZZER_PIN, NOTE_E4, 500, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  tone(BUZZER_PIN, NOTE_F4, 500, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  tone(BUZZER_PIN, NOTE_G4, 500, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  tone(BUZZER_PIN, NOTE_A4, 500, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  tone(BUZZER_PIN, NOTE_B4, 500, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
}
