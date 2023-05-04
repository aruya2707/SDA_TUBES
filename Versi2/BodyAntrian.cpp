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
address Alokasi_Antrian(infochar X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	P = (address)malloc(sizeof(Customer));
	if(P != NULL){ //alokasi berhasil
		NmPmbli(P) = X;
		Barang(P) = NULL;
		Next(P) = NULL;
	}
	return (P);
}

void DeAlokasi (address P){
	if(P != NULL){
		free(P);
	}
	
}


//
//void Enqueue_Belanja(ListBarang P[5]){
//	addressbrg L;
//	BrgBelian P_brg;
//	address P_cus;
//	CreateListBelian(&L);
//	
//	//Prompt the user to enter the item they want to buy and the quantity they want to purchase
//	int pilih, qty;
//	printf("\nMasukkan nomor barang yang ingin dibeli: ");
//	scanf("%d", &pilih);
//	printf("Masukkan jumlah yang ingin dibeli: ");
//	scanf("%d", &qty);
//
//	//Check if the item is in stock
//	if(P[pilih-1].StokBrng >= qty){
//		//Create a new BrgBelian node with the user's input
//		P_brg = (BrgBelian) malloc(sizeof(BrgBelian));
//		NmBrng(P_brg) = P[pilih-1].NmBrng;
//		HrgBrng(P_brg) = P[pilih-1].HrgBrng;
//		JmlBrg(P_brg) = qty;
//		NextBrg(P_brg) = NULL;
//
////Add the new BrgBelian node to the end of the customer's barang list
//		P_cus = (address) malloc(sizeof(Customer));
//		barang(P_cus) = L;
//		NmPmbli(P_cus) = "Pembeli";
//		next(P_cus) = NULL;
//		
//		if(First(L) == NULL){
//			
//		} 
//	}
//}


void InsertLast(Queue *Q, address P){
	address Last;
	
	if (First(*Q) != NULL){
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


void Dequeue(Queue *Q){
	//customer sampai di kasir
	address P;
	P = First(*Q);
	First(*Q) = Next(First(*Q));
	
	//P dismpan untuk history dan struk belanja nantinya
	//DeAlokasi(P);
}
