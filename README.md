Dette projekt er et lille kommandolinje-program skrevet i C, der kan kryptere og dekryptere tekst ved hjælp af to klassiske kryptografiske metoder: Caesar-cifferet og Vigenère-cifferet. Projektet er bygget op efter principperne for modularisering, header-filer og kommandolinje-interfaces, som gennemgået i undervisningen.
Programmet fungerer ved at tage argumenter fra terminalen, hvor man vælger om man vil kryptere eller dekryptere, hvilken algoritme der skal bruges, og hvilken tekst der skal behandles. Ved brug af Vigenère skal der desuden gives en nøgle.

Caesar-ciffer

Caesar-cifferet er en af de ældste krypteringsmetoder. Det fungerer ved at flytte hvert bogstav et fast antal pladser i alfabetet.
I denne version bruges et skift på 3 (A → D, B → E, …).
Denne metode er meget simpel, men let at knække, da samme skift bruges for hele teksten.

Vigenère-ciffer

Vigenère-cifferet er en videreudvikling af Caesar-cifferet. I stedet for ét fast skift bruger det et ord som nøgle, hvor hvert bogstav i nøglen bestemmer et forskelligt skift.
Nøglen gentages hen over hele teksten.
Dette gør krypteringen langt stærkere, fordi skiftet varierer fra bogstav til bogstav.
