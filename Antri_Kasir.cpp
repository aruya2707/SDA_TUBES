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


int ReadProduct(){
	FILE *file;
	int a=0;
	int ch;
	const char *lis = "list_barang.txt";
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
	
	printf("\njumlah jenis produk : %d \n",a);	
	return a;
}


int MenuPembeli(){
	int a, n = 0;
	FILE *fl, *fa;
	ListBrng prd;
	Kasir[0].Nomor = 1; 
	Kasir[1].Nomor = 2;
	Kasir[2].Nomor = 3;
	
	char *dir = "list_barang.txt";
	a = 0;
		system ("cls");
		
		printf("\n");
		printf("=================================================\n");
		
		//Menampilkan produk
		fl = fopen(dir,"r");
		printf("No\tNama Produk\t\tHarga\tJumlah\n");
		printf("-------------------------------------------------\n");
		do{
			fscanf(fl,"%d;%[^;];%d;%d\n", &prd[a].no, &prd[a].NmBrng, &prd[a].HrgBrng, &prd[a].StokBrng);
			printf("%d\t%-20s\t%d\t%d\n", prd[a].no, prd[a].NmBrng, prd[a].HrgBrng, prd[a].StokBrng);
			a++;
		}
		while(!feof(fl));
		printf("-------------------------------------------------\n");
		printf("99\tKembali\n");
		printf("=================================================\n");
		printf("\n");
		fclose(fl);

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
		printf("ALA Mart : \n");
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
				ReadProduct();
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
				ReadProduct();
				while (lagi == 1){
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					Nama_Barang = prd[n].NmBrng; //list[kode-1].nama;
					harga = prd[n].HrgBrng * jml; //list[kode-1].harga * jml;
					prd[n].StokBrng =  prd[n].StokBrng - jml; //proses pengurangan barang
					
					// menulis ulang hasil pengurangan barang diatas
					FILE *file;
					file = fopen("list_barang.txt", "w");
					if (file == NULL) {
					    printf("Error opening file!\n");
					    exit(1);
					}
					
					for (int i = 0; i < a; i++) {
					    fprintf(file, "%d;%s;%d;%d\n", prd[i].no, prd[i].NmBrng, prd[i].HrgBrng, prd[i].StokBrng);
					}	
				fclose(file);

				if(prd[n].StokBrng<0 /*list[kode-1].stok<0*/){
					printf("Maaf Barang Habis\n");
					prd[n].StokBrng=0; //list[kode-1].stok = 0;
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

