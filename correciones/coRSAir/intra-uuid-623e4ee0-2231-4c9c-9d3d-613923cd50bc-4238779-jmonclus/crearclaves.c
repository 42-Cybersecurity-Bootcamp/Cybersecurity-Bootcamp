#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/bn.h>

/*
struct
        {
        BIGNUM *n;              // public modulus OK
        BIGNUM *e;              // public exponent OK
        BIGNUM *d;              // private exponent OK
        BIGNUM *p;              // secret prime factor OK
        BIGNUM *q;              // secret prime factor OK
        BIGNUM *dmp1;           // d mod (p-1) OK
        BIGNUM *dmq1;           // d mod (q-1) OK
        BIGNUM *iqmp;           // q^-1 mod p OK
        // ...
        };
 RSA
 */

/*
n: 3329271541
e: 7
d: 23
p: 64763
q: 51407
d mod (p-1): 23
d mod (q-1): 23
q^-1 mod p: 46429
*/

int main () {
    int	ret = 0;
    //int bits = 512;
    BIO *bp_public = NULL, *bp_private = NULL;
    RSA* pub_key = RSA_new();
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM* n = BN_new();
    BIGNUM* e = BN_new();
    BIGNUM* d = BN_new();
    BIGNUM* p = BN_new();
    BIGNUM* q = BN_new();
    BIGNUM* dmp1 = BN_new();
    BIGNUM* dmq1 = BN_new();
    BIGNUM* iqmp = BN_new();

    /* Factors */
    /*BN_generate_prime_ex(p, bits, 1, NULL, NULL, NULL);
    BN_generate_prime_ex(q, bits, 1, NULL, NULL, NULL);*/
    BN_dec2bn(&p, "17");
    BN_dec2bn(&q, "11");
    RSA_set0_factors(pub_key, p, q);

    /* Key */
    /*BN_generate_prime_ex(e, bits, 1, NULL, NULL, NULL);
    BN_generate_prime_ex(d, bits, 1, NULL, NULL, NULL);*/
    BN_dec2bn(&e, "7");
    BN_dec2bn(&d, "23");
    BN_mul(n, p, q, ctx);
    RSA_set0_key(pub_key, n, e, d);

    /* Params */
    BN_sub(dmp1, p, BN_value_one());
    BN_sub(dmq1, q, BN_value_one());
    //printf("p-1: %s\n", BN_bn2dec(dmp1));
    //printf("q-1: %s\n", BN_bn2dec(dmq1));
    //printf("d: %s\n", BN_bn2dec(d));
    BN_mod(dmp1, d, dmp1, ctx);
    //printf("d mod(p-1) = %s mod 16 = 7 = %s\n", BN_bn2dec(d), BN_bn2dec(dmp1));
    BN_mod(dmq1, d, dmq1, ctx);
    //printf("d mod(q-1) = %s mod 10 = 3 = %s\n", BN_bn2dec(d), BN_bn2dec(dmq1));
    BN_mod_inverse(iqmp, q, p, ctx);
    RSA_set0_crt_params(pub_key, dmp1, dmq1, iqmp);


    /* --------------------------------------- */
    const BIGNUM *nn, *ee, *dd;
    RSA_get0_key(pub_key, &nn, &ee, &dd);
    printf("n: %s\n", BN_bn2dec(nn));
    printf("e: %s\n", BN_bn2dec(ee));
    printf("d: %s\n", BN_bn2dec(dd));
    /* --------------------------------------- */
    const BIGNUM *pp, *qq;
    RSA_get0_factors(pub_key, &pp, &qq);
    printf("p: %s\n", BN_bn2dec(pp));
    printf("q: %s\n", BN_bn2dec(qq));
    /* --------------------------------------- */
    const BIGNUM *dmp1dmp1, *dmq1dmq1, *iqmpiqmp;
    RSA_get0_crt_params(pub_key, &dmp1dmp1, &dmq1dmq1, &iqmpiqmp);
    printf("d mod (p-1): %s\n", BN_bn2dec(dmp1dmp1));
    printf("d mod (q-1): %s\n", BN_bn2dec(dmq1dmq1));
    printf("q^-1 mod p: %s\n", BN_bn2dec(iqmpiqmp));

    /* Escribir clave publica */
	bp_public = BIO_new_file("publickey.pem", "w+");
	ret = PEM_write_bio_RSAPublicKey(bp_public, pub_key);
    if(ret == 1) printf("Clave publica generada\n");

	/* Escribir clave privada */
	bp_private = BIO_new_file("privatekey.pem", "w+");
	ret = PEM_write_bio_RSAPrivateKey(bp_private, pub_key, NULL, NULL, 64, NULL, NULL);
    if(ret == 1) printf("Clave privada generada\n");

    RSA_free(pub_key);
    BIO_free_all(bp_public);
	BIO_free_all(bp_private);
    return EXIT_SUCCESS;

}

/* gcc -I/usr/include/openssl/ -Wall crearclaves.c -o crearclaves -lcrypto -ldl */