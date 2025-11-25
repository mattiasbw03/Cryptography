#include "caesar.h"
#include <stddef.h> // for NULL
#include <stdbool.h>

// Hjælpefunktion: tjekker om et tegn er en upper-case bogstav (A-Z)
static bool is_upper_letter(char c) {
    // Vi undgår <ctype.h> for at gøre det helt gennemsigtigt
    return c >= 'A' && c <= 'Z';
}

// Hjælpefunktion: normaliserer et heltal-shift til 0–25
static int normalize_shift(int shift) {
    // // Hvis shift er større end 26 eller negativt, folds det ind i 0–25
    shift %= 26;
    if (shift < 0) {
        shift += 26;
    }
    return shift;
}

// Krypter ét tegn med Caesar
char caesar_encrypt_char(char plaintextc, char shift) {
    // Hvis tegnet ikke er en upper-case bogstav, så rør vi det ikke
    if (!is_upper_letter(plaintextc)) {
        return plaintextc;
    }

    // // Normalisér shift og tegnposition til 0–25
    int s = normalize_shift((int)shift);
    int pos = plaintextc - 'A';

    // // Læg shift til, og wrap rundt med modulus
    int cipher_pos = (pos + s) % 26;

    // // Konverter tilbage til et bogstav
    return (char)('A' + cipher_pos);
}

// Dekrypter ét tegn med Caesar
char caesar_decrypt_char(char ciphertextc, char shift) {
    // // Hvis tegnet ikke er upper-case, lader vi det være
    if (!is_upper_letter(ciphertextc)) {
        return ciphertextc;
    }

    int s = normalize_shift((int)shift);
    int pos = ciphertextc - 'A';

    // // Træk shift fra, og sørg for at resultatet er positivt
    int plain_pos = (pos - s + 26) % 26;

    return (char)('A' + plain_pos);
}

// Krypter en hel streng in-place
char *caesar_encrypt(char *plaintext) {
    if (plaintext == NULL) {
        return NULL;
    }

    // // Gå igennem alle tegn indtil vi rammer '\0' (slut på streng)
    for (char *p = plaintext; *p != '\0'; ++p) {
        // // Udskift hvert tegn med det krypterede
        *p = caesar_encrypt_char(*p, CAESAR_SHIFT);
    }

    // // Returnér samme pointer, så funktionen kan bruges i udtryk
    return plaintext;
}

// Dekrypter en hel streng in-place
char *caesar_decrypt(char *ciphertext) {
    if (ciphertext == NULL) {
        return NULL;
    }

    // // Gå igennem alle tegn indtil strengens slut
    for (char *p = ciphertext; *p != '\0'; ++p) {
        // // Udskift hvert tegn med det dekrypterede
        *p = caesar_decrypt_char(*p, CAESAR_SHIFT);
    }

    return ciphertext;
}
