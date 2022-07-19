
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <string.h>

void error_and_exit(const char* msg) {
  printf("%s\n", msg);
  char buf[256];
  int err = ERR_get_error();
  ERR_error_string_n(err, buf, sizeof(buf));
  printf("errno: %d, %s\n", err, buf);
  exit(EXIT_FAILURE);
}

int main(int arc, char *argv[]) {
  printf("RSA example\n");




  int ret = 0;
    BIO *bp_public = NULL;
    RSA* pub_key = NULL;
    const char cert_publickey[] = "./publickey.pem";

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



printf("--------------------------------------------------\n");



    BIO *bp_private = NULL;
    RSA* pri_key = NULL;
    const char cert_privatekey[] = "./privatekey.pem";

    bp_private = BIO_new(BIO_s_file());
    ret = BIO_read_filename(bp_private, cert_privatekey);
    //printf("RET: %d\n", ret);
    if(ret == 1) printf("Clave privada leida\n");
    PEM_read_bio_RSAPrivateKey(bp_private, &pri_key, NULL, NULL);
    if(pri_key != NULL) printf("Clave privada cargada\n");
   /* --------------------------------------- */
    const BIGNUM *nnnn;
    const BIGNUM *dddd;
    //const BIGNUM *dd;
    RSA_get0_key(pri_key, &nnnn, NULL, &dddd);
    printf("n: %s\n", BN_bn2dec(nnnn));
    printf("n (hex): %s\n", BN_bn2hex(nnnn));
    printf("d: %s\n", BN_bn2dec(dddd));


printf("--------------------------------------------------\n");


  int modulus_bits = 512;
  const uint32_t exponent = 0x10001;

  EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
  if (ctx == NULL) {
    error_and_exit("Could not create a context for RSA_PSS");
  }

  if (EVP_PKEY_keygen_init(ctx) <= 0) {
    error_and_exit("Could not initialize the RSA context");
  }

  if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, modulus_bits) <= 0) {
    error_and_exit("EVP_PKEY_CTX_set_rsa_keygen_bits failed");
  }

  BIGNUM* exponent_bn = BN_new();
  BN_set_word(exponent_bn, exponent);
  if (EVP_PKEY_CTX_set_rsa_keygen_pubexp(ctx, exponent_bn) <= 0) {
    error_and_exit("EVP_PKEY_CTX_set_rsa_keygen_pubexp failed");
  }

  //EVP_PKEY* pkey = NULL;







    EVP_PKEY *pkey  = EVP_PKEY_new();
    EVP_PKEY_set1_RSA(pkey, pub_key);





  if (EVP_PKEY_keygen(ctx, &pkey) != 1) {
    error_and_exit("EVP_PKEY_keygen failed");
  }

  // So we have our key generated. We can now use it to encrypt

  // Create and initialize a new context for encryption.
  EVP_PKEY_CTX* enc_ctx = EVP_PKEY_CTX_new(pkey, NULL);
  if (EVP_PKEY_encrypt_init(enc_ctx) <= 0) {
    error_and_exit("EVP_PKEY_encrypt_init failed");
  }
  // Any algorithm specific control operations can be performec now before
  /*if (EVP_PKEY_CTX_set_rsa_padding(enc_ctx, RSA_PKCS1_OAEP_PADDING) <= 0) {
    error_and_exit("EVP_PKEY_CTX_set_rsa_padding failed");
  }*/

  unsigned char* in = (unsigned char*) "Hola mundo";
  size_t outlen;
  unsigned char* out;

  printf("Going to encrypt: %s\n", in);
  // Determine the size of the output
  if (EVP_PKEY_encrypt(enc_ctx, NULL, &outlen, in, strlen ((char*)in)) <= 0) {
    error_and_exit("EVP_PKEY_encrypt failed");
  }
  printf("Determined ciphertext to be of length: %ld) is:\n", outlen);

  out = OPENSSL_malloc(outlen);

  if (EVP_PKEY_encrypt(enc_ctx, out, &outlen, in, strlen ((char*)in)) <= 0) {
    error_and_exit("EVP_PKEY_encrypt failed");
  }

  printf("Encrypted ciphertext (len:%ld) is:\n", outlen);
  BIO_dump_fp(stdout, (const char*) out, outlen);















printf("--------------------------------------------------\n");



FILE* ff = fopen("temp1.pem", "w");
PEM_write_RSAPublicKey(ff, pub_key);


EVP_PKEY_CTX* ctx2 = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
  if (ctx == NULL) {
    error_and_exit("Could not create a context for RSA_PSS");
  }

  if (EVP_PKEY_keygen_init(ctx2) <= 0) {
    error_and_exit("Could not initialize the RSA context");
  }

  if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx2, modulus_bits) <= 0) {
    error_and_exit("EVP_PKEY_CTX_set_rsa_keygen_bits failed");
  }

  BIGNUM* exponent_bn2 = BN_new();
  BN_set_word(exponent_bn2, exponent);
  if (EVP_PKEY_CTX_set_rsa_keygen_pubexp(ctx2, exponent_bn2) <= 0) {
    error_and_exit("EVP_PKEY_CTX_set_rsa_keygen_pubexp failed");
  }





    /*EVP_PKEY *prkey  = EVP_PKEY_new();
    EVP_PKEY_set1_RSA(prkey, pri_key);



    if (EVP_PKEY_keygen(ctx2, &prkey) != 1) {
      error_and_exit("EVP_PKEY_keygen failed");
    }

    EVP_PKEY_CTX* dec_ctx = EVP_PKEY_CTX_new(prkey, NULL);*/








  // So we have our key generated. We can now use it to encrypt

  // Create and initialize a new context for encryption.
 EVP_PKEY_CTX* dec_ctx = EVP_PKEY_CTX_new(pkey, NULL);





  if (EVP_PKEY_decrypt_init(dec_ctx) <= 0) {
    error_and_exit("EVP_PKEY_encrypt_init failed");
  }

  /*if (EVP_PKEY_CTX_set_rsa_padding(dec_ctx, RSA_PKCS1_OAEP_PADDING) <= 0) {
    error_and_exit("EVP_PKEY_CTX_set_rsa_padding failed");
  }*/

  unsigned char* dout;
  size_t doutlen;
  if (EVP_PKEY_decrypt(dec_ctx, NULL, &doutlen, out, outlen) <= 0) {
    error_and_exit("EVP_PKEY_decrypt get length failed");
  }

  printf("Determimed plaintext to be of length: %ld:\n", doutlen);
  dout = OPENSSL_malloc(doutlen);
  if (!dout) {
    error_and_exit("OPENSSL_malloc failed");
  }

  if (EVP_PKEY_decrypt(dec_ctx, dout, &doutlen, out, outlen) <= 0) {
    error_and_exit("EVP_PKEY_decrypt failed");
  }

  printf("Decrypted Plaintext is:\n");
  BIO_dump_fp(stdout, (const char*) dout, doutlen);

  EVP_PKEY_CTX_free(ctx);
  exit(EXIT_SUCCESS);
}

/* gcc -I/usr/include/openssl/ -Wall enc-dec.c -o enc-dec -lcrypto -ldl */
