FROM debian:buster

# el apt-get -y  se pone para que no se pregunte si quiere instalar el paquete y se instale
RUN apt-get update && apt-get -y upgrade \
	&& apt-get install -y \
	apt-transport-https \
	ca-certificates \
	curl \
	gnupg-agent \
	software-properties-common

