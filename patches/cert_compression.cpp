/*
* Snippet to add compression algorithem
*/

static void BreezeTLS_SSL_CTX_add_cert_compression_alg(jlong ssl_address) {
    // Add certificate compression to current ssl_address
    /*
    * 0x0002 refers to the Algorithm number (See rfc8879)
    * 1: zlib
    * 2: brotli
    * 3: zsttd
    * etc. Experimental ones still exist and are used (XOR)
    */
    SSL* ssl = to_SSL(env, ssl_address, true);
    SSL_CTX_add_cert_compression_alg(SSL_get_SSL_CTX(ssl), 0x0002, Compress, Decompress);
}

static int Decompress(SSL* ssl, CRYPTO_BUFFER** out, size_t uncompressed_len, const uint8_t* in, size_t in_len) {
  // Decompress function body, parameters added by SSL_CTX_add_cert_compression_alg
}
static int Compress(SSL *ssl, CBB *out, const uint8_t *in, size_t in_len) {
  // Compress function body, parameters added by SSL_CTX_add_cert_compression_alg
  return 1;
}
