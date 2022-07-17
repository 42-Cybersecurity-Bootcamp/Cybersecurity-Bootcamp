# creacion de imagen

# vamos a crear una imagen desde un archivo dockerfile

 1. primero hacemos `FROM` y el nombre de la imagen base que queremos usar, en este caso es ubuntu:22.04

 2. luego con `RUN` le indicamos que tiene que hacer en la construcion del contenedor.

# construccion de la imagen
- para construir la imagen, usamos el comando `docker build`

- docker build -t nombre_de_la_imagen_que_queremos_crear ./ruta_del_archivo_dockerfile

- ejemplo:
	- docker build -t nivel_0 .

3.  esto construirá la imagen nivel_0
	- con el comando `docker images` podemos ver todas las imagenes que tenemos creadas
4. una vez creada la imagen podemos inciarla con el comando `docker run`
	- docker run -it nombre_de_la_imagen_que_queremos_iniciar sh
	- ejemplo: docker run -it nivel_0 sh
5. en este momento estamos dentro del contenedor.

6. ahora podemos usar vim para hacer un hello world compilando con gcc
	- vim hello.c
	- gcc hello.c -o hello
	- ./hello
	- ejemplo: vim hello.c && gcc hello.c -o hello && ./hello

# comentario
- os recomiendo ser root cuando esteis en un contenedor porque la terminal hace cosas raras si sabeis como solucionarlo. poner algun comentario en el repo
