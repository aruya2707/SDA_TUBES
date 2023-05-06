#ifndef antrian_H
#define antrian_H
#include "cassier.h"
#define First(L) (L).First
#define NmPmbli(P) (P)->NmPmbli
#define Barang(P) (P)->barang
#define Next(P) (P)->next
#define NmBrg(P) (P)->NmBrg
#define StokBrg(P) (P)->StokBrg
#define HrgBrg(P) (P)->HrgBrg
#define JmlBrg(P) (P)->JmlBrg
#define NextBrg(P) (P)->NextBrg
#define Bawaan(P) (P)->Bawaan
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
	infochar Bawaan;	//untuk troli atau keranjang
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
//terbentuk pointer yang menunjuk BrgBelian
boolean IsEmpty(Queue Q);
/* Mengirim true jika List Kosong */
address Alokasi_Antrian(infochar X,infotype N);
/* Mengirimkan address hasil alokasi sebuah elemen */
addressbrg Alokasi_Barang(infochar nama, infotype harga, infotype jumlah);
//Mengirimkan address hasil alokasi elemen BrgBelian
void DeAlokasi_Antrian(address P);

void DeAlokasi_Barang (addressbrg P);

void InsertLast(Queue *Q, address P);
//menginsertkan customer ke queue
void InsertLastB(address *P, addressbrg Brg);

void InsVLastQ(Queue *Q, infochar X, infotype N);

//void InsVLastB(address *P,addressbrg *B);

void Enqueue(Queue *Q, infochar X);
/*melakukan alokasi elemen */
void Dequeue_Antrian(Queue *Q);
/*menghapus node setelah melakukan transaksi di kasir*/
void Dequeue_Barang(BrgBelian *B);


#endif
