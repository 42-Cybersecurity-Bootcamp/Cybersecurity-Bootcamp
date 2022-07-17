FROM debian:buster

RUN apt-get update && apt-get install -y \
	upgrade \
	vim \
	nginx \
	tor \
	ssh

COPY nginx.conf /etc/nginx/nginx.conf

COPY index.html /var/www/html/index.html

