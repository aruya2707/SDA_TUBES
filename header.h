#ifndef Header_H
#define Header_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>
#include <limits.h>
#include "boolean.h"
#define First(L) (L).First
#define NmPmbli(P) (P)->NmPmbli
#define Barang(P) (P)->barang
#define Next(P) (P)->next
#define NmBrng(P) (P)->NmBrng
#define StokBrng(P) (P)->StokBrng
#define HrgBrng(P) (P)->HrgBrng

/*Deklarasi Kamus data*/
typedef char* infochar;
typedef int infotype;
typedef struct Customer *address;	//node2 di queue
typedef struct BrgBelian *addressbrg;	//node yg ditunjuk queue sebagai barang belian
typedef struct ListBarang *addresslist;

//infochar Kasir[3] = {"kasir1", "kasir2","kasir3"};	//array kasir
typedef struct{
	infotype kasir_1,kasir_2,kasir_3;
}kasir;

typedef struct Customer{
	addressbrg barang;	//menunjuk ke node BrgBelian
	infochar NmPmbli;	//nama pembeli
//	bool membawaTroli;	//untuk troli atau keranjang
	address next;	//pointer ke node pelanggan di depannya
}Customer;

/*Node yang berisi list2 barang dagangan ada stok dan harga
dimana setiap pembelianstok akan berkurang dan data pilihan
dimasukkan ke node BrgBelian */
typedef struct ListBarang{
	infochar NmBrng;	
	infotype StokBrng,HrgBrng;
}ListBarang;

typedef struct BrgBelian{
	infochar NmBrg;
	infotype HrgBrg, JmlBrg;
	addressbrg NextBrg;
}BrgBelian;

//pointer ke Queue
typedef struct {
	address First;
}List;

#endif
