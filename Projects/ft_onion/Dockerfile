FROM debian:buster

RUN apt-get update && apt-get install -y \
	upgrade \
	vim \
	nginx \
	tor \
	ssh

COPY nginx.conf /etc/nginx/nginx.conf

COPY index.html /var/www/html/index.html

"Mounts" [
    {
        "Type": "volume",
        "Name": "ft_onion_data",
        "Source": "container/volume",
        "Destination": "/app",
        "Driver": "local",
        "Mode": "",
        "RW": true,
        "Propagation": ""
    }
]
