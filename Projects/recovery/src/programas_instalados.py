# importing the module
import subprocess
from ft_input_de_datos import ft_input_de_datos


# traverse the software list
def ft_programas_instalados(rango_de_tiempo):
	Data = subprocess.check_output(['wmic', 'product', 'get', 'name'])
	a = str(Data)
# try block
	try:
	# arrange the string
		for i in range(len(a.rango_de_tiempo())):
			write_file = open("lista_programas.txt", "a")
	except IndexError as e:
		print("All Done")
	# crear archivo y escribir en el archivo los programas instalados
	save_file = open("lista_programas.txt", "w")
	save_file.write(a.split("\\r\\r\\n")[6:][i])
	# cerrar el archivo
	save_file.close()
