#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "contact.h"

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
int contactEq(Contact c1, Contact c2)
{
    bool eq = true;
    int i = 0;
    
    // check for null data
    if (c1.name == NULL || c1.surname == NULL || c2.name == NULL ||  c2.surname == NULL) return -99;
    
    // check the chars of the name
    while (c1.name[i] != '\0' && c2.name[i] != '\0')
    {
        if (toupper(c1.name[i]) != toupper(c2.name[i]))
        {
            eq = false;
            break;
        }
        i++;
    }
    
    // check for name length
    if (c1.name[i] != '\0' || c2.name[i] != '\0') eq = false;
    
    // if the name is the same
    if (eq == true)
    {
        i = 0;
        
        // check surname chars
        while(c1.surname[i] != '\0' && c2.surname[i] != '\0')
        {
            if (toupper(c1.surname[i]) != toupper(c2.surname[i]))
            {
                eq = false;
                break;
            }
            i++;
        }
        
        // check surname length
        if (c1.surname[i] != '\0' || c2.surname[i] != '\0') eq = false;
    }
    
    return eq;
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
int test_contactEq()
{
    Contact c1;
    Contact c2;
    bool passed = true;
    int ris;
    
    // null cases 
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "luca";
    c2.surname = "rossi";
    ris = contactEq(c1,c2);
    if (ris != -99) passed = false;;
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = NULL;
    c2.surname = NULL;
    ris = contactEq(c1,c2);
    if (ris != -99) passed = false;
    
    // same name lowercase
    c1.name = "mario";
    c1.surname = "rossi";
    c2.name = "mario";
    c2.surname = "rossi";
    ris = contactEq(c1,c2);
    if (ris != 1) passed = false;
    
    // same name uppercase
    c1.name = "MARIO";
    c1.surname = "ROSSI";
    c2.name = "mario";
    c2.surname = "rossi";
    ris = contactEq(c1,c2);
    if (ris != 1) passed = false;
    
    // different name
    c1.name = "mario";
    c1.surname = "caruso";
    c2.name = "mario";
    c2.surname = "rossi";
    ris = contactEq(c1,c2);
    
    if (ris != 0) passed = false;
    
    // different surnames
    c1.name = "luca";
    c1.surname = "rossi";
    c2.name = "mario";
    c2.surname = "rossi";
    ris = contactEq(c1,c2);
    
    if(ris != 0) passed = false; 
    
    if (passed == true) printf("TEST PASSED\n");
    else if (passed == false) printf("TEST FAILED\n");
    
    return 0;
}

int contactEqEff(const Contact *pc1, const Contact *pc2)
{
    bool eq = true;
    int i = 0;
    
    // check pointer validity
    if (pc1 == NULL || pc2 == NULL) return -99;
    
    // check for null data
    if (pc1->name == NULL || pc1->surname == NULL || pc2->name == NULL ||  pc2->surname == NULL) return -99;
    
    // check the chars of the name
    while (pc1->name[i] != '\0' && pc2->name[i] != '\0')
    {
        if (toupper(pc1->name[i]) != toupper(pc2->name[i]))
        {
            eq = false;
            break;
        }
        i++;
    }
    
    // check for name length
    if (pc1->name[i] != '\0' || pc2->name[i] != '\0') eq = false;
    
    // if the name is the same
    if (eq == true)
    {
        i = 0;
        
        // check surname chars
        while(pc1->surname[i] != '\0' && pc2->surname[i] != '\0')
        {
            if (toupper(pc1->surname[i]) != toupper(pc2->surname[i]))
            {
                eq = false;
                break;
            }
            i++;
        }
        
        // check surname length
        if (pc1->surname[i] != '\0' || pc2->surname[i] != '\0') eq = false;
    }
    
    return eq;
}

int test_contactEqEff()
{
    Contact c1;
    Contact c2;
    bool passed = true;
    int ris;
    
    // null cases
    c1.name = "Luca";
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris = contactEqEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = NULL;
    ris = contactEqEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris = contactEqEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = "Bianchi";
    ris = contactEqEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    ris = contactEqEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris = contactEqEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    // same surnames
    c1.name = "A";
    c1.surname = "Rossi";
    c2.name = "B";
    c2.surname = "ROSSI";
    ris = contactEqEff(&c1, &c2);
    if (ris != 0) passed = false;
    
    c1.name = "B";
    c1.surname = "Rossi";
    c2.name = "A";
    c2.surname = "ROSSI";
    ris = contactEqEff(&c1, &c2);
    if (ris != 0) passed = false;
    
    
    // same names
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Luca";
    c2.surname = "Bianchi";
    ris = contactEqEff(&c1, &c2);
    if (ris != 0) passed = false;
    
    // same name, case sensitive
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "LUCA";
    c2.surname = "Rossi";
    ris = contactEqEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    // same surname, case sensitive
    c1.name = "Luca";
    c1.surname = "rossi";
    c2.name = "Luca";
    c2.surname = "ROSSI";
    ris = contactEqEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    if (passed == true) printf("TEST PASSED\n");
    else if (passed == false) printf("TEST FAILED\n");
    
    return 0;
}

int contactCmp(Contact c1, Contact c2) 
{
    // check for null data
    if (c1.name == NULL || c1.surname == NULL || c2.name == NULL || c2.surname == NULL) return -99;
    
    int ris = 0;
    int i = 0;
    
    // check surnames
    while(c1.surname[i] != '\0' || c2.surname[i] != '\0')
    {
        char char1 = toupper(c1.surname[i]);
        char char2 = toupper(c2.surname[i]);
        
        if (char1 > char2)
        {
            ris = 1;
            break;
        }
        if (char1 < char2)
        {
            ris = -1;
            break;
        }
        i++;
    }
    
    // if surnames are equal
    if (ris == 0)
    {
        i = 0;
        
        // check names
        while (c1.name[i] != '\0' || c2.name[i] != '\0')
        {
            char char1 = toupper(c1.name[i]);
            char char2 = toupper(c2.name[i]);
        
            if (char1 > char2)
            {
                ris = 1;
                break;
            }
            if (char1 < char2)
            {
                ris = -1;
                break;
            }
            i++;
        }
    }
    
    return ris;
}

int test_contactCmp() 
{
    Contact c1;
    Contact c2;
    bool passed = true;
    int ris;
    
    // null cases
    c1.name = "Luca";
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris  = contactCmp(c1, c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = NULL;
    ris  = contactCmp(c1, c2);
    if (ris != -99) passed = false;
    
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris  = contactCmp(c1, c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    ris  = contactCmp(c1, c2);
    if (ris != -99) passed = false;
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris  = contactCmp(c1, c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    ris  = contactCmp(c1, c2);
    if (ris != -99) passed = false;
    
    // c1 > c2
    c1.name = "B";
    c1.surname = "Rossi";
    c2.name = "A";
    c2.surname = "Rossi";
    ris  = contactCmp(c1, c2);
    if (ris != 1) passed = false;
    
    c1.name = "B";
    c1.surname = "C";
    c2.name = "A";
    c2.surname = "B";
    ris  = contactCmp(c1, c2);
    if (ris != 1) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Beno";
    c2.name = "Luca";
    c2.surname = "Bena";
    ris  = contactCmp(c1, c2);
    if (ris != 1) passed = false;
    
    c1.name = "Beno";
    c1.surname = "Rossi";
    c2.name = "Bena";
    c2.surname = "Rossi";
    ris  = contactCmp(c1, c2);
    if (ris != 1) passed = false;
    
    // c2 > c1
    c1.name = "Bena";
    c1.surname = "Rossi";
    c2.name = "Beno";
    c2.surname = "Rossi";
    ris  = contactCmp(c1, c2);
    if (ris != -1) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Bena";
    c2.name = "Luca";
    c2.surname = "Beno";
    ris  = contactCmp(c1, c2);
    if (ris != -1) passed = false;
    
    // same names (case sensitive)
    c1.name = "Luca";
    c1.surname = "rossi";
    c2.name = "LUCA";
    c2.surname = "rossi";
    ris  = contactCmp(c1, c2);
    if (ris != 0) passed = false;
    
    // same surnames (case sensitive)
    c1.name = "Luca";
    c1.surname = "rossi";
    c2.name = "Luca";
    c2.surname = "ROSSI";
    ris  = contactCmp(c1, c2);
    if (ris != 0) passed = false;
    
    c1.name = "Luca";
    c1.surname = "b";
    c2.name = "Luca";
    c2.surname = "A";
    ris  = contactCmp(c1, c2);
    if (ris != 1) passed = false;
    
    c1.name = "Marco";
    c1.surname = "A";
    c2.name = "Marco";
    c2.surname = "b";
    ris  = contactCmp(c1, c2);
    if (ris != -1) passed = false;
    
    if (passed == true) printf("TEST PASSED\n");
    else printf("TEST FAILED\n");
    
    return 0; 
}

int contactCmpEff(const Contact *pc1, const Contact *pc2) 
{
    // check for null pointers
    if (pc1 == NULL || pc2 == NULL) return -99;
    
    // check for null data
    if (pc1->name == NULL || pc1->surname == NULL || pc2->name == NULL || pc2->surname == NULL) return -99;
    
    int ris = 0;
    int i = 0;
    
    // check surnames
    while(pc1->surname[i] != '\0' || pc2->surname[i] != '\0')
    {
        char char1 = toupper(pc1->surname[i]);
        char char2 = toupper(pc2->surname[i]);
        
        if (char1 > char2)
        {
            ris = 1;
            break;
        }
        if (char1 < char2)
        {
            ris = -1;
            break;
        }
        i++;
    }
    
    // if surnames are equal
    if (ris == 0)
    {
        i = 0;
        
        // check names
        while (pc1->name[i] != '\0' || pc2->name[i] != '\0')
        {
            char char1 = toupper(pc1->name[i]);
            char char2 = toupper(pc2->name[i]);
        
            if (char1 > char2)
            {
                ris = 1;
                break;
            }
            if (char1 < char2)
            {
                ris = -1;
                break;
            }
            i++;
        }
    }
    
    return ris;
}

int test_contactCmpEff() 
{
    Contact c1;
    Contact c2;
    bool passed = true;
    int ris;
    
    // null cases
    c1.name = "Luca";
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = NULL;
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -99) passed = false;
    
    // c1 > c2
    c1.name = "B";
    c1.surname = "Rossi";
    c2.name = "A";
    c2.surname = "Rossi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    c1.name = "B";
    c1.surname = "C";
    c2.name = "A";
    c2.surname = "B";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Beno";
    c2.name = "Luca";
    c2.surname = "Bena";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    c1.name = "Beno";
    c1.surname = "Rossi";
    c2.name = "Bena";
    c2.surname = "Rossi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    // c2 > c1
    c1.name = "Bena";
    c1.surname = "Rossi";
    c2.name = "Beno";
    c2.surname = "Rossi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -1) passed = false;
    
    c1.name = "Luca";
    c1.surname = "Bena";
    c2.name = "Luca";
    c2.surname = "Beno";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -1) passed = false;
    
    // same names (case sensitive)
    c1.name = "Luca";
    c1.surname = "rossi";
    c2.name = "LUCA";
    c2.surname = "rossi";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 0) passed = false;
    
    // same surnames (case sensitive)
    c1.name = "Luca";
    c1.surname = "rossi";
    c2.name = "Luca";
    c2.surname = "ROSSI";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 0) passed = false;
    
    c1.name = "Luca";
    c1.surname = "b";
    c2.name = "Luca";
    c2.surname = "A";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != 1) passed = false;
    
    c1.name = "Marco";
    c1.surname = "A";
    c2.name = "Marco";
    c2.surname = "b";
    ris  = contactCmpEff(&c1, &c2);
    if (ris != -1) passed = false;
    
    if (passed == true) printf("TEST PASSED\n");
    else printf("TEST FAILED\n");
    
    return 0;
}
