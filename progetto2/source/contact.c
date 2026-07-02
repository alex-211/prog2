#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/contact.h"

int contactEq(Contact c1, Contact c2) {
    if (c1.name == NULL || c1.surname == NULL || c2.name == NULL || c2.surname == NULL) {
        return -99;
    }
    if (strcmp(c1.name, c2.name) == 0 && strcmp(c1.surname, c2.surname) == 0) {
        return 1;
    }
    return 0;
}

int test_contactEq() 
{
    Contact c1, c2;
    
    // caso null
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactEq(c1, c2) != -99) {
        printf("TEST FAILED\n");
        return 0;
    }

    // different case
    c1.name = "Luigi";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactEq(c1, c2) != 0) {
        printf("TEST FAILED\n");
        return 0;
    }

    // equals case
    c1.name = "Mario";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactEq(c1, c2) != 1) {
        printf("TEST FAILED\n");
        return 0;
    }

    printf("TEST PASSED\n");
    return 0;
}

int contactEqEff(const Contact * const pc1, const Contact * const pc2) 
{
    if (pc1 == NULL || pc2 == NULL) return -99;
    if (pc1->name == NULL || pc1->surname == NULL || pc2->name == NULL || pc2->surname == NULL) return -99;
    if (strcmp(pc1->name, pc2->name) == 0 && strcmp(pc1->surname, pc2->surname) == 0) {
        return 1;
    }
    return 0;
}

int test_contactEqEff() 
{
    Contact c1, c2;
    
    // NULL pointer case
    if (contactEqEff(NULL, &c2) != -99) {
        printf("TEST FAILED\n");
        return 0;
    }

    // NULL field case
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactEqEff(&c1, &c2) != -99) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Different case
    c1.name = "Luigi";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactEqEff(&c1, &c2) != 0) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Equal case
    c1.name = "Mario";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactEqEff(&c1, &c2) != 1) {
        printf("TEST FAILED\n");
        return 0;
    }

    printf("TEST PASSED\n");
    return 0;
}

int contactCmp(Contact c1, Contact c2) 
{
    if (c1.name == NULL || c1.surname == NULL || c2.name == NULL || c2.surname == NULL) return -99;
    int cmp_surname = strcmp(c1.surname, c2.surname);
    if (cmp_surname < 0) return -1;
    if (cmp_surname > 0) return 1;
    int cmp_name = strcmp(c1.name, c2.name);
    if (cmp_name < 0) return -1;
    if (cmp_name > 0) return 1;
    return 0;
}

int test_contactCmp() 
{
    Contact c1, c2;
    
    // NULL field case
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmp(c1, c2) != -99) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Surname smaller
    c1.name = "Mario";
    c1.surname = "Bianchi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmp(c1, c2) != -1) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Surname larger
    c1.name = "Mario";
    c1.surname = "Verdi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmp(c1, c2) != 1) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Surnames equal, Name smaller
    c1.name = "Andrea";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmp(c1, c2) != -1) {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // Surnames equal, Name larger
    c1.name = "Zeno";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmp(c1, c2) != 1) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Equal
    c1.name = "Mario";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmp(c1, c2) != 0) {
        printf("TEST FAILED\n");
        return 0;
    }

    printf("TEST PASSED\n");
    return 0;
}

int contactCmpEff(const Contact * const pc1, const Contact * const pc2) {
    if (pc1 == NULL || pc2 == NULL) return -99;
    if (pc1->name == NULL || pc1->surname == NULL || pc2->name == NULL || pc2->surname == NULL) return -99;
    int cmp_surname = strcmp(pc1->surname, pc2->surname);
    if (cmp_surname < 0) return -1;
    if (cmp_surname > 0) return 1;
    int cmp_name = strcmp(pc1->name, pc2->name);
    if (cmp_name < 0) return -1;
    if (cmp_name > 0) return 1;
    return 0;
}

int test_contactCmpEff() {
    Contact c1, c2;
    
    // NULL pointer case
    if (contactCmpEff(NULL, &c2) != -99) {
        printf("TEST FAILED\n");
        return 0;
    }

    // NULL field case
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmpEff(&c1, &c2) != -99) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Surname smaller
    c1.name = "Mario";
    c1.surname = "Bianchi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmpEff(&c1, &c2) != -1) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Surname larger
    c1.name = "Mario";
    c1.surname = "Verdi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmpEff(&c1, &c2) != 1) {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // Surnames equal, Name smaller
    c1.name = "Andrea";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmpEff(&c1, &c2) != -1) {
        printf("TEST FAILED\n");
        return 0;
    }
    
    // Surnames equal, Name larger
    c1.name = "Zeno";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmpEff(&c1, &c2) != 1) {
        printf("TEST FAILED\n");
        return 0;
    }

    // Equal
    c1.name = "Mario";
    c1.surname = "Rossi";
    c2.name = "Mario";
    c2.surname = "Rossi";
    if (contactCmpEff(&c1, &c2) != 0) {
        printf("TEST FAILED\n");
        return 0;
    }

    printf("TEST PASSED\n");
    return 0;
}