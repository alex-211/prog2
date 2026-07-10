#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
 */
int contactEq(Contact c1, Contact c2) {
    
    int result = 1;
    int i=0;
    
    if( c1.name== NULL || c2.name==NULL || c1.surname==NULL || c2.surname==NULL){
        return -99;
    }
    
    while(c1.name[i]!='\0' && c2.name[i]!='\0'){
        
        if( (toupper (c1.name[i])) != toupper((c2.name[i])) ){
           result=0;
           break;
        }
        
        i++;
    }
    
    if(strlen(c1.name)>strlen(c2.name) || strlen(c1.name)<strlen(c2.name)  ){
        result=0;
    }
    
    if(result==1){
        i=0;
        
        while(c1.surname[i]!='\0' && c2.surname[i]!='\0'){
            if(( toupper (c1.surname[i])) != toupper((c2.surname[i])) ){
                result=0;
                break;
            }
        i++;
        }
        
        if(strlen(c1.surname)>strlen(c2.surname) || strlen(c1.surname)<strlen(c2.surname)  ){
            result=0;
        }
    }
    
    
    
    
    return result;
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
 */
 
int test_contactEq() {
    
    Contact c1;
    Contact c2;
    int flag=1;
    
    //NULL
    c1.name= NULL;
    c1.surname=NULL;
    c2.name="luca";
    c2.surname="rossi";
    int risultato= contactEq(c1,c2);
    
    if(risultato!=-99){
        flag=0;
    }
    
    c1.name= NULL;
    c1.surname= NULL;
    c2.name=NULL;
    c2.surname=NULL;
    risultato= contactEq(c1,c2);
    
    if(risultato!=-99){
        flag=0;
    }
    
    c1.name="mario";
    c1.surname="rossi";
    c2.name="mario";
    c2.surname="rossi";
    risultato= contactEq(c1,c2);

    if(risultato!=1){
        flag=0;
    }
    
    //nomi uguali 
    c1.name="MARIO";
    c1.surname="ROSSI";
    c2.name="mario";
    c2.surname="rossi";
    risultato= contactEq(c1,c2);
    
    if(risultato!=1){
        flag=0;
    }
    
    
    
    //nomi diversi
    c1.name="mario";
    c1.surname="caruso";
    c2.name="mario";
    c2.surname="rossi";
    risultato= contactEq(c1,c2);
    
    if(risultato!=0){
        flag=0;
    }
    
    //cognomi diversi
    c1.name="luca";
    c1.surname="rossi";
    c2.name="mario";
    c2.surname="rossi";
    risultato= contactEq(c1,c2);
    
    if(risultato!=0){
        flag=0;
    }
    
    
    
    
    if (flag==1){
        printf("TEST PASSED\n");
    }
    else if(flag==0){
        printf("TEST FAILED\n");
    }
    
    
    
    
    return 0;

}

// come per contactEq
// same as for contactEq
int contactEqEff(const Contact *pc1, const Contact *pc2) {
    
    int result = 1;
    int i=0;
    
    if( pc1->name== NULL || pc1->name==NULL || pc2->surname==NULL || pc2->surname==NULL){
        return -99;
    }
    
    while(pc1->name[i]!='\0' && pc2->name[i]!='\0'){
        
        if( (toupper (pc1->name[i])) != toupper((pc2->name[i])) ){
           result=0;
           break;
        }
        
        i++;
    }
    
    if(strlen(pc1->name)>strlen(pc2->name) || strlen(pc1->name)<strlen(pc2->name)  ){
        result=0;
    }
    
    if(result==1){
        i=0;
        
        while(pc1->surname[i]!='\0' && pc2->surname[i]!='\0'){
            if(( toupper (pc1->surname[i])) != toupper((pc2->surname[i])) ){
                result=0;
                break;
            }
        i++;
        }
        
        if(strlen(pc1->surname)>strlen(pc2->surname) || strlen(pc1->surname)<strlen(pc2->surname)  ){
            result=0;
        }
    }
    
    
    
    
    return result;

}

// come per test_contactEq
// same as for test_contactEq
int test_contactEqEff() {
    Contact c1;
    Contact c2;
    int flag = 1;
    int risultato;

    //cognomi null
    
    c1.name = "Luca";
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }

    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = NULL;
    risultato = contactEqEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //nomi null 
    
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }

    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //cognome e nome null
    
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    risultato = contactEqEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //cognomi uguali nomi diversi
    
    c1.name = "B";
    c1.surname = "Bianchi";
    c2.name = "A";
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != 0) {
        flag = 0;
    }
    
     c1.name = "A";
    c1.surname = "Bianchi";
    c2.name = "B";
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    //nomi uguali cognomi diversi
    
    c1.name = "Marco";
    c1.surname = "A";
    c2.name = "Marco";
    c2.surname = "B";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    c1.name = "Marco";
    c1.surname = "B";
    c2.name = "Marco";
    c2.surname = "A";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    //case sensitive nomi
    
    c1.name = "luca";
    c1.surname = "Bianchi";
    c2.name = "LUCA";
    c2.surname = "Bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    //case sensitive cognomi
    
    c1.name = "luca";
    c1.surname = "BIANCHI";
    c2.name = "luca";
    c2.surname = "bianchi";
    risultato = contactEqEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    

    if(flag == 1) {
        printf("TEST PASSED\n");
    } else if(flag==0) {
        printf("TEST FAILED\n");
    }

    return 0;
}

// come per contactEq
// same as for contactEq
int contactCmp(Contact c1, Contact c2) {

    if (c1.name == NULL || c2.name == NULL || c1.surname == NULL || c2.surname == NULL) {
        return -99;
    }

    int result = 0;
    int i = 0;
    
    while (1) {
        char char1 = toupper(c1.surname[i]);
        char char2 = toupper(c2.surname[i]);

        if (char1 > char2) {
            result = 1;
            break;
        } else if (char1 < char2) {
            result = -1;
            break;
        }
        
        if (char1 == '\0' && char2 == '\0') {
            break;
        }
        
        i++;
    }

    if (result == 0) {
        i = 0; 
        
        while (1) {
            char char1 = toupper(c1.name[i]);
            char char2 = toupper(c2.name[i]);

            if (char1 > char2) {
                result = 1; 
                break;
            } else if (char1 < char2) {
                result = -1; 
                break;
            }

            if (char1 == '\0' && char2 == '\0'){
               break; 
            } 

            i++;
        }
    }

    return result;
}

// come per test_contactEq
// same as for test_contactEq
int test_contactCmp() {
     
    Contact c1;
    Contact c2;
    int flag = 1;
    int risultato;

    //cognomi null
    
    c1.name = "Luca";
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != -99) {
        flag = 0;
    }

    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = NULL;
    risultato = contactCmp(c1, c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //nomi null 
    
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != -99) {
        flag = 0;
    }

    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = "Bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //cognome e nome null
    
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    risultato = contactCmp(c1, c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //c1>c2
    
    c1.name = "B";
    c1.surname = "Bianchi";
    c2.name = "A";
    c2.surname = "Bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "B";
    c1.surname = "C";
    c2.name = "A";
    c2.surname = "B";
    risultato = contactCmp(c1, c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "A";
    c1.surname = "barco";
    c2.name = "A";
    c2.surname = "barca";
    risultato = contactCmp(c1, c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "barco";
    c1.surname = "A";
    c2.name = "barca";
    c2.surname = "A";
    risultato = contactCmp(c1, c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    //c2>c1
    
    c1.name = "barca";
    c1.surname = "A";
    c2.name = "barco";
    c2.surname = "A";
    risultato = contactCmp(c1, c2);
    if(risultato != -1) {
        flag = 0;
    }
    
    c1.name = "A";
    c1.surname = "barca";
    c2.name = "A";
    c2.surname = "barco";
    risultato = contactCmp(c1, c2);
    if(risultato != -1) {
        flag = 0;
    }
    
    
    //case sensitive nomi
    
    c1.name = "luca";
    c1.surname = "Bianchi";
    c2.name = "LUCA";
    c2.surname = "Bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    //case sensitive cognomi
    
    c1.name = "luca";
    c1.surname = "BIANCHI";
    c2.name = "luca";
    c2.surname = "bianchi";
    risultato = contactCmp(c1, c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    c1.name = "Marco";
    c1.surname = "b";
    c2.name = "Marco";
    c2.surname = "A";
    risultato = contactCmp(c1, c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "Marco";
    c1.surname = "A";
    c2.name = "Marco";
    c2.surname = "b";
    risultato = contactCmp(c1, c2);
    if(risultato != -1) {
        flag = 0;
    }
    

    if(flag == 1) {
        printf("TEST PASSED\n");
    } else if(flag==0) {
        printf("TEST FAILED\n");
    }

    return 0;
}

// come per test_contactEq
// same as for test_contactEq
int contactCmpEff(const Contact *pc1, const Contact *pc2) {
    
    if (pc1->name == NULL || pc2->name == NULL || pc1->surname == NULL || pc2->surname == NULL) {
        return -99;
    }

    int result = 0;
    int i = 0;
    
    while (1) {
        char char1 = toupper(pc1->surname[i]);
        char char2 = toupper(pc2->surname[i]);

        if (char1 > char2) {
            result = 1;
            break;
        } else if (char1 < char2) {
            result = -1;
            break;
        }
        
        if (char1 == '\0' && char2 == '\0') {
            break;
        }
        
        i++;
    }

    if (result == 0) {
        i = 0; 
        
        while (1) {
            char char1 = toupper(pc1->name[i]);
            char char2 = toupper(pc2->name[i]);

            if (char1 > char2) {
                result = 1; 
                break;
            } else if (char1 < char2) {
                result = -1; 
                break;
            }

            if (char1 == '\0' && char2 == '\0'){
               break; 
            } 

            i++;
        }
    }

    return result;
}

// come per test_contactEq
// same as for test_contactEq
int test_contactCmpEff() {
    Contact c1;
    Contact c2;
    int flag = 1;
    int risultato;

    //cognomi null
    
    c1.name = "Luca";
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }

    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = NULL;
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //nomi null 
    
    c1.name = NULL;
    c1.surname = "Rossi";
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }

    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = "Bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //cognome e nome null
    
    
    c1.name = "Luca";
    c1.surname = "Rossi";
    c2.name = NULL;
    c2.surname = NULL;
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    c1.name = NULL;
    c1.surname = NULL;
    c2.name = "Marco";
    c2.surname = "Bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -99) {
        flag = 0;
    }
    
    //c1>c2
    
    c1.name = "B";
    c1.surname = "Bianchi";
    c2.name = "A";
    c2.surname = "Bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "B";
    c1.surname = "C";
    c2.name = "A";
    c2.surname = "B";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "A";
    c1.surname = "barco";
    c2.name = "A";
    c2.surname = "barca";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "barco";
    c1.surname = "A";
    c2.name = "barca";
    c2.surname = "A";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    //c2>c1
    
    c1.name = "barca";
    c1.surname = "A";
    c2.name = "barco";
    c2.surname = "A";
   risultato = contactCmpEff(&c1, &c2);
    if(risultato != -1) {
        flag = 0;
    }
    
    c1.name = "A";
    c1.surname = "barca";
    c2.name = "A";
    c2.surname = "barco";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -1) {
        flag = 0;
    }
    
    
    //case sensitive nomi
    
    c1.name = "luca";
    c1.surname = "Bianchi";
    c2.name = "LUCA";
    c2.surname = "Bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    //case sensitive cognomi
    
    c1.name = "luca";
    c1.surname = "BIANCHI";
    c2.name = "luca";
    c2.surname = "bianchi";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != 0) {
        flag = 0;
    }
    
    c1.name = "Marco";
    c1.surname = "b";
    c2.name = "Marco";
    c2.surname = "A";
   risultato = contactCmpEff(&c1, &c2);
    if(risultato != 1) {
        flag = 0;
    }
    
    c1.name = "Marco";
    c1.surname = "A";
    c2.name = "Marco";
    c2.surname = "b";
    risultato = contactCmpEff(&c1, &c2);
    if(risultato != -1) {
        flag = 0;
    }
    

    if(flag == 1) {
        printf("TEST PASSED\n");
    } else if(flag==0) {
        printf("TEST FAILED\n");
    }
    return 0;
}
