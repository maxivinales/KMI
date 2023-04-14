from machine import Pin
from time import sleep

ledRojo = Pin(32, Pin.OUT)  # Declaro en qué pin se encuentra mi LED Rojo
ledAmarillo = Pin(33, Pin.OUT)  # Declaro en qué pin se encuentra mi LED Amarillo
ledVerde = Pin(25, Pin.OUT)  # Declaro en qué pin se encuentra mi LED Verde

while True:
    ledRojo.on()  # Damos un estado alto al LED Rojo
    sleep(5)  # Generamos una espera de 5 segundos
    ledRojo.off()  # Damos un estado bajo al LED Rojo
    ledAmarillo.on()  # Damos un estado alto al LED Amarillo
    sleep(2)  # Generamos una espera de 2 segundos
    ledAmarillo.off()  # Damos un estado bajo al LED Amarillo
    ledVerde.on()  # Damos un estado alto al LED Verde
    sleep(5)  # Generamos una espera de 5 segundos
    ledVerde.off()  # Damos un estado bajo al LED Verde
    ledAmarillo.on()  # Damos un estado alto al LED Amarillo
    sleep(2)  # Generamos una espera de 2 segundos
    ledAmarillo.off()  # Damos un estado bajo al LED Amarillo
# Escribe tu código aquí :-)
