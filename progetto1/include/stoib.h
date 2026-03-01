/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */
#include <stdbool.h>
/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * @brief Converte una stringa in intero (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa `s` nella base `b` (tra 2 e 36):
 * − saltando gli eventuali spazi bianchi iniziali;
 * − riconoscendo l'eventuale (singolo) carattere del segno (+ o -);
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data
 *   (le cifre per la base 36 sono 0,..,9,A,..,Z, invece a-z non sono cifre valide);
 * - deve essere presente almeno una cifra nella base data.
 *
 * Restituisce:
 * - 0 se uno degli argomenti non è valido, e in tal caso il valore in salvato in `r` non è significativo;
 * - altrimenti, il numero di caratteri letti dalla stringa (inclusi spazi e segni), salvando in `r` il risultato.
 * 
 * Notare che la conversione della stringa c_n ... c_2 c_1 c_0 in base b è il numero:
 * c_n * b^n + ... * c_2 * b^2 + c_1 * b + c_0.
 *
 * La funzione non si accorge di eventuali overflow numerici (restituendo in questo caso un risultato scorretto).
 *
 * @param s una stringa da convertire.
 * @param b la base (tra 2 e 36).
 * @param r l'indirizzo dell'intero dove memorizzare il risultato.
 * @return  il numero di caratteri letti dalla stringa
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_stoib"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * @brief Converts a string to an integer (given the base).
 *
 * Computes the integer represented by the string `s` in base `b` (between 2 and 36):
 * - skipping any leading whitespace;
 * - recognizing an optional (single) sign character (+ or -);
 * - stopping at the first character that is not a valid digit in the given base
 *   (the digits for base 36 are 0,..,9,A,..,Z, while a-z are not valid digits);
 * - at least one digit in the given base must be present.
 *
 * Returns:
 * - 0 if one of the arguments is invalid, and in that case the value stored in `r` is not meaningful;
 * - otherwise, the number of characters read from the string (including whitespace and signs), storing the result in `r`.
 * 
 * Note that the conversion of string c_n ... c_2 c_1 c_0 in base b is the number:
 * c_n * b^n + ... * c_2 * b^2 + c_1 * b + c_0.
 *
 * The function does not detect possible numeric overflows (returning an incorrect result in that case).
 *
 * @param s a string to convert.
 * @param b the base (between 2 and 36).
 * @param r the address of the integer where the result is stored.
 * @return  the number of characters read from the string
 *
 * NOTE: this function appears in compilation errors as "student_stoib"
 * NOTE: this function is tested independently of your main
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int stoib(char *s, unsigned short b, int *r)