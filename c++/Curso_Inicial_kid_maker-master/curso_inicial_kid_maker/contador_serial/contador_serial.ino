/*
   Contador Serial

    En este ejemplo podremos recibir el valor de un contador que aumente la cifra
    en correspondencia a los ciclos del procesador. 

  Nota:
  - No se requiere de ninguna libreria adicional para esta actividad  
  - Es necesario tener la Placa Educativa conectada a su computadora,
    y haber seleccionado la placa correspondiente en herramientas.
    
  Año 2022
  http://www.faniot.com.ar
  
*/

int cont=0;//Inicio una variable

void setup(){
 //iniciamos el puerto serie
 Serial.begin(115200);
}

void loop(){
  //Imprimimos el valor del contador
  Serial.print("Contador Serial: "); //Aqui escribimos entre comillas el texto que deseamos que aparezca en pantalla
  Serial.println(cont);       //Aqui enviaremos el valor de la variable cont por el monitor serie 
  
  //incrementamos el contador y esperamos un segundo
  cont++;
  delay(1000);
}
