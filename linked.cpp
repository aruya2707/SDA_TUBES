#include "linked.h"

// List Pelanggan

boolean isEmpty_Pembeli(address_P p){ // check
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Pembeli (address_P *p){	// check
	
	*p = (address_P)malloc(sizeof(List_Pembeli));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Pembeli (address_P *p , address_BB *q, infochar Nama_Pembeli, infotype No_Kasir){ // check
	
	if(isEmpty_Pembeli(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		BarangBelian(*p) = *q;
		Nama_Pembeli(*p) = Nama_Pembeli;
		No_Kasir(*p) = No_Kasir;
	}
	
}

void Ins_Akhir_Pembeli (address_P *p, address_P PNew){ // check
	
	address_P A;
	if(isEmpty_Pembeli(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Pembeli(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


// List BarangBelian

boolean isEmpty_BarangBelian(address_BB p){  // check
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_BarangBelian (address_BB *p){	// check
	
	*p = (address_BB)malloc(sizeof(List_BarangBelian));
	
}

void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar nama_barang, infotype jumlah_barang){	// check
	
	if(isEmpty_BarangBelian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Harga(*p) = harga;
		Nama_Barang(*p) = nama_barang;
		Jumlah_Barang(*p) = jumlah_barang;
	}
	
}

void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew){	// check
	
	address_BB A;
	if(isEmpty_BarangBelian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_BarangBelian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


void Del_Awal_BarangBelian (address_BB * p, infochar * X){	// check
	
	address_BB A;
	
	if(isEmpty_BarangBelian(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = Nama_Barang(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
}

// List Antrian

boolean isEmpty_Antrian(address_A p){	// check
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Antrian (address_A *p){	// check
	
	*p = (address_A)malloc(sizeof(List_Antrian));	// membuat node sebesar list antrian
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Antrian (address_A *p , infochar nama){	// Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan ,Periksa keberadaan P, Nilai diisi jika P tidak NULL
	
	if(isEmpty_Antrian(*p)){
		printf("Node Belum di Alokasi\n");	
	}else{
		next(*p) = Nil;		// next yang ditunjuk p disii Nil 
		nama(*p) = nama;	// nama yang ditunjuk p diisi nama
	}
	
}

void Tampil_List_Antrian (address_A p){		// Menampilkan seluruh isi Linked List, p parameter passing by value
	int i = 1;
	
	if(isEmpty_Antrian(p)){	
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
			printf("%d. %s",i,&p->nama);	// print yang ada di antrian
			p = next(p);	// p diisi next p
			if(p != Nil){	// jika p tidak sama dengan nil 
				printf("\n");
			}
		i++; // lakukan ini sebanyak i	
		}
		printf("\n");
	}	
	
}

void Ins_Akhir_Antrian (address_A *p, address_A PNew){	//  menambahkan elemen list (PNew) di akhir LinkedList 
	
	address_A A;
	if(isEmpty_Antrian(*p)){
		*p = PNew;	// pointer diisi pNew
	}else{	
		A = *p;
		while(!isEmpty_Antrian(next(A))){ // memeriksa next A apakah kosong 
			A = next(A);	// A diisi next A
		}
		next(A) = PNew;
	}
}


void Del_Awal_Antrian (address_A * p, infochar * X){	
	
	address_A A;
	
	if(isEmpty_Antrian(*p)){	// memeriksa apakah antrian kosong
		printf("Antrian Kosong\n");	// jika kosong print 
	}else{
		A = *p;	// Antrian diisi address p
		*X = nama(A);	// mengalokasi dengan nama pada Antrian
		*p = next(*p);	// pointer diisi next p
		A = NULL;	// A diisi NIL
		free(A);	// hampus A dari antrian
	}
	
}

