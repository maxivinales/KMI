/*
  Actividad N° 2 - Parpadeo LED
  
  Realiza un parpadeo del LED cada tres segundos.

  Nota:
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
   y haber seleccionado la placa correspondiente en herramientas.

  Año 2022
  por FANIOT
  http://www.faniot.com.ar
  
*/


// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {
  
  //Inicializamos el pin digital 33 como salida.
  pinMode(33, OUTPUT);
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {
  
  digitalWrite(33, HIGH);  // Enciende el LED ("HIGH" es el nivel de voltaje)
  delay(300);              // Espera 300 milisegundos
  digitalWrite(33, LOW);   // Apaga el LED haciendo que el voltaje sea "LOW"
  delay(300);              // Espera 300 milisegundos
  digitalWrite(33, HIGH);  // Enciende el LED
  delay(300);              // Espera 300 milisegundos
  digitalWrite(33, LOW);   // Apaga el LED
  delay(3000);             // Espera 3 segundos
}
