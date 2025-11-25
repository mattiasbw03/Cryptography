#pragma once

/** @file vigenere.h
 *  @brief Vigenère cipher for upper-case ASCII uden mellemrum.
 */

/**
 * @brief Krypterer en upper-case streng med Vigenère in-place.
 *
 * @param plaintext Teksten der skal krypteres (kun A–Z).
 * @param key       Nøglen (kun A–Z, gentages automatisk).
 * @return Samme streng, nu krypteret.
 */
char *vigenere_encrypt(char *plaintext, char *key);

/**
 * @brief Dekrypterer en upper-case streng med Vigenère in-place.
 *
 * @param ciphertext Krypteret tekst (kun A–Z).
 * @param key        Nøglen (kun A–Z, gentages automatisk).
 * @return Samme streng, nu dekrypteret.
 */
char *vigenere_decrypt(char *ciphertext, char *key);
