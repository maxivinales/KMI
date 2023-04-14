# Escribe tu código aquí :-)
# Actividad N° 8 - Sensor de temperatura
#
# Hace una lectura de datos proveniente del sensor de temperatura,
# lo muestra por el Monitor Serial y alerta cuando esta excede los
# 30°C encendiendo el zumbador.
#
# Nota:
# - Se debe descargar la libreria OneWire y DallasTemperature en caso de
#   no tenerla: Link OneWire: https://www.arduinolibraries.info/libraries/one-wire
#               Link DallasTemperature: https://www.arduinolibraries.info/libraries/dallas-temperature
# - No se requiere ningun tipo de componente extra para esta actividad.
# - Es necesario tener la Placa Educativa conectada a su computadora,
#   y haber seleccionado la placa correspondiente en herramientas.
#
# Año 2022
# por FANIOT
# http://www.faniot.com.ar

import machine
import onewire
import time
import ds18x20

# Definimos el Pin del zumbador, en este caso es el 14.
ZUM = machine.Pin(14, machine.Pin.OUT)

# Definimos el Pin del sensor de temperatura, en este caso es el 19.
S_TEMP = machine.Pin(19)

# Iniciamos los objetos donde estara definido el Pin del sensor
one_wire = onewire.OneWire(S_TEMP)
sensors = ds18x20.DS18X20(one_wire)


# La funcion "loop" se ejecuta una y otra vez constantemente.
def loop():
    sensors.convert_temp()
    time.sleep_ms(750)  # Esperamos 750 milisegundos para obtener el resultado

    temperatura = sensors.read_temp(roms[0])

    if temperatura > 30:
        ZUM.on()  # Encendemos el zumbador
    else:
        ZUM.off()  # Apagamos el zumbador
    print("Temperatura ambiental: ", temperatura, "°C")
    time.sleep(0.5)  # Esperamos medio segundo por cada lectura


# La funcion "main" se ejecuta una vez al resetear o encender la placa.
def main():
    roms = sensors.scan()

    if len(roms) > 0:
        print("Sensor de temperatura detectado!")
        print("Iniciando monitoreo...")
    else:
        print("No se detecto ningun sensor de temperatura.")
        return
    while True:
        loop()


if __name__ == "__main__":
    main()
