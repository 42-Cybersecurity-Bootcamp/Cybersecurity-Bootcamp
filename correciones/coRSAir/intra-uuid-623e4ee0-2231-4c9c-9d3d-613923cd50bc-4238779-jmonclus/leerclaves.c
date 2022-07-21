#include <math.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main() {
    //const BIGNUM *n, *e, *d;
    int ret = 0;
    BIO *bp_public = NULL;
    RSA* pub_key = NULL;
    const char cert_publickey[] = "./publickey.pem";
    //const char cert_privatekey[] = "./p2_privatekey.pem";

    OpenSSL_add_all_algorithms();
    OpenSSL_add_all_ciphers();

    bp_public = BIO_new(BIO_s_file());
    ret = BIO_read_filename(bp_public, cert_publickey);
    //printf("RET: %d\n", ret);
    if(ret == 1) printf("Clave publica leida\n");
	PEM_read_bio_RSAPublicKey(bp_public, &pub_key, NULL, NULL);
    if(pub_key != NULL) printf("Clave publica cargada\n");


    /* --------------------------------------- */
    const BIGNUM *nn;
    const BIGNUM *ee;
    //const BIGNUM *dd;
    RSA_get0_key(pub_key, &nn, &ee, NULL);
    printf("n: %s\n", BN_bn2dec(nn));
    printf("n (hex): %s\n", BN_bn2hex(nn));
    printf("e: %s\n", BN_bn2dec(ee));
    //printf("d: %s\n", BN_bn2dec(dd));
    /* --------------------------------------- */
    //const BIGNUM *pp;


    //const BIGNUM *qq;
    //RSA_get0_factors(pub_key, &pp, &qq);
    //RSA_get0_factors(pub_key, &pp, NULL);
    //RSA_get0_factors(pub_key, NULL, &qq);
    //printf("p: %s\n", BN_bn2dec(pp));
    //printf("q: %s\n", BN_bn2dec(qq));
    /* --------------------------------------- */
    //const BIGNUM *dmp1dmp1;
    //const BIGNUM *dmq1dmq1;
    //const BIGNUM *iqmpiqmp;
    //RSA_get0_crt_params(pub_key, &dmp1dmp1, &dmq1dmq1, &iqmpiqmp);
    //RSA_get0_crt_params(pub_key, NULL, NULL, &iqmpiqmp);
    //RSA_get0_crt_params(pub_key, NULL, &dmq1dmq1, NULL);
    //RSA_get0_crt_params(pub_key, &dmp1dmp1, NULL, NULL);
    //printf("d mod (p-1): %s\n", BN_bn2dec(dmp1dmp1));
    //printf("d mod (q-1): %s\n", BN_bn2dec(dmq1dmq1));
    //printf("q^-1 mod p: %s\n", BN_bn2dec(iqmpiqmp));

    RSA_free(pub_key);
    BIO_free_all(bp_public);


    printf("----------------------------------\n");


    BIO *bp_private = NULL;
    RSA* pri_key = NULL;
    const char cert_privatekey[] = "./privatekey.pem";

    bp_private  = BIO_new(BIO_s_file());
    ret = BIO_read_filename(bp_private, cert_privatekey);
    //printf("RET: %d\n", ret);
    if(ret == 1) printf("Clave privada leida\n");
	PEM_read_bio_RSAPrivateKey(bp_private , &pri_key, NULL, NULL);
    if(pub_key != NULL) printf("Clave privada cargada\n");


    /* --------------------------------------- */
    const BIGNUM *nnnn;
    const BIGNUM *dddd;
    //const BIGNUM *dd;
    RSA_get0_key(pri_key, &nnnn, NULL, &dddd);
    printf("n: %s\n", BN_bn2dec(nnnn));
    printf("n (hex): %s\n", BN_bn2hex(nnnn));
    printf("d: %s\n", BN_bn2dec(dddd));



    RSA_free(pri_key);
    BIO_free_all(bp_private);

    return EXIT_SUCCESS;
}

/* gcc -I/usr/include/openssl/ -Wall leerclaves.c -o leerclaves -lcrypto -ldl */