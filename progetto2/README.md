consegna moodle:
Sviluppare un modulo contact.c che implementi la specifica:

contact.h

In cui si definisce il seguente tipo di dato Contact: 

/**  Un tipo di dato per contatti telefonici e cyberspaziali */

typedef struct contact {

   char* name;

   char* surname;

   char* mobile;

   char* url;

} Contact, *ContactPtr;
e alcune funzioni di utilità che operano su di esso. 
Applicare la metodologia TDD, procedendo in modo iterativo e incrementale.

ATTENZIONE: le differenze maiuscole/minuscole non contano, ma non potete usare funzioni che non siano standard C, mentre potete usare macro come toupper e tolower definite in ctype.h

Ecco il codice di contact.c

===========================

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