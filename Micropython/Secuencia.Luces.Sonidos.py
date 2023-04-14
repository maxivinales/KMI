import machine
import time

# Definir el número del pin donde está conectado el zumbador
buzzer_pin = machine.Pin(14, machine.Pin.OUT)

# Definir las notas de la melodía
melodia = ["G4", "C5", "E5", "D5", "C5", "B4", "C5", "B4"]

# Definir las duraciones de cada nota
duraciones = [200, 200, 200, 400, 200, 200, 200, 400]

# Configurar el PWM para el zumbador
buzzer_pwm = machine.PWM(buzzer_pin)

# Reproducir la melodía cuatro veces
for j in range(4):
    for i, nota in enumerate(melodia):
        # Convertir la nota en una frecuencia
        if nota == "C4":
            frecuencia = 262
        elif nota == "D4":
            frecuencia = 294
        elif nota == "E4":
            frecuencia = 330
        elif nota == "F4":
            frecuencia = 349
        elif nota == "G4":
            frecuencia = 392
        elif nota == "A4":
            frecuencia = 440
        elif nota == "B4":
            frecuencia = 494
        elif nota == "C5":
            frecuencia = 523
        else:
            continue
        # Obtener la duración de la nota actual
        duracion = duraciones[i]

        # Establecer la frecuencia y la duración de la nota
        buzzer_pwm.freq(frecuencia)
        buzzer_pwm.duty(512)
        time.sleep_ms(duracion)
        buzzer_pwm.duty(0)

        # Hacer una pausa breve entre cada nota
        time.sleep(0.10)
    # Hacer una pausa de medio segundo entre cada repetición
    time.sleep(0.5)
import machine
import neopixel
from time import sleep

# Configuración de los pines y el número de LEDs
NUM_LEDS = 4
PIN = 27

# Inicialización de los LEDs
np = neopixel.NeoPixel(machine.Pin(PIN), NUM_LEDS)

# Definición de los colores
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

# Loop principal
while True:
    for i in range(NUM_LEDS):
        np[i] = red
        np.write()
        sleep(0.1)
    sleep(2)

    for i in range(NUM_LEDS):
        np[i] = green
        np.write()
        sleep(0.1)
    sleep(2)

    for i in range(NUM_LEDS):
        np[i] = blue
        np.write()
        sleep(0.1)
    sleep(2)# Escribe tu código aquí :-)
