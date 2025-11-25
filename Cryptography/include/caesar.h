#pragma once

/** @file caesar.h
 *  @brief Caesar cipher kun defineret for upper-case ASCII
 */

#ifndef CAESAR_SHIFT
#define CAESAR_SHIFT 3  /**< Standard skift for hver bogstav. */
#endif

/**
 * @brief Krypterer en upper-case streng med Caesar in-place.
 *
 * @note Ikke-upper-case tegn ignoreres. Bruges @ref CAESAR_SHIFT.
 * @return Samme streng, nu krypteret.
 */
char *caesar_encrypt(char *plaintext);

/**
 * @brief Krypterer ét upper-case tegn.
 *
 * @note Ikke-upper-case tegn ignoreres (returneres uændret).
 */
char caesar_encrypt_char(char plaintextc, char shift);

/**
 * @brief Dekrypterer en upper-case streng med Caesar in-place.
 *
 * @note Ikke-upper-case tegn ignoreres. Bruges @ref CAESAR_SHIFT.
 * @return Samme streng, nu dekrypteret.
 */
char *caesar_decrypt(char *ciphertext);

/**
 * @brief Dekrypterer ét upper-case tegn.
 *
 * @note Ikke-upper-case tegn ignoreres (returneres uændret).
 */
char caesar_decrypt_char(char ciphertextc, char shift);
