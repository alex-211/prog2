/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */
#include <stdbool.h>
#include <string.h>
#include <math.h>
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
int stoib(char *s, unsigned short b, int *r) {

    //NOTE \n and \t count as a whitespace
    // NOTE the leading whitespace needs to be counted only if there's a valid char in the string!
    // NOTE whitespace in the middle of the string need not be counted

    // check all arguments are valid
    if (s == NULL || b == 0 || r == NULL) return 0;
    
    *r = 0;
    int retVal = 0;
    int sign = +1;
    size_t sSize = strlen(s);
    
    // check base
    if (b < 2 || b > 36) return 0;
    
    // check when the string starts
    int i = 0;
    while (i <= sSize && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')) 
    {
        retVal++;
        i++;
    }
    
    // check sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
        retVal++;
    }
    // since we assumed sign is positive, if we see "+" we just need to skip it in our for loop
    else if (s[i] == '+') 
    {
        i++;
        retVal++;
    }

    // empty string/only sign means return value should be 0
    if (i == sSize) return 0;

    bool stringIsValid = false;
    
    for(int j = i; j < sSize; j++)
    {
        int currentValue = 0;
        
        // check for whitespace
        // shouldn't count this whitespace so we just need a break 
        if (s[j] == ' ')
        {
            break;
        }
        
        // check if char is allowed in our base
        // bases 2-10
        if (b >= 2 && b <= 10)
        {
            if (!(s[j] >= '0' && s[j] < ('0' + b)))
            {
                break;   
            }
            else
            {
                stringIsValid = true;
                currentValue = s[j] - '0';
            }
        }
            
        // bases 11-36
        else
        {
            if  (!(s[j] >= '0' && s[j] < ('0' + 10)) && // check numbers
                 !(s[j] >= 'A' && s[j] < ('A' + b - 10)) // check letters (uppercase only)
                ) 
            {
                break;
            }
            else 
            {
                if (s[j] >= '0' && s[j] < ('0' + 10))
                {
                    stringIsValid = true;
                    currentValue = s[j] - '0';  
                } 
                if (s[j] >= 'A' && s[j] < ('A' + b - 10))
                {
                    stringIsValid = true;
                    currentValue = s[j] - 'A' + 10;  
                } 
                if (s[j] >= 'a' && s[j] < ('a' + b - 10))
                {
                    stringIsValid = true;
                    currentValue = s[j] - 'a' + 10;
                }
            }
        }
        
        *r = *r * b + currentValue;
        retVal++;
    }

    // this is needed cos apparently whitespace need only be counted when there's a valid char in the string
    if (stringIsValid == false)
    {
        retVal = 0;
    }

    *r = *r * sign;
    return retVal;
}


/**
 * Invoca la funzione stoib su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione stoib
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the stoib function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your stoib function
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
 
 // tutti i caratteri letti sono contati
int main() {

    int r = 0;

    // Caso stringa vuota
    if (stoib(" ", 2, &r) != 0)
    {
        printf("TEST FAILED\n");
        return 0;   
    }
    
    // Caso spazio vuoto
    if (stoib(" 1234", 10, &r) != 5 || r != 1234)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // caso spazio vuoto in mezzo
    if (stoib("123 4", 10, &r) != 3 || r != 123)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // segno + esplc
    if (stoib("+1234", 10, &r) != 5 || r != 1234)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // segno - esplc
    if (stoib("-1234", 10, &r) != 5 || r != -1234)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // segni non riconosciuti inizio
    if (stoib("!1234", 10, &r) != 0)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // doppio segno
    if (stoib("+-1234", 10, &r) != 0)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // base sbagliata
    if (stoib("420", 69, &r) != 0)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // base 10 con lettere maiusc
    if (stoib("ABC", 36, &r) != 3 || r != 13368)
    {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // tanti spazi
    if (stoib("    1", 10, &r) != 5 || r != 1)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    printf("TEST PASSED\n");
    return 0;
}
