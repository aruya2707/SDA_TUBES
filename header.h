#ifndef Header_H
#define Header_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* infochar;
typedef int infotype;
typedef struct Costumer *address;
typedef struct BrgBelian *addressbrng;

typedef struct kasir{
    int kasir_1, kasir_2, kasir_3;
}

typedef struct Costumer{
    addressbrg BrngBelian;
    infochar nmPmbli;
    address next;
}

typedef struct tListBarang{
    infochar NmBrng;
    infotype StokBrg;
    intotype HrgBrng;
}

typedef struct BrgBelian{
    infochar NmBarang;
    infotype HrgBarang;
    infotype JmlBarang;
    addressbrng NextBrng;
}

