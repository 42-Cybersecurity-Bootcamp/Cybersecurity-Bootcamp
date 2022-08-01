/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corsair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:52:02 by dugonzal          #+#    #+#             */
/*   Updated: 2022/08/01 15:06:04 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corsair.h"

/*
1. Un cliente (por ejemplo, un navegador) envía su clave pública al servidor y solicita algunos datos.
2. El servidor cifra los datos utilizando la clave pública del cliente y envía los datos cifrados.
3. El cliente recibe estos datos y los descifra.
*/

void ft_generate_keys(RSA **pub)
{
	const int Bits = 1024; // bits of key
	RSA *key = RSA_new(); // create new RSA structure
	BIGNUM *bn = BN_new(); // create new BIGNUM structure
	*pub = key; // ((RSA **)malloc(sizeof(RSA *))); // = key; // = RSA_new();
	BN_set_word(bn, RSA_F4); // set BN to ¿RSA_F4?
	// generate keys and store them in pub and priv
	RSA_generate_key_ex(key, Bits, bn, NULL); // generate key with ¿RSA_F4?
	RSA_check_key(*pub); // check keys
	// save keys to files
	BIO *bp_public = BIO_new_file("keys/public.key", "w"); // create new BIO structure
	// comprobamos que se han generado correctamente las claves pública y privada, punto de control 1
	if (bp_public == NULL)// en este caso me parese inutil esta comprobacion pero la hare para acostumbrarme
	{
		printf("Error opening file\n");
		exit(1);
	}
	// sacar el private key de la estructura
	PEM_write_bio_RSAPublicKey(bp_public, key); // write public key to file
	// free memory
	BIO_free_all(bp_public); // free BIO structure
}

// forma de crear una funcion sin poner nada dentro
void ft_(void)
{
	BIO *priv = NULL;
	

}

int	main(void)
{
	unsigned char	*enc_msg;
	int				enc_len;
	int				keylen;
	char			*pem_key;
	RSA				*pub;
	//RSA				*priv;
	int				dec_len;
	// mensaje a encriptar
	const unsigned char msg[] = "Decifre el mensaje!";
	printf("Mensaje a encriptar: %s\n", msg);
	// iniciando  keys
	ft_generate_keys(&pub);
	// escribir clave publica en un archivo
	BIO *bio = BIO_new(BIO_s_mem()); // create new BIO structure for memory buffer
	//PEM_write_bio_RSAPrivateKey(bio, priv, NULL, NULL, 0, NULL, NULL); //  no entiendo porque en la privare se pone NULL y en la publica no
	PEM_write_bio_RSAPublicKey(bio, pub);

	keylen = BIO_pending(bio);
	pem_key = calloc(keylen + 1, 1); // Null-terminate string with calloc()
	BIO_read(bio, pem_key, keylen);
	// print keys to stdout and mensage a encriptar
	printf("\n                 KEYS coRSAir UPLOAD\n\n");
	printf("{\n%s}\n", pem_key);
	// fin keys

	// encriptar mensaje con clave publica
	enc_len = RSA_size(pub); // get size of encrypted message
	enc_msg = calloc(enc_len + 1, 1); // Null-terminate string with calloc()
	enc_len = RSA_public_encrypt(ft_strlen(msg), msg, enc_msg, pub, RSA_PKCS1_PADDING);
	// print msg to stdout and mensage a encriptar
	printf("\n                 MESSAGE coRSAir UPLOAD\n\n");
	// save encrypted message to file
	//int	fd = open("encrypted.txt", ); // create new file
	//write(fd, enc_msg,); // write encrypted message to file
	//fwrite(enc_msg, enc_len, 1, fp); // write encrypted message to file
	//fclose(fp); // close file
	//printf("\n\n       KEYS coRSAir encriptacion decencriptacion  \n\n");
	printf("\nencriptado:{%d}\n", enc_len);
	// desencriptar mensaje con clave privada
	//dec_len = RSA_size(p); // get size of decrypted message
	unsigned char *dec_msg = calloc(enc_len + 1, 1); // Null-terminate string with calloc()
	dec_len = RSA_private_decrypt(enc_len, enc_msg, dec_msg, pub, RSA_PKCS1_PADDING);
	// print decrypted message to stdout
	printf("\ndecriptado:{%s}\n", enc_msg);
	printf("mensaje desencriptado: {%s}", dec_msg);
	printf("\nfuncion dec_len: {%d}", dec_len);
	// save decrypted message to file
	//FILE *fp = fopen("decrypted.txt", "w"); // create new file
	//fwrite(enc_msg, dec_len, 1, fp); // write decrypted message to file
	//fclose(fp); // close file
	// free memory
	BIO_free_all(bio);
	RSA_free(pub);
	free(pem_key);
}

