### Create a docker image with Alpine and Tor using docker compose.

<br>

Docker is microservice oriented, then each image must do an only single thing. Docker
commands allows you to run a single container at the same time, Docker compose allows
you to run and manage many containers at once. 

<br>

To use docker compose, you need to install it. In debian:

`sudo apt-get install docker-compose-plugin`

Build your image

`docker build -t tor_image:v1`

Now we use compose to run a container

`docker compose up -d`

If you put 0.0.0.0:9050 in your browser, our SOCKS proxy is working!

<br>

You can use `docker compose ps` too to see running containers.

<br>

### Stop the container

<br>

Use `docker compose down` to close container. You can check it with `ps` too to ensure.


