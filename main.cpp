#include"linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"queue.h"

datakasir A[5];

main(){
	address_P Head_Pelanggan = NULL;
	address_K Head_Keranjang = NULL;
	address_B Head_Barang = NULL;
	address_P Pelanggan = NULL;
	address_B Barang;
	address_K Keranjang;
	address_A Antrian;
	int pil,pilsub1,pilsub2,nomor, lagi,kode,jml,nokasir,harga,Nomor,i=0, k;
	infotype dompet=125000, nmr_ksr = NULL, Qty;
	infotype2 nama,Nama_Barang,riwayat;
	bool back_1 = false, back_mn = false, menu_pelanggan = false, menu_kasir = false, menu_admin = false;
	int a, n=0;
	ListBrng prd;
	FILE *file, *fl, *fa;
	
	A[0].no_kasir = 1;
	A[1].no_kasir = 2;
	A[2].no_kasir = 3;
	
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
	
	do{
		tampilan();
		back_mn = false;
		system("cls");
		printf("##================================[S E L A M A T   D A T A N G   D I   A L A M A R T]=================================##");
		printf("\n\n");
		printf("\t\t\t\t[MENU UTAMA]                                           \n");
		printf("\t\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t\t||                                                    ||\n");		
		printf("\t\t\t\t||             ---PROGRAM ANTRIAN KASIR---            ||\n");
		printf("\t\t\t\t||                                                    ||\n");
		printf("\t\t\t\t||                  1. MENU PELANGGAN                 ||\n");
		printf("\t\t\t\t||                  2. MENU KASIR                     ||\n");
		printf("\t\t\t\t||                  3. MENU GUDANG                    ||\n");
		printf("\t\t\t\t||                                                    ||\n");	
		printf("\t\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t\tInput Pilihan:");
		scanf("%d",&pil);
		switch(pil){
			case 1:
				do{	 
					back_1 = false;
					system("cls");
					printf("\t\t\t\t[MENU PELANGGAN]                                       \n");
					printf("\t\t\t\t-------------------------------------------------------\n");
					printf("\t\t\t\t||                                                    ||\n");
					printf("\t\t\t\t||                 1. Pilih Pelanggan                 ||\n");
					printf("\t\t\t\t||                 2. Tambah Pelanggan                ||\n");
					printf("\t\t\t\t||                 3. Menu Utama                      ||\n");					
					printf("\t\t\t\t||                                                    ||\n");	
					printf("\t\t\t\t-------------------------------------------------------\n");
					printf("\t\t\t\tInput Pilihan:");
					scanf("%d", &pilsub1);
					switch(pilsub1){
						case 1:
							if(IsEmpty_Pelanggan(Head_Pelanggan)){
								printf("\t\t\t\tPelanggan Kosong\n\t\t\t\tTambahkan pelanggan terlebih dahulu\n");
								system("pause");
								back_1 = true;
							}else{
								printf("\t\t\t\tList Pelanggan : \n");
								Pelanggan = Head_Pelanggan;
								Tampil_List_Pelanggan(Head_Pelanggan);
								printf("\n\t\t\t\tLihat Pelanggan : ");
								scanf("%d",&nomor);
								for(int i=1;i<nomor;i++){
									Pelanggan = Pelanggan->next;
								}
							}
						break;
						case 2:
							printf("\t\t\t\tMasukkan nama Pelanggan : ");
							scanf("%s",&nama);
							Enqueue_Pelanggan(&Head_Pelanggan,&Head_Keranjang,dompet,nama,nmr_ksr);
							Pelanggan = Head_Pelanggan;
							while(Pelanggan->next != NULL){
								Pelanggan = Pelanggan->next;	
							}
						break;
						case 3:
							back_1 = true;
						break;
						default:
						break;
					}
					if((pilsub1 == 1 || pilsub1 == 2 ) && ( back_1 != true )){
						do{
							menu_pelanggan = false;
							system("cls");
							printf("\t\t\t\t[TAMBAH PELANGGAN]                                     \n");
							printf("\t\t\t\t-------------------------------------------------------\n");
							printf("\t\t\t\t No Kasir : %d                                         \n",Pelanggan->Nmr_ksr);
							printf("\t\t\t\t Nama     : %s                                         \n",&Pelanggan->Nm_pelanggan);
							printf("\t\t\t\t-------------------------------------------------------\n");
							if(!IsEmpty_Keranjang(Head_Keranjang)){
								printf("\t\t\t\t|| 99. Masuk Antrian                                 ||\n");
							}
							printf("\t\t\t\t|| 1. Tambah Barang                                  ||\n");				
							printf("\t\t\t\t|| 2. Lihat Keranjang                                ||\n");	
							printf("\t\t\t\t|| 3. Kembali                                        ||\n");
							printf("\t\t\t\t-------------------------------------------------------\n");
							printf("\t\t\t\tInput Pilihan:");
							scanf("%d",&pilsub2);
							switch(pilsub2){
								case 99:
									printf("\t\t\t\tMasukan Nomor Kasir : ");
									scanf("%d",&nomor);
									Pelanggan->Nmr_ksr = nomor;
									Antrian = NULL;
									
									Create_Node_Antrian(&Antrian);
									Isi_Node_Antrian(&Antrian, Pelanggan->Nm_pelanggan);
									Ins_Akhir_Antrian(&A[nomor-1].p,Antrian);
									printf ("\n\t\t\t\tHoree!! Anda sudah masuk antrian. (klik untuk kembali)");
									getch();
									menu_pelanggan = true;
									
								break;
								case 1:
								    n = 0;
								    lagi = 1;
								    system("cls");
								    printf("\t\t\t\t[TAMBAH PELANGGAN]                                     \n");
									printf("\t\t\t\t-------------------------------------------------------\n");
									printf("\t\t\t\t No Kasir : %d                                         \n",Pelanggan->Nmr_ksr);
									printf("\t\t\t\t Nama     : %s                                         \n",&Pelanggan->Nm_pelanggan);
									printf("\t\t\t\t-------------------------------------------------------\n");
								    ReadProduct();  // Membaca data barang dari file ke dalam array prd
								    printf("\n\t\t\t\t-------------------------------------------------------\n");
								    while (lagi == 1) {
								        printf("\n\t\t\t\tPilih Kode Barang: ");
								        scanf("%d", &kode);
								        // Cari indeks yang sesuai dengan nomor barang yang dipilih
										for (n = 0; n < a; n++) {
										    if (prd[n].no == kode) {
										        break;
										    }
										}
								        printf("\t\t\t\tMasukan Jumlah Barang: ");
								        scanf("%d", &jml);
								        Nama_Barang = prd[n].NmBrng;
								        harga = prd[n].HrgBrng * jml;
								        prd[n].StokBrng = prd[n].StokBrng - jml; //proses pengurangan barang
								
								        // Menulis ulang semua data barang ke file
								        FILE *file;
								        file = fopen("list_barang.txt", "w");
								        if (file == NULL) {
								            printf("\t\t\t\tGagal membuka file\n");
								            exit(1);
								        }
								        for (int x = 0; x < a; x++) {
								            fprintf(file, "\t\t\t\t%d;%s;%d;%d\n", prd[x].no, prd[x].NmBrng, prd[x].HrgBrng, prd[x].StokBrng);
								        }
								        fclose(file);
								
								        if (prd[n].StokBrng < 0) {
								            printf("\t\t\t\tMaaf Barang Habis\n");
								            prd[n].StokBrng = 0;
								        }
								        Pelanggan->Keranjang = Head_Keranjang;
								        Head_Keranjang = Pelanggan->Keranjang;
								        Enqueue_Keranjang(&Head_Keranjang, harga, Nama_Barang, jml);
								        printf("\n\t\t\t\tBelanja Lagi? [1.Ya, 2.Tidak] \n\t\t\t\tInput Pilihan: ");
								        scanf("%d", &lagi);
								    }
								    Pelanggan->Keranjang = Head_Keranjang;
								    Create_Node_Keranjang(&Keranjang);
								    Isi_Node_Keranjang(&Keranjang, Barang->HrgBrng, Barang->NmBrng, Qty);
								    Ins_Akhir_Keranjang(&Pelanggan->Keranjang, Keranjang);
								    menu_pelanggan = false;
								    Head_Keranjang = Pelanggan->Keranjang;
								    printf("\n\t\t\t\t||Asik Barang belanjaan anda sudah kami masukan keranjang||\n\t\t\t\t!!!Klik lagi untuk kembali ke menu sebelumnya!!!");
								    getch();

								break;
								case 2 :	
									Tampil_List_Keranjang(Head_Keranjang);
									getch();
								break;
								case 3 :
									menu_pelanggan = true;
								break;
							}
						}while(menu_pelanggan != true);
					}	
				}while(back_1 != true);
			break;
				
			case 2:
	   		 do {
		        back_1 = false;
		        system("cls");
		        //menampilkan antrian 
				for(k==0 ; k<3; k++){
		        	printf("\t\t\t\tList Antrian : \n");
	        	    Tampil_List_Antrian(A[k].p);
	        	  //  getch();    
				}
		       	printf("\t\t\t\t[MENU KASIR]                                           \n");
				printf("\t\t\t\t-------------------------------------------------------\n");
				printf("\t\t\t\t||                                                    ||\n");
				printf("\t\t\t\t||                 Pilih Kasir 1/2/3                  ||\n");					
				printf("\t\t\t\t||                                                    ||\n");	
				printf("\t\t\t\t-------------------------------------------------------\n");
		        printf("\t\t\t\tInput pilihan: ");
		        scanf("%d", &nomor);
		
		        if (nomor < 1 || nomor > 3) {
		            printf("\t\t\t\tKasir tidak ada. (Klik untuk memilih ulang)\n");
		            getch();
		            break; // Exit the do-while loop and go back to the main menu
	        }
	
	        nomor = nomor - 1;
	        do {
	            menu_kasir = false;
	            system("cls");
				printf("\t\t\t\t[MENU KASIR]                                           \n");
				printf("\t\t\t\t-------------------------------------------------------\n");
				printf("\t\t\t\t No Kasir : %d                                         \n",A[nomor].no_kasir);
				printf("\t\t\t\t-------------------------------------------------------\n");	            
				printf("\t\t\t\t|| 1. Proses Antrian Pertama                         ||\n");					
				printf("\t\t\t\t|| 2. Kembali ke Menu Kasir                          ||\n");	
				printf("\t\t\t\t|| 3. Kembali ke Menu Utama                          ||\n");
				printf("\t\t\t\t-------------------------------------------------------\n");

	            printf("\t\t\t\tInput Pilihan : ");
	            scanf("%d", &pil);
	            switch(pil) {
	                case 1:
	                    Del_Awal_Antrian(&A[nomor].p, &riwayat);
	                    printf("\t\t\t\tMenghapus Antrian : %s", &riwayat);
	                    printf("\n\t\t\t\tAntrian berhasil diproses. (klik untuk pilih antrian berikutnya)");
	                    getch();
	                    break;
	                case 2:
	                    menu_kasir = true;
	                    break;
	                case 3:
	                    menu_kasir = true;
	                    back_1 = true;
	                    break;
	            }
	        } while (menu_kasir != true);
	    } while (back_1 != true);
	    break;
	    
		case 3:
			Login_Admin();	//untuk update barang-barang
			break;
		}
			
		}while(back_mn != true);
}
	
	
