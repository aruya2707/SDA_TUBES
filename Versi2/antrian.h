#ifndef antrian_H
#define antrian_H
#include "cassier.h"
#define First(L) (L).First
#define NmPmbli(P) (P)->NmPmbli
#define Barang(P) (P)->barang
#define Next(P) (P)->next
#define NmBrng(P) (P)->NmBrng
#define StokBrng(P) (P)->StokBrng
#define HrgBrng(P) (P)->HrgBrng

/***Deklarasi Variabel***/
typedef struct Customer *address;	//node2 di queue
typedef struct ListBarang *addresslist;

typedef struct{
	infotype kasir_1,kasir_2,kasir_3;
}kasir;

typedef struct Customer{
	addressbrg barang;	//menunjuk ke node BrgBelian
	infochar NmPmbli;	//nama pembeli
//	bool membawaTroli;	//untuk troli atau keranjang
	address next;	//pointer ke node pelanggan di depannya
}Customer;

typedef struct BrgBelian{
	infochar NmBrg;
	infotype HrgBrg, JmlBrg;
	addressbrg NextBrg;
}BrgBelian;
//pointer ke Queue
typedef struct {
	address First;
}List;

/***Deklarasi Modul***/
void CreateList(List *L);
//terbentuk list kosong untuk pointer First
void CreateListBelian(addressbrg *L);
//Alokasi barang belanjaan
boolean IsEmpty(List L);
/* Mengirim true jika List Kosong */
address Alokasi_Antrian(infochar X);
/* Mengirimkan address hasil alokasi sebuah elemen */
void Enqueue_Belanja();
//Membaca file yang berisi barang belanjaan;
void InsertLast(List *L, address P);
//menginsertkan customer ke queue
void Enqueue(List *L, infochar X);
/*melakukan alokasi elemen */
void Dequeue(List *L);
/*menghapus node setelah melakukan transaksi di kasir*/

#endif