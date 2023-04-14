/*
  Actividad N° 1 - Hola Mundo!

  Imprime un "Hola Mundo!" por unica vez a traves del Monitor Serie.

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
  
  //Inicializamos la comunicacion serial a 115200 bits por segundo:  
  Serial.begin(115200);
  //Esperamos 5 segundos
  delay(5000);
  //Imprime datos en el puerto serie como texto ASCII.
  Serial.println("Hola Mundo!");
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {
  
  // Aqui es donde colocaria el codigo que se
  // ejecutaria todo el tiempo.
}
