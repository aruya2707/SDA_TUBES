#include "queue.h"

datakasir Kasir[3];
DataBarang list[5];

address_P Head_Pembeli = NULL;
address_BB Head_BarangBelian = NULL;
address_B Head_Barang = NULL;
address_P Pembeli = NULL;
address_B Barang; 
address_BB BarangBelian;
address_A Antrian;
	
infotype pil,kode,jml,nokasir,harga,lagi,Nomor,i=0;
infochar nama,riwayat,Nama_Barang;

void list_barang(){
	int i;
	printf("\t\t\t\tList Barang Toko Corona\n");
	printf("Nama Barang\t\t\t\t\tStok Barang\t\t\t\tHarga\n");
	
	for(i=0;i<5;i++){
		printf("%d. %s\t\t\t\t%d\t\t\t\t\t%d\n",i+1,list[i].nama,list[i].stok,list[i].harga);
	}
}

int main(){
	Kasir[0].Nomor = 1; 
	Kasir[1].Nomor = 2;
	Kasir[2].Nomor = 3;
	
	list[0].nama = "Daging Ayam	",list[0].stok = 10,list[0].harga = 25000;
	list[1].nama = "Daging Sapi	",list[1].stok = 10,list[1].harga = 40000;
	list[2].nama = "Daging Kambing",list[2].stok = 10,list[2].harga = 30000;
	list[3].nama = "Mie Goreng	",list[3].stok = 100,list[3].harga = 3000;
	list[4].nama = "Mie Rebus	",list[4].stok = 100,list[4].harga = 3000;
	for(;;){
		system ("cls");
		printf("Daftar Antrian: \n");
		printf("Kasir 1:\n");
		Tampil_List_Antrian(Kasir[0].next);
		printf("Kasir 2:\n");
		Tampil_List_Antrian(Kasir[1].next);
		printf("Kasir 3:\n");
		Tampil_List_Antrian(Kasir[2].next);
		printf("\n");
		printf("Toko Negatif Corona : \n");
		printf(" 1. Persediaan Stok Barang \n");
		printf(" 2. Beli Barang \n");
		printf(" 3. Proses Antrian \n");
		printf(" 4. Tutup Toko \n");
		printf("Pilihan : "); 
		scanf("%d", &pil);
		system("cls");
		switch(pil)
		{
			case 1 :{
				list_barang();
				system("pause");
				break;
			}
			case 2 :{
				lagi = 1;
				printf("Isi Nama Pembeli : ");
				scanf("%s",&nama);
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
					Pembeli = Pembeli->next;	
				}
				list_barang();
				while (lagi == 1){
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					Nama_Barang = list[kode-1].nama;
					harga = list[kode-1].harga * jml;
					list[kode-1].stok = list[kode-1].stok-jml;
				if(list[kode-1].stok<0){
					printf("Maaf Barang Habis\n");
					list[kode-1].stok = 0;
				}
					Pembeli->BarangBelian = Head_BarangBelian;				
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
				}
				printf("\nPilih No. Kasir (1-3): ");
				scanf("%d",&nokasir);
				Antrian = NULL;
				Create_Node_Antrian(&Antrian);	// dengan parameter antrian, antrian = address A
				Isi_Node_Antrian(&Antrian, Pembeli->Nama_Pembeli);	// pembeli dengan subvar nama pembeli
				Ins_Akhir_Antrian(&Kasir[nokasir-1].next,Antrian);	// antrian = address A
				printf("\nAnda Sudah Masuk Antrian\n");
				system("pause");	
				break;
			}
			case 3 :{
				printf("Pilih Kasir(1-3): ");
				scanf("%d",&i);
				Dequeue_Antrian(&Kasir[i-1].next,&nama);	// menghapus nama di antrian
				printf("Nama %s telah dihapus dari antrian\n",&nama);
				system("pause");
				break;
			}
			case 4 :{
				printf("Maaf Toko sudah ditutup");
				exit(1);
				break;
			}
			default :{
				printf("Pilihan Tidak Tersedia\n");
				system("pause");
				break;
			}
		}
	}
}

