#ifndef antrian_H
#define antrian_H
#include "cassier.h"

/***Deklarasi Variabel***/
typedef struct Customer *address;	//node2 di queue
typedef struct BrgBelian *addressbrg;	//pointer ke list barang belanjaan
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

void Kondisi_Enqueue(Kasir K[]);

void Enqueue(Queue *Q, infochar X);
/*melakukan alokasi elemen */
void Dequeue_Antrian(Queue *Q);
/*menghapus node setelah melakukan transaksi di kasir*/
void Dequeue_Barang(BrgBelian *B);

void MenuCustomer(Kasir K[]);

void TampilKasir(Kasir K[]);
#endif
