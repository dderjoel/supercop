/**
 * \file api.h
 * \brief NIST KEM API used by the LOCKER scheme
 */


#ifndef API_H
#define API_H


#define CRYPTO_ALGNAME "LOCKER-IX"

#define CRYPTO_SECRETKEYBYTES 2238
#define CRYPTO_PUBLICKEYBYTES 2198
#define CRYPTO_BYTES 64
#define CRYPTO_CIPHERTEXTBYTES 2326


int crypto_kem_keypair(unsigned char* pk, unsigned char* sk);
int crypto_kem_enc(unsigned char* ct, unsigned char* ss, const unsigned char* pk);
int crypto_kem_dec(unsigned char* ss, const unsigned char* ct, const unsigned char* sk);

#endif

