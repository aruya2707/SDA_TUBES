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

typedef struct customer
{
	char nama[20];
	int kode;
	char order[20];
	int harga;
	int jumlah;
	int TotalHarga;
}cstmr[10];

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

struct customer input(struct customer cst[10], int *c);

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
		
		menu :
		// menampilkan menu
		printf("\n=== MENU ===\n");
		printf("1. Beli barang\n");
		printf("2. Lihat keranjang/troli\n");
		printf("3. Masuk kasir\n");
		printf("Pilih: ");
		scanf("%d", &pilih);

		switch (pilih){
			case 1: {
				cstmr data;
				int x, w;
				system ("cls");
					
				input(data, &x);
				system("cls");
				goto menu;
				break;
			}
			case 2: {
				printf("\nList Keranjang : \n");
				Tampil_List_Keranjang(Head_Keranjang);
				getch();
				break;
			}
			case 3: {
				printf("Silahkan pilih no kasir");
				break;
			}
			default: {
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

struct customer input(struct customer cst[10], int *c)
{
	FILE *fl, *fa;
	char pesan;
	int n, a, no, j;
	int x, b, q;
	ListBrng prd;
	
	char *dir = "list_barang.txt";
	
	no = 0;
	n = 0;
	
	do
	{	
		ulang :
		a = 0;
		system ("cls");
		
		printf("\n");
		printf("\t\t=================================================\n");
		
		//Menampilkan produk
		fl = fopen(dir,"r");
		printf("\t\tNo\tNama Produk\t\tHarga\tJumlah\n");
		printf("\t\t-------------------------------------------------\n");
		do{
			fscanf(fl,"%d;%[^;];%d;%d\n", &prd[a].no, &prd[a].NmBrng, &prd[a].HrgBrng, &prd[a].StokBrng);
			printf("\t\t%d\t%-20s\t%d\t%d\n", prd[a].no, prd[a].NmBrng, prd[a].HrgBrng, prd[a].StokBrng);
			a++;
		}
		while(!feof(fl));
		printf("\t\t-------------------------------------------------\n");
		printf("\t\t99\tKembali\n");
		printf("\t\t=================================================\n");
		printf("\n");
		fclose(fl);
	
		lagi :
		//kode 
		printf("\t\t\tPilihan \t: "); 
		scanf("%d", &cst[n].kode);
		no = cst[n].kode;
		
		if (cst[n].kode == prd[no].no){
			//tampil nama dan harga produk
			printf("\t\t\tNama Barang \t: %s", prd[no].NmBrng);  //jenis kue
			strcpy(cst[n].order, prd[no].NmBrng);
			printf("\n\t\t\tHarga Barang \t: Rp. %d", prd[no].HrgBrng);  //harga kue
			cst[n].harga = prd[no].HrgBrng;	
			
			//jumlah
			printf("\n\t\t\tJumlah \t\t: ");		//jumlah toples
			scanf("%d", &cst[n].jumlah);
			
			if (cst[n].jumlah > prd[no].StokBrng){
				printf("\n\t\t\tStok tidak cukup");
				goto lagi;
			}else{
				//mengurangi produk
				prd[no].StokBrng = prd[no].StokBrng - cst[n].jumlah;
				b = 0;
				fa = fopen(dir,"w");
				do{
					fprintf(fa, "%d;%s;%d;%d", prd[b].no, prd[b].NmBrng, prd[b].HrgBrng, prd[b].StokBrng);
					b++;
					if(b<a){
						fprintf(fa,"\n");
					}
				}
				while(b<a);
				fclose(fa);
				
			}
			
			//Total Harga
			cst[n].TotalHarga = cst[n].harga * cst[n].jumlah; 
			printf("\t\t\tTotal Harga \t: Rp. %d", cst[n].TotalHarga);
			printf("\n");
			printf("\t\t=================================================\n");
			
			//pesan lagi
			printf("\n");
			printf("\t\t\tPesan lagi [Y/T]? ");
			fflush(stdin);
			scanf("%c", &pesan);
			printf("\t\t=================================================\n");
	
			n++;	
		}
		else if (cst[n].kode == 99)
			n = 99;
		else 
			goto ulang; 
	} 
	while (pesan == 'Y' || pesan == 'y');
	
	*c = n; 
	return cst[n];
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
		printf("Anda belum mengambil apapun!\n");
	}
	else{		
		while(!isEmpty_Keranjang(p)){
			printf("Jumlah barang anda %d, anda menggunakan Keranjang!");
			p = next(p);
			if(p != Nil){
				printf("\n");
			}
			
		}
		printf("\n");
	}	
	
}

boolean isEmpty_Keranjang(address_K p){
    if(p == NULL){
        return true;
    } else {
        return false;
    }
}

void Tampil_List_Keranjang(address_K p){
    if(isEmpty_Keranjang(p)){
        printf("Keranjang kosong\n");
    } else {
        int i = 1;
        while(p != NULL){
            printf("%d. %s Rp.%d %d buah\n", i, p->Nm_brg, p->Harga, p->Qty);
            p = next(p);
            i++;
        }
    }
}

boolean IsUsingKeranjang(address_P p){
    return !isEmpty_Keranjang(Keranjang(p));
}
