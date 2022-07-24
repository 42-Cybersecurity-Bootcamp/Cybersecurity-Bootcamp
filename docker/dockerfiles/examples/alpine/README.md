# Create a docker image with Alpine and Tor using docker compose.

<br>

Alpine is a linux distro intended to be very lightweight, perfect for using it to create docker images.

<br>

Docker is microservice oriented, then each image must do an only single thing. Docker
commands allows you to run a single container at the same time, Docker compose allows
you to run and manage many containers at once. 

<br>

To use docker compose, you need to install it. In debian:

````
sudo apt-get install docker-compose-plugin
````

<br>

Use compose to build image and run the container

````
docker compose up -d
````
<br>

If you put 0.0.0.0:9050 in your browser, our SOCKS proxy is working!

<br>

You can use `docker compose ps` too to see running containers.

<br>

## Stop the container

<br>

Use `docker compose down` to close container. You can check it with `ps` too to ensure.


