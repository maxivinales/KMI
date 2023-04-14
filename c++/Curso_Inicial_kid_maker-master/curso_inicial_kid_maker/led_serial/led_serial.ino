/*
   Leds Serial

    En este ejemplo podremos enviar una orden al dispositivo por medio 
    del puerto serie de la computadora.Para ello enviamos un carácter a 
    la placa empleando el monitor serial. En caso de enviar 'a' la placa 
    apaga los LEDs, y en caso de enviar 'b' lo enciende.

  Nota:
  - No se requiere de ninguna libreria adicional para esta actividad  
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  http://www.faniot.com.ar
  
*/

int option=NULL;              //Declaro una variable para asociarla a mi eleccion
int ledRojo = 32;       //Declaro en que pin se encuentra mi led Rojo
int ledAmarillo = 33;  //Declaro en que pin se encuentra mi led Amarillo
int ledVerde = 25;    //Declaro en que pin se encuentra mi led Verde

void setup(){
  Serial.begin(115200);//Iniciamos la comunicacion serial
  // Inicializo los pines digitales de los tres siguientes como salida. 
  pinMode(ledRojo, OUTPUT);              
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  delay(5000);        //espero 5 segundos para dar tiempo a entrar al monitor serie
} 

void loop(){ 
  if(option==NULL || option=='a' || option=='b'){//si es option cero quiere decir que es el programa apenas inicio
                                              //sinó tine que imprimir igual ya que el usuario mando ordenes
    Serial.println("Seleccione una opcion para continuar: a= Apagado - b=encendido");//entonces escribo mis opciones

    option=1;                              //le doy un valor a option para que no entre mas al if
  }
  //Serial.println("Seleccione una opcion para continuar: a= Apagado - b=encendido");//Mandamos un mensaje en pantalla
  if (Serial.available()==true){                                        //si existe datos disponibles los leemos       
      option=Serial.read();                  //leemos la opcion enviada
      if(option=='a') {                     //Si ingresamos la letra a en la consola
        digitalWrite(ledRojo, LOW);        //Ponemos al Led Rojo en bajo
        digitalWrite(ledAmarillo, LOW);   //Ponemos al Led Amarillo en bajo
        digitalWrite(ledVerde, LOW);     //Ponemos al Led Verde en bajo
        Serial.println("LEDS APAGADOS");//Mandamos un mensaje en pantalla 
                      }
      if(option=='b') {
        digitalWrite(ledRojo, HIGH);         //Ponemos al Led Rojo en alto
        digitalWrite(ledAmarillo, HIGH);    //Ponemos al Led Amarillo en alto
        digitalWrite(ledVerde, HIGH);      //Ponemos al Led Verde en alto
        Serial.println("LEDS ENCENDIDOS");//Mandamos un mensaje en pantalla
       }
           
     }
  }
