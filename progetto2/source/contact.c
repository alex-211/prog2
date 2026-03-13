#include <stdio.h>
#include <string.h>

#include "contact.h"

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**

 * @brief Controlla se due contatti hanno lo stesso nome e cognome.
 *
 * Restituisce:
 * - 1 se i due contatti sono uguali, 0 se sono diversi, -99 se qualche name o surname è NULL
 *
 * @param c1 primo contatto.
 * @param c2 secondo contatto.
 * @return  1, 0, o -99.
 *
 * <ENGLISH VERSION>
 *
 * @brief Checks is two contacts have same name and surname.
 *
 * Returns:
 * - 1 if the contacts are equal, 0 is they are different, -99 is some name o surname is NULL
 *
 * @param c1 first contact.
 * @param c2 second contact.
 * @return  1, 0, o -99 (see above).
 */

int contactEq(Contact c1, Contact c2) {

    return 0;

}

/**
 * Invoca la funzione contactEq su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 *
 * <ENGLISH VERSION>
 *
 * Invokes the contactEq function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 *
 * NOTE: this function appears in compilation errors as "student_main"
 */

int test_contactEq() {

    return 0; 

}

// come per contactEq
// same as for contactEq
int contactEqEff(const Contact *pc1, const Contact *pc2) {

    return 0;

}

// come per test_contactEq
// same as for test_contactEq
int test_contactEqEff() {

    return 0;

}

// come per contactEq
// same as for contactEq
int contactCmp(Contact c1, Contact c2) {

    return 0;

}

// come per test_contactEq
// same as for test_contactEq
int test_contactCmp() {

    return 0; 

}

// come per test_contactEq
// same as for test_contactEq
int contactCmpEff(const Contact *pc1, const Contact *pc2) {

    return 0;

}

// come per test_contactEq
// same as for test_contactEq
int test_contactCmpEff() {

    return 0;

}
