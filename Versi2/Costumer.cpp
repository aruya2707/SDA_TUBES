#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define Nil NULL

#define nama(P) (P)->nama
#define Keranjang(P) (P)->Keranjang
#define Dompet(P) (P)->Dompet
#define Nm_pelanggan(P) (P)->Nm_pelanggan
#define Nmr_ksr(P) (P)->Nmr_ksr
#define Harga(P) (P)->Harga
#define Nm_brg(P) (P)->Nm_brg
#define Qty(P) (P)->Qty
#define next(P) (P)->next

typedef int infotype;
typedef char *infotype2;
typedef struct List_Keranjang *address_K;
typedef struct List_Pelanggan *address_P;
typedef struct ListBarang *address_B;
typedef struct List_Keranjang {
	infotype2 Nm_brg;
	infotype Harga;
	infotype Qty;
	address_K next;
} List_Keranjang;

typedef struct List_Pelanggan {
	address_K Keranjang;
	infotype2 Nm_pelanggan;
	infotype Dompet;
	infotype Nmr_ksr;
	address_P next;
} List_Pelanggan;

typedef struct ListBarang{
	char NmBrng[20];	
	infotype StokBrng, HrgBrng, no;
	address_B next;
}ListBrng[100];

typedef address_P Queue_P;
typedef address_B Queue_B;
typedef address_K Queue_K;
//typedef address_A Queue_A;
typedef bool boolean;

void Ins_Akhir_Pelanggan (address_P *p, address_P PNew);

void Isi_Node_Pelanggan (address_P *p , address_K *k, infotype dompet, infotype2 nm_pelanggan, infotype nmr_ksr);

void Create_Node_Keranjang (address_K *p);

void Create_Node_Pelanggan (address_P *p);

void Enqueue_Pelanggan(Queue_P *Q, Queue_K *K, infotype X, infotype2 Y, infotype Z);

boolean isEmpty_Pelanggan(address_P p);

int readProduct();

void Isi_Node_Keranjang (address_K *p , infotype harga, infotype2 nm_brg, infotype qty);

void Ins_Akhir_Keranjang (address_K *p, address_K PNew);

boolean isEmpty_Keranjang(address_K p);

void Tampil_List_Keranjang (address_K p);

int main() {
	infotype pilih, Qty, nomor, Dompet, Nmr_ksr;
	infotype2 nama;
	// inisialisasi Head_Pelanggan dan Head_Keranjang
	address_P Head_Pelanggan = NULL;
	address_K Head_Keranjang = NULL;
	address_P Pelanggan = NULL;
	address_K Keranjang;
	address_B Barang;
	address_B Head_Barang = NULL;
	bool menu_pelanggan = false;

	// meminta input nama pelanggan
	printf("Masukkan nama Pelanggan : ");
	scanf("%s", &nama);
	// membuat node pelanggan baru dan menambahkannya ke dalam queue
	Enqueue_Pelanggan(&Head_Pelanggan, &Head_Keranjang, Dompet, nama, Nmr_ksr);
	// mendapatkan pointer ke node pelanggan terakhir dalam queue
	Pelanggan = Head_Pelanggan;
	while (Pelanggan->next != NULL) {
		Pelanggan = Pelanggan->next;
	}
	do {
		// menampilkan menu
		printf("\n=== MENU ===\n");
		printf("1. Beli barang\n");
		printf("2. Lihat keranjang/troli\n");
		printf("3. Masuk kasir\n");
		printf("Pilih: ");
		scanf("%d", &pilih);

		switch (pilih){
			case 1: {
				readProduct();
				printf("\nPilih Barang : ");
				scanf("%d", &nomor);
				// mencari node barang yang sesuai dengan nomor yang diinputkan
				Barang = Head_Barang;
				for (int i = 1; i < nomor; i++) {
					Barang = Barang->next;
				}
				printf("Masukan Jumlah Barang : ");
				scanf("%d", &Qty);
				
				Pelanggan->Keranjang = Head_Keranjang;
				Create_Node_Keranjang(&Keranjang);
				Isi_Node_Keranjang(&Keranjang, Barang->HrgBrng, Barang->NmBrng, Qty);
				Ins_Akhir_Keranjang(&Pelanggan->Keranjang, Keranjang);
				
				menu_pelanggan = false;
				Head_Keranjang = Pelanggan->Keranjang;
				break;
			}
			case 2: {
					printf("List Keranjang : \n");
					Tampil_List_Keranjang(Head_Keranjang);
					getch();
				break;
			}default: {
					printf("Pilihan tidak ada!\n");
				break;
			}
		}
	}while (pilih = 0);
}

void Enqueue_Pelanggan(Queue_P *Q, Queue_K *K, infotype X, infotype2 Y, infotype Z){
	
	address_P a = NULL;
	address_K b = NULL;
	
	Create_Node_Pelanggan(&a);
	Create_Node_Keranjang(&b);
	Isi_Node_Pelanggan(&a, &b, X, Y, Z);
	Ins_Akhir_Pelanggan(&(*Q),a);
	
}

//pemilihan barang ditapilkan di modul readproduct yang sama dg nampilin barang di admin
int readProduct(){
	FILE *file;
	int a=0;
	int ch;
	char *lis = "list_barang.txt";
	ListBrng brg;
	
//	file = fopen("list_barang.txt", "r");
	// 
	if ( (file = fopen(lis,"r"))== NULL )
	{
		printf("File tidak dapat dibuka!\r\n");
	}
	
/*Menampilkan List barang*/
	printf("---------------------------------------------\n");
	printf("No\tNama Produk\t\tHarga\tStok\n");
	printf("---------------------------------------------\n");
	while (fscanf(file,"%d;%[^;];%d;%d\n", &brg[a].no, &brg[a].NmBrng, &brg[a].HrgBrng, &brg[a].StokBrng) != EOF)
	{
		printf("%d\t%-20s\t%d\t%d\n", brg[a].no, brg[a].NmBrng, brg[a].HrgBrng, brg[a].StokBrng);
		a++;
	}	
	fclose(file);
	
	printf("\njumlah jenis produk : %d",a);	
	return a;
}

void Create_Node_Pelanggan (address_P *p){	
	*p = (address_P)malloc(sizeof(List_Pelanggan));	
}

void Create_Node_Keranjang (address_K *p){	
	*p = (address_K)malloc(sizeof(List_Keranjang));
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

boolean isEmpty_Pelanggan(address_P p){
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

//void Isi_Node_Keranjang (address_K *p , infotype harga, infotype2 nm_brg, infotype qty){
//	
//	if(isEmpty_Keranjang(*p)){
//		printf("Node Belum di Alokasi\n");
//	}else{
//		next(*p) = Nil;
//		Harga(*p) = harga;
//		Nm_brg(*p) = nm_brg;
//		Qty(*p) = qty;
//	}
//	
//}

void Isi_Node_Keranjang (address_K *p , infotype harga, infotype2 nm_brg, infotype qty) {
    *p = (address_K) malloc (sizeof(List_Keranjang));
    if (*p != Nil) {
        strcpy((*p)->Nm_brg, nm_brg);
        (*p)->Harga = harga;
        (*p)->Qty = qty;

        FILE *fp;
        fp = fopen("pesanan.txt", "a");
        fprintf(fp, "%s\t%d\t%d\n", nm_brg, harga, qty);
        fclose(fp);
    }
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

boolean isEmpty_Keranjang(address_K p){
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Tampil_List_Keranjang (address_K p){
	int i = 1;
	if(isEmpty_Keranjang(p)){
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Keranjang(p)){
			printf("%d. %s Rp.%d %d buah",i,&p->Nm_brg, p->Harga, p->Qty);
			p = next(p);
			if(p != Nil){
				printf("\n");
			}
			
		}
		printf("\n");
	}	
	
}

//void Tampil_List_Keranjang (address_K p){
//	int i = 1;
//	while (p != NULL) {
//		printf("| %-4d | %-13s | %-5d | %-7d |\n", i, p->Nm_brg, p->Harga, p->Qty);
//		p = p->next;
//		i++;
//	}
//	printf("\n");
//}
