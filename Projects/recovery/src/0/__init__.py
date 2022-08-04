# importamos el archivo del banner para poder usarlo en el programa
import argparse
from datetime import datetime
from posixpath import dirname
from banner import banner
import os, sys

def ft_banner(banner):
	print (banner)
	#return banner
# funcion para limpiar la terminal en windows y linux
def clear():
    if sys.platform == "win32"  or sys.platform == "win64":
        print('\n' * 100)
    else:
        os.system('clear')

# creamos una funcion para obtener los argumentos de la terminal
parcel = argparse.ArgumentParser(description='Recovery es una herramienta de recoleccion de datos de interes de un sistema operativo.')
parcel.add_argument('-t', '--time', default=1, type=int, help='tiempo de recoleccion de datos') #tiempo de recoleccion de datos tenemos que recebir el tiempo de recoleccion de datos

# main del programa
if __name__ == '__main__':
	#print (banner)
	clear();
	ft_banner (banner);
	args = parcel.parse_args()
	print ('Tiempo de recoleccion de datos: ' + str(args.time), 'dias' )
