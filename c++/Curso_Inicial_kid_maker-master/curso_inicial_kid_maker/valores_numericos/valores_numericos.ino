/*
   Valores Numericos

    En este ejemplo podremos enviar un numero del 1 al 9
    empleando el monitor serial y los leds en la placa brillaran 
    la misma cantidad de veces. 

  Nota:
  - No se requiere de ninguna libreria adicional para esta actividad  
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  http://www.faniot.com.ar
  
*/

int option;              //Declaro una variable que utilizare posteriormente
int ledRojo = 32;       //Declaro en que pin se encuentra mi led Rojo
int ledAmarillo = 33;  //Declaro en que pin se encuentra mi led Amarillo
int ledVerde = 25;    //Declaro en que pin se encuentra mi led Verde


void setup(){
 Serial.begin(115200);                 //Iniciamos la comunicacion serial
 pinMode(ledRojo, OUTPUT);         // Inicializo los pines digitales de los tres siguientes como salida. 
 pinMode(ledAmarillo, OUTPUT);
 pinMode(ledVerde, OUTPUT);
}//Final del Setup

void loop(){    
  if (Serial.available()>0){                              //si existe información pendiente  
    char option = Serial.read();                                                   //leeemos la opcion   
    if (option >= '1' && option <= '9'){                                          //si la opcion esta entre '1' y '9'
        option -= '0';                           //restamos el valor '0' para obtener el numero enviado
        for(int i=0;i<option;i++){
           digitalWrite(ledRojo, HIGH);         //Ponemos al Led Rojo en alto
           digitalWrite(ledAmarillo, HIGH);    //Ponemos al Led Rojo en alto
           digitalWrite(ledVerde, HIGH);      //Ponemos al Led Rojo en alto
           delay(100);                         //Generamos una espera de 100ms
           digitalWrite(ledRojo, LOW);        //Ponemos al Led Rojo en bajo
           digitalWrite(ledAmarillo, LOW);   //Ponemos al Led Rojo en bajo
           digitalWrite(ledVerde, LOW);     //Ponemos al Led Rojo en bajo
           delay(200);                     //Generamos una espera de 200ms
           }
       }
}
}//Final del Loop
