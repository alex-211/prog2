// final code handed in on moodle
// funzioni di supporto
RAM initram_internal(int M) 
{
    if (M < 1) return NULL;
    if ((M & (M-1)) != 0) return NULL; // "se non è una potenza di 2"

    RAM r = malloc(sizeof(struct nodo));
    if (r == NULL)
    {
        printf("initram failed to create ram node\n");
        return NULL;
    }
    r->parent = NULL;
    r->KB = M;
    r->s = LIBERO;
    r->lbuddy = NULL;
    r->rbuddy = NULL;

    return r;
}

int ramCounter(RAM ram)
{
    if (ram == NULL) return 0;
    return 1 + ramCounter(ram->lbuddy) + ramCounter(ram->rbuddy);
}

/**
* @brief Crea una struttura RAM con una certa quantità di memoria  
* @param M la quantità di memoria voluta, espressa in KB (deve essere una potenza di 2, maggiore o uguale a 1)
* @return Il puntatore alla struttura creata, oppure NULL in caso di errore
*/
RAM initram(int M) 
{
    if (M < 1) return NULL;
    if ((M & (M-1)) != 0) return NULL; // "se non è una potenza di 2"

    RAM r = malloc(sizeof(*r));
    if (r == NULL)
    {
        printf("initram failed to create ram node\n");
        free(r);
        return NULL;
    }
    r->parent = NULL;
    r->KB = M;
    r->s = LIBERO;
    r->lbuddy = NULL;
    r->rbuddy = NULL;

    return r;
}


/**
* @brief Tenta di allocare una data quantità di memoria entro una RAM
* @param K la quantità di memoria richiesta, in KB
* @param ram la RAM entro cui cercare la memoria richiesta
* @return Il puntatore al nodo che può ospitare la quantità richiesta, oppure NULL se non trovato
*/
RAM allocram(int K, RAM ram) 
{
    if (ram == NULL) return NULL;
    if (K<=0) return NULL;
    if (K > ram->KB) return NULL;
    if (ram->s == OCCUPATO) return NULL;

    if (ram->s == INTERNO)
    {
        RAM ris = allocram(K, ram->lbuddy);
        if (ris) return ris;
        ris = allocram(K, ram->rbuddy);
        return ris;
    }

    if (K > ram->KB / 2)
    {
        ram->s = OCCUPATO;
        return ram;
    }
    RAM left = initram(ram->KB / 2);
    RAM right = initram(ram->KB / 2);
    if (left == NULL || right == NULL) return NULL;
    left->parent = ram;
    right->parent = ram;
    ram->rbuddy = right;
    ram->lbuddy = left;
    ram->s = INTERNO;

    return allocram(K, left);
}


/**
* @brief Libera un nodo RAM precedentemente ottenuto con allocram    
* @param ram il nodo RAM da liberare
* @return Il successo della operazione
*/
Risultato deallocram(RAM ram) 
{
    if (ram == NULL) return NOK;
    if (ram->s != OCCUPATO) return NOK; //? credo

    RAM currentNode = ram;
    ram->s = LIBERO;
    while (currentNode->parent != NULL)
    {
        RAM rParent = currentNode->parent;
        if (rParent->lbuddy->s == LIBERO && rParent->rbuddy->s == LIBERO)
        {
            free(rParent->lbuddy);
            rParent->lbuddy = NULL;
            free(rParent->rbuddy);
            rParent->rbuddy = NULL;
            rParent->s = LIBERO;
            currentNode = rParent;
        }
        else break;
        
    }
    return OK;
}


/**
* @brief calcola il numero di KB di memoria ancora liberi all'interno di una struttura RAM    
* @param ram la struttura RAM 
* @return La quantità di memoria libera, oppure -1 in caso di errore
*/
int numfree(RAM ram) 
{
    if (ram == NULL) return -1;
    if (ram->s == LIBERO) return ram->KB;
    if (ram->s == OCCUPATO) return 0;

    int leftie = 0;
    int rightie = 0;

    if (ram->lbuddy != NULL)
    {
        leftie = numfree(ram->lbuddy);
    }
    if (ram->rbuddy != NULL)
    {
        rightie = numfree(ram->rbuddy);
    }

    return leftie + rightie;
}


void ram2str_rec(char* string, RAM ram)
{
    if (ram == NULL) {
        strcat(string, "{N}");
        return;
    }

    char kb[20];
    char *s;
    if (ram->s == LIBERO) s = "L";
    else if (ram->s == OCCUPATO) s = "O";
    else s = "I";
    
    snprintf(kb, 20, "{%d,%s,[", ram->KB, s);
    strcat(string, kb);

    ram2str_rec(string, ram->lbuddy);
    strcat(string, ",");
    ram2str_rec(string, ram->rbuddy);
    
    strcat(string, "]}");
}


/**
* @brief crea una rappresentazione dello stato interno della RAM sotto forma di una stringa (in un formato a piacere, 
* purchè completo di tutte le informazioni, ovvero tale che si possa ricreare dalla stringa esattamente lo stesso stato)
* @param ram la struttura RAM di cui creare la stringa
* @return la stringa creata, vuota in caso di RAM nulla o errore
*/
char* ram2str(RAM ram) 
{
    if (ram == NULL)
    {
        char *pta = malloc(sizeof(char)*1);
        pta[0] = '\0';
        return pta;
    }
    int nodes = ramCounter(ram);
    char* string = malloc(nodes * 40 + (nodes + 1) * 3 + 1);
    if (string == NULL) return NULL;

    string[0] = '\0';
    ram2str_rec(string, ram);
    return string;
}

RAM str2ram_rec(char **ptr, RAM parent)
{
    char *s = *ptr;
    if (strncmp(s, "{N}", 3) == 0) {
        *ptr += 3;
        return NULL;
    }

    if (*s != '{') return NULL;
    s++;

    int kb = atoi(s);
    while (*s >= '0' && *s <= '9') s++;
    if (*s != ',') return NULL;
    s++;

    Stato stato;
    if (*s == 'L') stato = LIBERO;
    else if (*s == 'O') stato = OCCUPATO;
    else if (*s == 'I') stato = INTERNO;
    else return NULL;
    s++; 
    if (*s != ',') return NULL;
    s++; 
    if (*s != '[') return NULL;
    s++;

    RAM r = initram_internal(kb);
    if (r == NULL) return NULL;
    r->s = stato;
    r->parent = parent;

    *ptr = s;
    r->lbuddy = str2ram_rec(ptr, r);
    s = *ptr;
    if (*s != ',') return NULL;
    s++; 
    *ptr = s;
    r->rbuddy = str2ram_rec(ptr, r);
    s = *ptr;

    if (*s != ']') return NULL;
    s++; 
    if (*s != '}') return NULL;
    s++; 

    *ptr = s;
    return r;
}

/**
* @brief ricostruisce una struttura RAM a partire dalla sua rappresentazione sotto forma di stringa creata da ram2str 
* @param s  la stringa che contiene la rappresentazione della RAM, eventualmente vuota
* @return la RAM creata, oppure NULL in caso di errore o stringa vuota
*/
RAM str2ram(char *str)
{
    if (str == NULL || strlen(str) == 0 || strcmp(str, "{N}") == 0) return NULL;
    char *ptr = str;
    return str2ram_rec(&ptr, NULL);
}


/**
* @brief cancella dallo heap la struttura dati di un nodo RAM e di tutti i suoi figli  
* @param ram il nodo RAM da cancellare
* @return Restituisce OK se la funzione ha effettivamente liberato della memoria, NOK altrimenti
*/
Risultato freeram(RAM* ramptr) 
{
    if (ramptr == NULL || *ramptr == NULL) return NOK;

    if ((*ramptr)->lbuddy != NULL) freeram((&(*ramptr)->lbuddy));
    if ((*ramptr)->rbuddy != NULL) freeram((&(*ramptr)->rbuddy));

    free(*ramptr);
    *ramptr = NULL;
    return OK;
}
