import machine
import time

ZUM = 14
LDR = 39

# Inicializar los pines
zum = machine.Pin(ZUM, machine.Pin.OUT)
ldr = machine.ADC(machine.Pin(LDR))
ldr.atten(machine.ADC.ATTN_11DB)

# Variables globales
luminosidad = 0
luminosidad_estable = 0
luminosidad_anterior = 0
tiempo_var = 0


def controla_buzzer(diferencia):
    T = 3000 // (3 + diferencia * 2)
    if diferencia > 0:
        zum.value(1)
        time.sleep_ms(T // 4)
        zum.value(0)
        time.sleep_ms(3 * T // 4)


while True:
    luminosidad = int(((4095 - ldr.read()) / 4095) * 100)

    if luminosidad_estable == 0:
        luminosidad_estable = luminosidad
        luminosidad_anterior = luminosidad
        tiempo_var = time.ticks_ms()
    if luminosidad < luminosidad_estable:
        diferencia_luminosidad = luminosidad_estable - luminosidad
    else:
        diferencia_luminosidad = 0
    if luminosidad == luminosidad_anterior:
        if time.ticks_diff(time.ticks_ms(), tiempo_var) > 10000:
            luminosidad_estable = luminosidad
    else:
        luminosidad_anterior = luminosidad
        tiempo_var = time.ticks_ms()
    controla_buzzer(diferencia_luminosidad)
