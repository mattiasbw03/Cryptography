#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#include "vigenere.h"

// Udskriver usage-tekst, som vist i opgavebeskrivelsen
static void print_usage(const char *progname) {
    fprintf(stderr,
        "Usage:\n"
        "  %s MODE ALGORITHM TEXT [KEY]\n"
        "Modes:\n"
        "  e, encrypt   Encrypt the input text\n"
        "  d, decrypt   Decrypt the input text\n"
        "Algorithms:\n"
        "  c, caesar    Caesar cipher\n"
        "  v, vigenere  Vigenere cipher\n"
        "Examples:\n"
        "  %s e c HELLO\n"
        "  %s decrypt v LQVRRBOFTQJ KEY\n",
        progname, progname, progname
    );
}

int main(int argc, char *argv[]) {
    // // Vi forventer minimum: progname MODE ALGORITHM TEXT
    if (argc < 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE; // 1: noget gik galt
    }

    // // Læs argumenter fra kommandolinjen
    char *mode      = argv[1]; // e / encrypt / d / decrypt
    char *algorithm = argv[2]; // c / caesar / v / vigenere
    char *text      = argv[3]; // teksten som krypteres/dekrypteres

    char *key = NULL;

    // // Tolk MODE: encrypt eller decrypt
    int encrypt_flag;
    if (strcmp(mode, "e") == 0 || strcmp(mode, "encrypt") == 0) {
        // // Vi skal kryptere
        encrypt_flag = 1;
    } else if (strcmp(mode, "d") == 0 || strcmp(mode, "decrypt") == 0) {
        // // Vi skal dekryptere
        encrypt_flag = 0;
    } else {
        fprintf(stderr, "Error: Unknown MODE '%s'\n", mode);
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // // Tjek om vi bruger Caesar eller Vigenère
    int use_caesar   = 0;
    int use_vigenere = 0;

    if (strcmp(algorithm, "c") == 0 || strcmp(algorithm, "caesar") == 0) {
        use_caesar = 1;
    } else if (strcmp(algorithm, "v") == 0 || strcmp(algorithm, "vigenere") == 0) {
        use_vigenere = 1;
    } else {
        fprintf(stderr, "Error: Unknown ALGORITHM '%s'\n", algorithm);
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // // Hvis vi skal bruge Vigenère, skal der være en key som 5. argument
    if (use_vigenere) {
        if (argc < 5) {
            fprintf(stderr, "Error: Vigenere requires a KEY argument\n");
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }
        key = argv[4]; // nøglen tages direkte fra kommandolinjen
    }

    // // Nu udfører vi den valgte handling
    if (use_caesar) {
        if (encrypt_flag) {
            // // Caesar-kryptering in-place
            caesar_encrypt(text);
        } else {
            // // Caesar-dekryptering in-place
            caesar_decrypt(text);
        }
    } else if (use_vigenere) {
        if (encrypt_flag) {
            // // Vigenère-kryptering in-place
            vigenere_encrypt(text, key);
        } else {
            // // Vigenère-dekryptering in-place
            vigenere_decrypt(text, key);
        }
    }

    // // Udskriv resultatet til standard output
    printf("%s\n", text);

    // // EXIT_SUCCESS = 0 betyder at programmet sluttede uden fejl
    return EXIT_SUCCESS;
}
