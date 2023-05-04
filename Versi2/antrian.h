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
#define Head(L) (L).Head
#define Nil NULL

/***Deklarasi Variabel***/
typedef struct Customer *address;	//node2 di queue
typedef struct BrgBelian *addressbrg;	//pointer ke list barang belanjaan

//typedef struct{
//	infotype kasir_1,kasir_2,kasir_3;
//}kasir;
typedef struct Kasir{
	infochar info;
	address queue;
}Kasir;

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
}Queue;

typedef struct {
	addressbrg Head;
}ListBrg;

/***Deklarasi Modul***/
void CreateKasir(Kasir K[]);
//membuat array list kasir
void CreateQueue(Queue *Q);
//terbentuk list kosong untuk pointer First
void CreateListBrg(ListBrg *L);
//Alokasi barang belanjaan
boolean IsEmpty(Queue Q);
/* Mengirim true jika List Kosong */
address Alokasi_Antrian(infochar X);
/* Mengirimkan address hasil alokasi sebuah elemen */
void Enqueue_Belanja();
//Membaca file yang berisi barang belanjaan;
void InsertLast(Queue *Q, address P);
//menginsertkan customer ke queue
void Enqueue(Queue *Q, infochar X);
/*melakukan alokasi elemen */
void Dequeue(Queue *Q);
/*menghapus node setelah melakukan transaksi di kasir*/

#endif
