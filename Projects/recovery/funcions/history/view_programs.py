# importing os module
import os
import string
import subprocess

'''
tenemos que crear una funcion que nos muestre los programas instalados y los guarde en un archivo
pasos:
tenemos que guardar en una variale el resultado de la funcion 	os.popen('ls -l /usr/bin')
'''


# Python program to explain os.open() method


# File path to be opened
path = './programas_instalados.txt'

# Mode to be set
mode = 0o666

# flags
flags = os.O_RDWR | os.O_CREAT


# Open the specified file path
# using os.open() method
# and get the file descriptor for
# opened file path
fd = os.open(path, flags, mode)

print("File path opened successfully.")


# Write a string to the file
# using file descriptor
Data = subprocess.check_output(['wmic', 'product', 'get', 'name'])

os.write(fd, str.encode())
print("String written to the file descriptor.")


# Now read the file
# from beginning
os.lseek(fd, 0, 0)
str = os.read(fd, os.path.getsize(fd))
print("\nString read from the file descriptor:")
print(str.decode())

# Close the file descriptor
os.close(fd)
print("\nFile descriptor closed successfully.")
