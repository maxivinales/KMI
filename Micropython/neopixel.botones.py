# Actividad N° 7 - Pulsadores y neopixels
# Permite intercambiar entre distintos colores los neopixels,
# haciendo el uso de tres botones.
# Nota:
# - Se debe descargar la libreria NeoPixel en caso de no tenerla -
# Link: https://github.com/adafruit/Adafruit_NeoPixel
# - No se requiere ningun tipo de componente extra para esta actividad.
# - Es necesario tener la Placa Educativa conectada a su computadora,
# y haber seleccionado la placa correspondiente en herramientas.
# Año 2022 por FANIOT http://www.faniot.com.ar

from machine import Pin
import neopixel

NEO_PIN = 27
NUM_PIXELS = 4
B_IZQ_PIN = 13
B_ENTER_PIN = 15
B_DER_PIN = 23

pixels = neopixel.NeoPixel(Pin(NEO_PIN), NUM_PIXELS)
b_izq = Pin(B_IZQ_PIN, Pin.IN, Pin.PULL_UP)
b_enter = Pin(B_ENTER_PIN, Pin.IN, Pin.PULL_UP)
b_der = Pin(B_DER_PIN, Pin.IN, Pin.PULL_UP)


def set_color(color):
    for i in range(NUM_PIXELS):
        pixels[i] = color
    pixels.write()


def red():
    set_color((255, 0, 0))


def green():
    set_color((0, 255, 0))


def blue():
    set_color((0, 0, 255))


while True:
    if not b_izq.value():
        red()
    elif not b_enter.value():
        green()
    elif not b_der.value():
        blue()
