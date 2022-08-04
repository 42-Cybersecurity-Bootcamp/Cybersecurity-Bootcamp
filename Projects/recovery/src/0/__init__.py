# argparse es un modulo para el manejo de argumentos de la terminal y el programa
import argparse
from datetime import datetime
# importamos el archivo del banner para poder usarlo en el programa
from banner import banner

import os, sys

def ft_banner(banner): # funcion para imprimir el banner le pasamos el banner como parametro
	print (banner)
	#return banner
# funcion para limpiar la terminal en windows y linux
def clear():
    if sys.platform == "win32"  or sys.platform == "win64":
        print('\n' * 100)
    else:
        os.system('clear')

# creamos una variable para obtener los argumentos de la terminal
parcel = argparse.ArgumentParser(description='Recovery es una herramienta de recoleccion de datos de interes de un sistema operativo.')
parcel.add_argument('-t', '--time', default=1, type=int, help='tiempo de recoleccion de datos') #tiempo de recoleccion de datos tenemos que recebir el tiempo de recoleccion de datos

# main del programa
if __name__ == '__main__':
	#print (banner)
	clear();
	ft_banner (banner);
	args = parcel.parse_args()
	print ('Tiempo de recoleccion de datos es de ' + str(args.time), 'dias' )
