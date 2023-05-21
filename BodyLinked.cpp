#include "linked.h"

// List Pelanggan

boolean isEmpty_Pelanggan(address_P p){
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Pelanggan (address_P *p){
	
	*p = (address_P)malloc(sizeof(List_Pelanggan));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Pelanggan (address_P *p , address_K *k, infotype dompet, infotype2 nm_pelanggan, infotype nmr_ksr){
	
	if(isEmpty_Pelanggan(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Keranjang(*p) = *k;
		Dompet(*p) = dompet;
		Nm_pelanggan(*p) = nm_pelanggan;
		Nmr_ksr(*p) = nmr_ksr;
	}
	
}

void Tampil_List_Pelanggan (address_P p){
	int i = 1;
	if(isEmpty_Pelanggan(p)){
		printf("\t\t\t\tList Kosong\n");
	}
	else{		
		while(!isEmpty_Pelanggan(p)){
			printf("\t\t\t\t%d. Nama = %s \n\t\t\t\t   Nomor Kasir = %d",i,&p->Nm_pelanggan, p->Nmr_ksr);
			p = next(p);
			if(p != Nil){
				printf("\n");
			}
			i++;
			
		}
		printf("\n");
	}	
	
}

void Ins_Awal_Pelanggan (address_P *p, address_P PNew){
	
	next(PNew) = *p;
	*p = PNew;
	
}

void Ins_Akhir_Pelanggan (address_P *p, address_P PNew){
	
	address_P A;
	if(isEmpty_Pelanggan(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Pelanggan(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}

void InsertAfter_Pelanggan (address_P * pBef, address_P PNew){
	
	if(*pBef != NULL){
		printf("Searching Berhasil dengan Alamat %i\n",*pBef);
		next(PNew) = next(*pBef);
		next(*pBef) = PNew;
	}else{
		printf("Tidak Ada Data yang Dicari\n");
	}
	
}

void Del_Awal_Pelanggan (address_P * p, infotype2 * X){
	
	address_P A;
	
	if(isEmpty_Pelanggan(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = Nm_pelanggan(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
	
}


void Del_After_Pelanggan (address_P * pBef, infotype * X, infotype2 * Y){
	
	address_P A,B;
	
	if(*pBef == NULL){
		printf("Tidak Ada Data yang Dicari\n");
	}else if(next(*pBef) == NULL){
		printf("Tidak Ada Data Setelah Node\n");
	}else{
		printf("Searching Berhasil\n");
		A = next(*pBef);
		B = next(A);
		next(*pBef) = B;
		next(A) = NULL;
		free(A);
	}
	
}

void DeAlokasi_Pelanggan (address_P * p){
	
	*p = NULL;
	free(*p);
	
}


// List Barang

boolean isEmpty_Barang(address_B p){
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Barang (address_B *p){
	
	*p = (address_B)malloc(sizeof(ListBarang));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Barang (address_B *p , infotype harga, infotype2 nm_brg){
	
	if(isEmpty_Barang(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		HrgBrng(*p) = harga;
		strcpy(NmBrng(*p), nm_brg);
	}
	
}


void Tampil_List_Barang (address_B p){
	int i = 1;
	if(isEmpty_Barang(p)){
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Barang(p)){
			printf("%d. %s Rp.%d",i,p->NmBrng, p->HrgBrng);
			p = next(p);
			if(p != Nil){
				printf("\n");
			}
			i++;
		}
		printf("\n");
	}	
	
}

void Ins_Awal_Barang (address_B *p, address_B PNew){
	
	next(PNew) = *p;
	*p = PNew;
	
}

void Ins_Akhir_Barang (address_B *p, address_B PNew){
	
	address_B A;
	if(isEmpty_Barang(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Barang(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


void InsertAfter_Barang (address_B * pBef, address_B PNew){
	
	if(*pBef != NULL){
		printf("Searching Berhasil dengan Alamat %i\n",*pBef);
		next(PNew) = next(*pBef);
		next(*pBef) = PNew;
	}else{
		printf("Tidak Ada Data yang Dicari\n");
	}
	
}

void Del_Awal_Barang (address_B * p, infotype2 * X){
	
	address_B A;
	
	if(isEmpty_Barang(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = NmBrng(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
	
}



void Del_After_Barang (address_B * pBef, infotype * X, infotype2 * Y){
	
	address_B A,B;
	
	if(*pBef == NULL){
		printf("Tidak Ada Data yang Dicari\n");
	}else if(next(*pBef) == NULL){
		printf("Tidak Ada Data Setelah Node\n");
	}else{
		printf("Searching Berhasil\n");
		A = next(*pBef);
		B = next(A);
		next(*pBef) = B;
		next(A) = NULL;
		free(A);
	}
	
}

void DeAlokasi_Barang (address_B * p){
	
	*p = NULL;
	free(*p);
	
}



// List Keranjang

boolean isEmpty_Keranjang(address_K p){
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Keranjang (address_K *p){
	
	*p = (address_K)malloc(sizeof(List_Keranjang));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Keranjang (address_K *p , infotype harga, infotype2 nm_brg, infotype qty){
	
	if(isEmpty_Keranjang(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		HrgBrng(*p) = harga;
		NmBrng(*p) = nm_brg;
		Qty(*p) = qty;
	}
	
}
//void Isi_Node_Keranjang (address_K *p, infotype harga, infotype2 nm_brng, infotype qty){
//	if(isEmpty_Keranjang(*p)){
//		printf("Node Belum di Alokasi\n");
//	} else {
//		next(*p) = Nil;
//		HrgBrng(*p) = harga;
//		strcpy(NmBrng(*p), nm_brng); // Salin nilai dari NmBrng ke NmBrng(*p)
//		Qty(*p) = qty;
//	}
//}

void Tampil_List_Keranjang (address_K p){
	int i = 1;
	if(isEmpty_Keranjang(p)){
		printf("\t\t\t\tList Kosong, Silahkan klik lagi...                   \n");
		printf("\t\t\t\t-------------------------------------------------------\n");
	}
	else{		
		while(!isEmpty_Keranjang(p)){
			printf("\t\t\t\t%d. %s Rp.%d %d buah",i,p->NmBrng, p->HrgBrng, p->Qty);
			p = next(p);
			if(p != Nil){
				printf("\n");
			}
			i++;
		}
		printf("\n");
	}	
	
}

void Ins_Awal_Keranjang (address_K *p, address_K PNew){
	
	next(PNew) = *p;
	*p = PNew;
	
}

void Ins_Akhir_Keranjang (address_K *p, address_K PNew){
	
	address_K A;
	if(isEmpty_Keranjang(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Keranjang(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}

void InsertAfter_Keranjang (address_K * pBef, address_K PNew){
	
	if(*pBef != NULL){
		printf("Searching Berhasil dengan Alamat %i\n",*pBef);
		next(PNew) = next(*pBef);
		next(*pBef) = PNew;
	}else{
		printf("Tidak Ada Data yang Dicari\n");
	}
	
}

void Del_Awal_Keranjang (address_K * p, infotype2 * X){
	
	address_K A;
	
	if(isEmpty_Keranjang(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = NmBrng(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
	
}

void Del_After_Keranjang (address_K * pBef, infotype * X, infotype2 * Y){
	
	address_K A,B;
	
	if(*pBef == NULL){
		printf("Tidak Ada Data yang Dicari\n");
	}else if(next(*pBef) == NULL){
		printf("Tidak Ada Data Setelah Node\n");
	}else{
		printf("Searching Berhasil\n");
		A = next(*pBef);
		B = next(A);
		next(*pBef) = B;
		next(A) = NULL;
		free(A);
	}
	
}

void DeAlokasi_Keranjang (address_K * p){
	
	*p = NULL;
	free(*p);
	
}

// List Antrian

boolean isEmpty_Antrian(address_A p){
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Antrian (address_A *p){
	
	*p = (address_A)malloc(sizeof(List_Antrian));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Antrian (address_A *p , infotype2 nama){
	
	if(isEmpty_Antrian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		nama(*p) = nama;
	}
	
}

void Tampil_List_Antrian (address_A p){
	int i = 1;
	if(isEmpty_Antrian(p)){
		printf("\t\t\t\tList Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
			printf("\t\t\t\t%d. %s",i,&p->nama);
			p = next(p);
			if(p != Nil){
				printf("\n");
			}
			
		}
		printf("\n");
	}	
	
}

void Ins_Awal_Antrian (address_A *p, address_A PNew){
	
	next(PNew) = *p;
	*p = PNew;
	
}

void Ins_Akhir_Antrian (address_A *p, address_A PNew){
	
	address_A A;
	if(isEmpty_Antrian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Antrian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}

void InsertAfter_Antrian (address_A * pBef, address_A PNew){
	
	if(*pBef != NULL){
		printf("Searching Berhasil dengan Alamat %i\n",*pBef);
		next(PNew) = next(*pBef);
		next(*pBef) = PNew;
	}else{
		printf("Tidak Ada Data yang Dicari\n");
	}
	
}

void Del_Awal_Antrian (address_A * p, infotype2 * X){
	
	address_A A;
	
	if(isEmpty_Antrian(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = nama(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
	
}


void Del_After_Antrian (address_A * pBef, infotype * X, infotype2 * Y){
	
	address_A A,B;
	
	if(*pBef == NULL){
		printf("Tidak Ada Data yang Dicari\n");
	}else if(next(*pBef) == NULL){
		printf("Tidak Ada Data Setelah Node\n");
	}else{
		printf("Searching Berhasil\n");
		A = next(*pBef);
		B = next(A);
		next(*pBef) = B;
		next(A) = NULL;
		free(A);
	}
	
}

void DeAlokasi_Antrian (address_A * p){
	
	*p = NULL;
	free(*p);
	
}
