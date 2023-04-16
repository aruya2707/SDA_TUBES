#include <stdio.h>
#include <stdlib.h>
#include "antrian.h"

void CreateList(List *L){
	First(*L) = NULL;
}

void CreateListBelian(addressbrg *L){
	*L = (addressbrg)malloc(sizeof(BrgBelian));
}

boolean IsEmpty(List L){
/* Mengirim true jika List Kosong */	
	if(First(L) == NULL){
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


void InsertLast(List *L, address P){
	address Last;
	
	if (First(*L) != NULL){
		Last = First(*L);
		while (Next(Last) != NULL){
			Last = Next(Last);
		}
		Next(Last) = P;
	}
	else
	{
		First(*L) = P;
	}
}


void Enqueue(List *L, infochar X)
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
		InsertLast(&(*L),P);	
	//setelah mengalami perubahan input G ke antrian
	}
}


void Dequeue(List *L){
	//customer sampai di kasir
	address P;
	P = First(*L);
	First(*L) = Next(First(*L));
	
	//P dismpan untuk history dan struk belanja nantinya
	//DeAlokasi(P);
}
