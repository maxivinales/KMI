/*
 *  Sensor de proximidad con LDR:
 *  
 *  En esta actividad se simula ser un sensor de proximidad como los de los automoviles.
 *  El principio de funcionamiento sería que cuando estamos mas cerca de un objeto, este
 *  proyecta cierta sombra hacia nosotros (en este caso hacia el kid maker), que se puede
 *  percibir utilizando el LDR.
 *  
 *  Nota:
 *  - No es necesario descargar ninguna librería para esta actividad
 *  - No se requiere ningun tipo de componente extra para esta actividad.
 *  - Es necesario tener la Placa Educativa conectada a su computadora,
 *    y haber seleccionado la placa correspondiente en herramientas.
 *  
 * 
  */

#define ZUM 14   // Definimos el Pin del zumbador, en este caso es el 14.
#define LDR 39 // Definimos el Pin del sensor LDR, en este caso es el 39.

//////////////////////////////
////  Variables globales  ////
int luminosidad=0;          // indicador de luminocidad
int luminosidad_estable=0;  //indica la luminocidad que se tiene en estado normal, sin objetos acercandose
int luminosidad_anterior=0; //aqui se guarda la muestra de lumonosidad de un ciclo anterior
uint32_t tiempo_var=0;      //guarda el valor de millis() de la ultima vez que hubo una variacion en la luminocidad


////////////////////////////////////
////  Declaracion de funciones  ////
void controla_buzzer(int);        // funcion que controla la frecuencia de pitido del buzzer

// Declaramos las variables a enviar
void setup() {
  Serial.begin(115200);             // seteamos la comunicacion a 115200 bps
  
  pinMode(ZUM, OUTPUT);             //Inicializamos el pin digital del zumbador como salida.

}

// La funcion "loop" se ejecuta una y otra vez constantemente.
void loop() {
  luminosidad=map(analogRead(LDR), 4095, 0, 100, 0);  // Leemos el LDR, usamos la funcion "map" para convertir el valor analogico 
                                                      // de 0-4095 a 0-100 el cual sera nuestro porcentaje, y lo guardamos en 
                                                      // una variable del tipo entero
                                                      
  //entra al if solo al principio, ya que se considera que nunca la luminosidad estable es cero                                                    
  if(luminosidad_estable==0){                         // al principio considero que nadie se está acercando
    luminosidad_estable=luminosidad;                  // y considero que la luminocidad que mide primero es la que se tiene de manera estable
    luminosidad_anterior=luminosidad;
    tiempo_var=millis();
  }

  int diferencia_luminosidad;                         //variable que se le pasa a la funcion para controlar el buzzer
  if(luminosidad<luminosidad_estable){                //si la lumionicidad disminuye quiere decir que algo se está acercando
    diferencia_luminosidad=luminosidad_estable-luminosidad; // calculo la diferencia de lumoinocidades
  }else{                                              //si no, lo iguala a 0
    diferencia_luminosidad=0;
  }

  if(luminosidad==luminosidad_anterior){              //si la luminocidad se mantiene estable se cree que no hay objetos acercandose                                //entonces activo un contador para medir
    if((millis()-tiempo_var)>10000){                  //si el tiempo que paso desde la ultima variacion es mayor a 15 segundos
      luminosidad_estable=luminosidad;                //se supone que cambió la luz ambiente y no que hay un objeto acercandoce,
                                                      //entonces se cambia el valor de luminocidad estable
    }
  }else{                                              //si no es igual, quiere decir que la lumonocidad cambió
    luminosidad_anterior=luminosidad;                 //se guarda la luminocidad actual en la variable de luminocidad anterior
    tiempo_var=millis();                              //y se guarda el tiempo de la ultima variacion
  }

  controla_buzzer(diferencia_luminosidad);            //finalmente se llama a la función del buzzer y se le pasa la diferencia de luminocidad

}

//////////////////////////////////
////  Definicion de funciones ////
void controla_buzzer(int diferencia){ // funcion que controla la frecuencia de pitido del buzzer
  int T;                              // se declara el tiempo que dura  un periodo del pitido
  T=3000/(3+diferencia*2);            //se calcula con la funcion experimental, para que a medida que
                                      //la diferencia aumente, el periodo disminuya
  if(diferencia>0){                   //solo emite pitidos si hay una diferencia entre la lumonocidad estable y la actual
    digitalWrite(ZUM, HIGH);          //enciende el buzzer
    delay(T/4);                       //esta encendido solo la cuarta parte del periodo para que no sea tan molesto
    digitalWrite(ZUM, LOW);           //apaga el buzzer
    delay(3*T/4);                     //espera el resto del periodo
  }
}
