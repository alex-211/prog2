#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/contact.h"

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

// not sure i need this
int smallerStr(char* s1, char* s2)
{
    int lenS1 = strlen(s1);
    int lenS2 =  strlen(s2);
    if (lenS1 >= lenS2)
    {
        return lenS2;
    }
    return lenS1;
}

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

    Contact c1, c2;

    // caso empty string
    c1.name = "\0";
    c1.surname = "\0";
    c2.name = "\0";
    c2.surname = "\0";
    if (contactEq(c1, c2) != -99)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso roba a caso
    c1.name = "Giacomo";
    // c1.name should be null?
    c2.name = "Giacomo";
    c2.surname = "Squared";
    if (contactEq(c1, c2) != -99)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // Caso nomi diversi
    c1.name = "Giacomo";
    c1.surname = "Testaquadra";
    c2.name = "Jacob";
    c2.surname = "Squared";
    if (contactEq(c1, c2) != 0)
    {
        printf("TEST FAILED\n");
        return 0;
    } 

    // caso nomi uguali
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "Giacomo";
    c2.surname = "Squared";
    if (contactEq(c1, c2) != 1)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso nomi uguali ma uno maiusc
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "GIACOMO";
    c2.surname = "SQUARED";
    if (contactEq(c1, c2) != 1)
    {
        printf("TEST FAILED\n");
        return 0;
    } 

    printf("TEST PASSED\n");
    return 0;

}

// come per contactEq
// same as for contactEq
int contactEqEff(const Contact *pc1, const Contact *pc2) {

    // check for null pointers
    if (pc1 == NULL || pc2 == NULL) return -99;

    // check for empty strings
    if (strcmp(pc1->surname, "\0") != 0 || strcmp(pc1->name, "\0") == 0 ||
        strcmp(pc2->surname, "\0") != 0 || strcmp(pc2->name, "\0") == 0) return -99; // giving problems here debug

    // concatenate name + surname
    char name1[100];
    // strcpy(name1, strcat(pc1->name, pc1->surname)); // buffer overflow, didnt know how strcat works
    // it's like a printf except the output gets copied into a string, it's f ing nuts
    snprintf(name1, sizeof(name1), "%s%s", pc1->name, pc1->surname);
    char name2[100];
    snprintf(name2, sizeof(name2), "%s%s", pc2->name, pc2->surname);
    // strcpy(name2, strcat(pc2->name, pc2->surname));
    int len = smallerStr(name1, name2);

    // pretty much goes, if they are not the same length, they are deffo not equal
    if (name1[len] == '\0' && name2[len] != '\0') return 0;
    if (name1[len] != '\0' && name2[len] == '\0') return 0;

    for (int i = 0; i < len; i++)
    {
        if (toupper(name1[i]) != toupper(name2[i]))
        {
            return 0;
        }
    }

    return 1;

}

// come per test_contactEq
// same as for test_contactEq
int test_contactEqEff() {

    Contact c1, c2;
    Contact *pC1 = &c1;
    Contact *pC2 = &c2;

    // caso roba a caso
    c1.name = "Giacomo";
    // c1.name should be null?
    c2.name = "Giacomo";
    c2.surname = "Squared";
    if (contactEqEff(pC1, pC2) != -99)
    {
        printf("TEST FAILED");
        return 0;
    }

    // Caso nomi diversi
    c1.name = "Giacomo";
    c1.surname = "Testaquadra";
    c2.name = "Jacob";
    c2.surname = "Squared";
    if (contactEqEff(pC1, pC2) != 0)
    {
        printf("TEST FAILED");
        return 0;
    } 

    // caso nomi uguali
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "Giacomo";
    c2.surname = "Squared";
    if (contactEqEff(pC1, pC2) != 1)
    {
        printf("TEST FAILED");
        return 0;
    }

    // caso nomi uguali ma uno maiusc
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "GIACOMO";
    c2.surname = "SQUARED";
    if (contactEqEff(pC1, pC2) != 1)
    {
        printf("TEST FAILED");
        return 0;
    } 

    // caso gli passo null
    if (contactEqEff(NULL, NULL) != -99)
    {
        printf("TEST FAILED");
        return 0;
    }

    printf("TEST PASSED");
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

    if (pc1 == NULL || pc2 == NULL) return -99;

    int len;
    char n1[] = "";
    char n2[] = "";

    //! this doesn't work, it's case sensitive
    if (pc1->surname == pc2->surname) //? can we even compare strings like so?
    {
        strcpy(n1, pc1->name);
        strcpy(n2, pc2->name);
    }
    else 
    {
        strcpy(n1, pc1->surname);
        strcpy(n1, pc2->surname);
    }

    len = smallerStr(n1, n2);

    for (int i = 0; i < len; i++)
    {
        if (n1[i] > n2[i])
        {
            return 1;
        }
        else if (n1[i] < n2[i]) 
        {
            return -1;
        }

    }

    return 0;

}

// come per test_contactEq
// same as for test_contactEq
int test_contactCmpEff() {

    Contact c1, c2;
    Contact *pc1 = &c1;
    Contact *pc2 = &c2;

    // caso null
    if (contactCmpEff(NULL, NULL) != -99)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso diversi c1 < c2
    c1.surname = "Testaquadra";
    c2.surname = "Squared";
    if (contactCmpEff(pc1, pc2) != 1)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso diversi c2 < c1
    c2.surname = "Testaquadra";
    c1.surname = "Squared";
    if (contactCmpEff(pc1, pc2) != 2)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso stesso cognome
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "Jacob";
    c2.surname = "Squared";
    if (contactCmpEff(pc1, pc2) != 1)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso uguali
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "Giacomo";
    c2.surname = "Squared";
    if (contactCmpEff(pc1, pc2) != 0)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    // caso diversi ma uno maiusc
    c1.name = "Giacomo";
    c1.surname = "Squared";
    c2.name = "GIACOMO";
    c2.surname = "SQUARED";
    if (contactCmpEff(pc1, pc2) != 0)
    {
        printf("TEST FAILED\n");
        return 0;
    }

    printf("TEST PASSED\n");
    return 0;

}