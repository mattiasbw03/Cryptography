#include "vigenere.h"
#include <stddef.h> // for NULL
#include <string.h> // for strlen

// Hjælpefunktion: tjek om et tegn er upper-case bogstav (A-Z)
static int is_upper_letter(char c) {
    return c >= 'A' && c <= 'Z';
}

// Hjælpefunktion: laver key-tegn om til et shift 0–25
static int key_char_to_shift(char keyc) {
    // // Vi antager keyc er 'A'..'Z' (som i opgavebeskrivelsen)
    return keyc - 'A';
}

// Krypter én karakter med Vigenère
static char vigenere_encrypt_char(char plaintextc, char keyc) {
    if (!is_upper_letter(plaintextc)) {
        // // Hvis det ikke er en bogstav, lader vi det være (selvom opgaven siger kun A–Z)
        return plaintextc;
    }

    int shift = key_char_to_shift(keyc);
    int pos   = plaintextc - 'A';

    // // Læg key-shift til og wrap rundt med modulus
    int cipher_pos = (pos + shift) % 26;

    return (char)('A' + cipher_pos);
}

// Dekrypter én karakter med Vigenère
static char vigenere_decrypt_char(char ciphertextc, char keyc) {
    if (!is_upper_letter(ciphertextc)) {
        return ciphertextc;
    }

    int shift = key_char_to_shift(keyc);
    int pos   = ciphertextc - 'A';

    // // Træk key-shift fra og sørg for positivt resultat
    int plain_pos = (pos - shift + 26) % 26;

    return (char)('A' + plain_pos);
}

// Krypter en streng med Vigenère in-place
char *vigenere_encrypt(char *plaintext, char *key) {
    if (plaintext == NULL || key == NULL) {
        return NULL;
    }

    size_t key_len = strlen(key);
    if (key_len == 0) {
        // // Hvis nøglen er tom, giver kryptering ingen mening
        return plaintext;
    }

    // // j bruges til at gå igennem nøglen
    size_t j = 0;

    // // Loop over alle tegn i teksten
    for (size_t i = 0; plaintext[i] != '\0'; ++i) {
        char c = plaintext[i];

        if (is_upper_letter(c)) {
            // // Brug det aktuelle nøgle-tegn
            char keyc = key[j];

            // // Krypter tegnet med nøgle-tegnet
            plaintext[i] = vigenere_encrypt_char(c, keyc);

            // // Gå videre til næste nøgle-tegn og wrap rundt
            j = (j + 1) % key_len;
        } else {
            // // Ikke en bogstav? Lad det være, og ryk ikke nøgle-positionen
            plaintext[i] = c;
        }
    }

    return plaintext;
}

// Dekrypter en streng med Vigenère in-place
char *vigenere_decrypt(char *ciphertext, char *key) {
    if (ciphertext == NULL || key == NULL) {
        return NULL;
    }

    size_t key_len = strlen(key);
    if (key_len == 0) {
        return ciphertext;
    }

    size_t j = 0;

    // // Loop over alle tegn i den krypterede tekst
    for (size_t i = 0; ciphertext[i] != '\0'; ++i) {
        char c = ciphertext[i];

        if (is_upper_letter(c)) {
            char keyc = key[j];

            // // Dekrypter tegnet ved at trække key-shift fra
            ciphertext[i] = vigenere_decrypt_char(c, keyc);

            j = (j + 1) % key_len;
        } else {
            ciphertext[i] = c;
        }
    }

    return ciphertext;
}
