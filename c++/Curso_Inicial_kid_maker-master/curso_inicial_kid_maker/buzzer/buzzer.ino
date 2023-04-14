/*
  Actividad N° 5 - Zumbador y LDR

  Detecta cambios en el nivel de luz ambiental haciendo uso
  de un sensor LDR, y a su vez indica de manera porcentual
  los parametros sensados a traves del Monitor Serial.
  Cuando el nivel de luminosidad es inferior a los 50%,
  activa un zumbador.

  Nota:
  - No se requiere ningun tipo de componente extra para esta actividad.
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  por FANIOT
  http://www.faniot.com.ar
  
*/

#define LDR 39   // Definimos el Pin del sensor LDR, en este caso es el 39.
#define ZUM 14   // Definimos el Pin del zumbador, en este caso es el 14.

// La funcion "setup" se ejecuta una vez al resetear o encender la placa.
void setup() {
  
  //Inicializamos la comunicacion serial a 9600 bits por segundo:  
  Serial.begin(115200);
  //Inicializamos el pin digital del zumbador como salida.
  pinMode(ZUM, OUTPUT); 
}


// La funcion "loop" se ejecuta una y otra vez constantemente. 
void loop() {
  
  
  int luminosidad = map(analogRead(LDR), 4095, 0, 100, 0);  // Leemos el LDR, usamos la funcion "map" para convertir el valor analogico 
                                                            // de 0-1023 a 0-100 el cual sera nuestro porcentaje, y lo guardamos en 
                                                            // una variable del tipo entero.
                                                            
  if (luminosidad < 50){                                    // Evaluamos la variable "luminosidad", y si esta es menor a 50
    digitalWrite(ZUM, HIGH);                                // enviamos una señal "HIGH" que hara sonar el zumbador.
  }else                                                      
    digitalWrite(ZUM, LOW);                                 // De no cumplirse la condicion, detenemos el sonido.                                                                              
                                                            
  Serial.print("Luz ambiental: ");                          // Imprimimos el texto "Luz ambiental:"
  Serial.print(luminosidad);                                // Imprimimos la variable
  Serial.println("%");                                      // Imprimimos el simbolo de porcentaje, y hacemos un salto de linea
  delay(500);                                               // Esperamos 500 milisegundos por cada lectura
}
