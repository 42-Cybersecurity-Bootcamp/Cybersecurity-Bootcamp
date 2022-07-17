# imagen base
FROM ubuntu:22.04

# instalar paquetes necesarios
RUN apt-get update && apt-get -y upgrade \
	&& apt-get -y install \
		vim gcc

# copia de main hello world
COPY main.c /home
