# dar un rango de tiempo
from datetime import timedelta, datetime

# dar una fecha de extraccion de datos
# rango de tiempo que vamos a recoger la lectura
# input del tiempo de eextraccion de datos
def ft_input_de_datos():
	while True:
			print("\nIntroduce el tiempo de extraccion de datos: ejemplo 1 = 1 dia\n")
			tiempo = int(input("Introduce el tiempo de extraccion de datos: "))
			rango_de_tiempo = timedelta(days=(tiempo))
			print("\nEl tiempo de extraccion de datos es: ", tiempo, "dias\n")
	return rango_de_tiempo

# funbcion de programas intalados del sistema windows le pasamos como parametro la fecha de recoleccion de datos

 # que tipo de dato es el parametro

# que tipo de datos es stdio y que tipo de datos es stdout
# que tipo de datos es stderr

