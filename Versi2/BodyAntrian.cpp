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
address Alokasi_Antrian(infochar X){

/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

	address P;
	P = (address)malloc(sizeof(Customer));
	if(P != NULL){ //alokasi berhasil
		NmPmbli(P) = X;
		Barang(P) = NULL;
		Next(P) = NULL;
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

void Enqueue(Queue *Q, infochar X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	address P;
	//addreslist
	//Alokasi
	P = Alokasi_Antrian(X);
	if(P != NULL)
	{
	//Tampilkan barang barang belanjaan
	//memilih barang belanjaan
	//TampilListBarang();
	
	//pilihan disimpan ke G
		InsertLast(&(*Q),P);	
	//setelah mengalami perubahan input G ke antrian
	}
}

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