# importacion de funcion del timepo de extraccion de datos
from ft_input_de_datos import ft_input_de_datos as ft_input_de_datos
from programas_instalados import *

# crear funciones para hacer las cosas lol o clases lol



# main del programa
if __name__ == '__main__':

	ft_input_de_datos()
	ft_programas_instalados( ft_input_de_datos());

# comprobacion de que haya echado el tiempo de extraccion de datos
	if ft_programas_instalados ==  0:
		print("\nNo se pudo realizar la extraccion de datos\n")
	else:
		print("\nSe realizo la extraccion de datos\n")
