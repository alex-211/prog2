/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */
#include <stdbool.h>
/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

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
int main() {
    
    bool testPassed;
    int r = 0;
    int* pR = &r;
    // Caso stringa vuota
    if (stoib(" ", 2, pR) == 0) testPassed = true;
    else testPassed = false;
    /*
    // Caso spazio vuoto
    s = ' 1234';
    if (stoib(*pS, 10, pR) == 4 && *r == 1234) testPassed = true;
    else testPassed = false;
    
    // caso spazio vuoto in mezzo
    s = '123 4';
    if (stoib(*pS, 10, pR) == 5 && *r == 1234) testPassed = true;
    else testPassed = false;
    
    // segno + esplc
    s = '+1234';
    if (stoib(*pS, 10, pR) == 5 && *r == 1234) testPassed = true;
    else testPassed = false;
    
    // segno - esplc
    s = '-1234';
    if (stoib(*pS, 10, pR) == 5 && *r == -1234) testPassed = true;
    else testPassed = false;
    
    // segni non riconosciuti midway
    s = '123!4';
    if (stoib(*pS, 10, pR) == 3 && *r == 123) testPassed = true;
    else testPassed = false;
    
    // segni non riconosciuti inizio
    s = '!1234';
    if (stoib(*pS, 10, pR) == 0) testPassed = true;
    else testPassed = false;
    
*/
    if (testPassed == true) printf("TEST PASSED\n");
    else printf("TEST PASSED\n");
    
    return 0;
}
