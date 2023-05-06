#include <stdio.h>
#include <stdlib.h>
#include "antrian.h"
//membuat array list kasir
void CreateKasir(Kasir K[]){
	int i;
	infochar info[3] = {"kasir_1", "kasir_2" , "kasir_3"};
	for (i = 0; i < 3; i++){
		K[i].info = info[i];
		K[i].queue = NULL;
	}
}
void CreateQueue(Queue *Q){
	First(*Q) = Nil;
}
void CreateListBrg(ListBrg *L){
	Head(*L) = Nil;
}
boolean IsEmpty(Queue Q){
/* Mengirim true jika List Kosong */	
	if(First(Q) == NULL){
		return true;
	}else{
		return false;
	}
}
/**** Manajemen Memory ****/
address Alokasi_Antrian(infochar X,infotype N){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

	address P;
	P = (address)malloc(sizeof(Customer));
	if(P != NULL){ //alokasi berhasil
		if (N == 1){
			NmPmbli(P) = X;
			Bawaan(P) = "Troli";
			Barang(P) = Nil;
			Next(P) = Nil;
		}else{
			NmPmbli(P) = X;
			Bawaan(P) = "Keranjang";
			Barang(P) = Nil;
			Next(P) = Nil;
		}
	}
	return (P);
}
addressbrg Alokasi_Barang(infochar nama, infotype harga, infotype jumlah){
	addressbrg P;
	P = (addressbrg) malloc (sizeof (BrgBelian));
	
	if (P != Nil){
		NmBrg(P) = nama;
		HrgBrg(P) = harga;
		JmlBrg(P) = jumlah;
		NextBrg(P) = Nil;
	}
	return (P);
}
void DeAlokasi_Antrian (address P){
	if(P != Nil){
		free(P);
	}
}
void DeAlokasi_Barang (addressbrg P){
	if(P != Nil){
		free(P);
	}
}
/***Menghubungkan Link***/
void InsertLast(Queue *Q, address P){
	address Last;
	
	if (First(*Q) != Nil){
		Last = First(*Q);
		while (Next(Last) != NULL){
			Last = Next(Last);
		}
		Next(Last) = P;
	}
	else
	{
		First(*Q) = P;
	}
}
void InsertLastB (address *P, addressbrg Brg){
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
addressbrg Last;
if (Barang(*P) != Nil)
{
	Last = Barang(*P);
	while (NextBrg(Last) != Nil)
	{	Last = NextBrg(Last);}
		NextBrg(Last) = Brg;
	}else{
		Barang(*P) = Brg;
	}
}
//untuk Queue customer
void InsVLastQ(Queue *Q, infochar X, infotype N){
	address P;
	
	P = Alokasi_Antrian(X,N);
	if (P != Nil){
		InsertLast (&(*Q), P);
	}
}
//untuk menambahkan queue barang
//void InsVLastB(address *P, infotype X, infotype H, infotype J){
//	addressbrg Brg;
//parameter infochar nama, infotype harga, infotype jumlah
//	Brg = Alokasi_Barang (X,H,J);
//	if (Brg != Nil){
//		InsertLastB (&(*P), Brg);
//	}
//}
void Kondisi_Enqueue(Kasir K[]){
	// memilih kasir berdasarkan jumlah troli dalam queue pelanggan
    int min_troli = -1;
    int min_troli_idx = -1;
    int i;
    for (i = 0; i < 3; i++) {
        int troli_count = 0;
        address p = K[i].queue;
        while (p != Nil) {
            if (Bawaan(p) == "Troli") {
                troli_count++;
            }
            p = Next(p);
        }
        if (min_troli == -1 || troli_count < min_troli) {
            min_troli = troli_count;
            min_troli_idx = i;
        }
    }
}
//
//void Dequeue_Antrian(Queue *Q){
//	//customer sampai di kasir
//	address P;
//	P = First(*Q);
//	First(*Q) = Next(First(*Q));
//	DeAlokasi_Antrian(P);
//}
//
//void Dequeue_Barang(BrgBelian *B){
//	//customer sampai di kasir
//	address P;
//	P = Head(*B);
//	Head(*B) = NextBrg(Head(*B));
//	DeAlokasi_Barang(P);
//}
void TampilAntrian(){
	
}
