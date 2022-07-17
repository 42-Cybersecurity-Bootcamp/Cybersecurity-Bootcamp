1. Install virt machine.
2. Port mapping 80:80 4242:4242 \
	2.1 Install openssh-server \
	2.2 /etc/ssh/sshd_config -> Port 4242 \
	2.3 service ssh restart \
3. Install nginx.
	3.1 mv /var/www/html/indexxxxxxnginx.html /var/www/html/index.html \
	3.2 Change /var/www/html/index.html -> "Up to you" \
4. Install tor.
	4.1 /etc/tor/torrc \
	Uncomment 	#HiddenServiceDir /var/lib/tor/hidden_service/" \
			#HiddenServicePort 80 127.0.0.1:80" \
	4.2 service tor restart \
5. cat /var/lib/tor/hidden_service/hostname <- xxx.onion will be here 
