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
	int pil,pilsub1,pilsub2,nomor;
	infotype dompet=125000, nmr_ksr = NULL, Qty;
	infotype2 nama,nama_barang,riwayat;
	bool back_1 = false, back_mn = false, menu_pelanggan = false, menu_kasir = false;
	
	Barang = NULL;
	nama_barang = "Mie Goreng";
	Create_Node_Barang(&Barang);
	Isi_Node_Barang(&Barang, 5000, nama_barang);
	Ins_Akhir_Barang(&Head_Barang,Barang);
	
	Barang = NULL;
	nama_barang = "Mie Rebus";
	Create_Node_Barang(&Barang);
	Isi_Node_Barang(&Barang, 15000, nama_barang);
	Ins_Akhir_Barang(&Head_Barang,Barang);
	
	Barang = NULL;
	nama_barang = "Susu Ultra";
	Create_Node_Barang(&Barang);
	Isi_Node_Barang(&Barang, 25000, nama_barang);
	Ins_Akhir_Barang(&Head_Barang,Barang);
	
	Barang = NULL;
	nama_barang = "Tisu Basah";
	Create_Node_Barang(&Barang);
	Isi_Node_Barang(&Barang, 500, nama_barang);
	Ins_Akhir_Barang(&Head_Barang,Barang);
	
	A[0].no_kasir = 1;
	A[1].no_kasir = 2;
	A[2].no_kasir = 3;
	
	do{
		back_mn = false;
		system("cls");
		printf("    #  S E L A M A T   D A T A N G   D I   A L A M A R T   #\n");
		printf("\n\n");
		printf("	--------------------------------------------------\n");
		printf("	||    TUGAS AKHIR STRUKTUR DATA DAN ALGORITMA   ||\n");
		printf("	||             PROGRAM ANTRIAN KASIR            ||\n");
		printf("	||               1. PELANGGAN                   ||\n");
		printf("	||               2. KASIR                       ||\n");
		printf("	--------------------------------------------------\n");
		printf("		Input Pilihan:");
		scanf("%d",&pil);
		switch(pil){
			case 1:
				do{	 
					back_1 = false;
					system("cls");
					printf("--------------------------------------------------\n");
					printf("||		1. Pilih Pelanggan              ||\n");			  
					printf("||		2. Tambah Pelanggan             ||\n");
					printf("||		3. Kembali Ke Menu              ||\n");
					printf("--------------------------------------------------\n\n");
					printf("Input Pilihan:");
					scanf("%d", &pilsub1);
					switch(pilsub1){
						case 1:
							if(IsEmpty_Pelanggan(Head_Pelanggan)){
								printf("Pelanggan Kosong");
								back_1 = true;
							}else{
								printf("List Pelanggan : \n");
								Pelanggan = Head_Pelanggan;
								Tampil_List_Pelanggan(Head_Pelanggan);
								printf("\nPilih Pelanggan : ");
								scanf("%d",&nomor);
								for(int i=1;i<nomor;i++){
									Pelanggan = Pelanggan->next;
								}
							}
						break;
						case 2:
							printf("Masukkan nama Pelanggan : ");
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
							printf("--------------------------------------------------\n");
							printf("Nama : %s \t Dompet = Rp.%d \t Nomor Kasir = %d \n",&Pelanggan->Nm_pelanggan,Pelanggan->Dompet,Pelanggan->Nmr_ksr);
							printf("--------------------------------------------------\n");
							if(!IsEmpty_Keranjang(Head_Keranjang)){
								printf("99. Masuk Antrian\n");
							}
							printf("1. Tambah barang\n");
							printf("2. Lihat dompet\n");
							printf("3. Lihat keranjang\n");
							printf("4. Back\n");
							printf("--------------------------------------------------\n\n");
							printf("Input Pilihan:");
							scanf("%d",&pilsub2);
							switch(pilsub2){
								case 99:
									printf("Masukan Nomor Kasir : ");
									scanf("%d",&nomor);
									Antrian = NULL;
									
									Create_Node_Antrian(&Antrian);
									Isi_Node_Antrian(&Antrian, Pelanggan->Nm_pelanggan);
									Ins_Akhir_Antrian(&A[nomor-1].p,Antrian);
									getch();
									
								break;
								case 1 :
									printf("List Barang : \n");
									Tampil_List_Barang(Head_Barang);
									printf("Pilih Barang : ");
									scanf("%d",&nomor);
									Barang = Head_Barang;
									for(int i=1;i<nomor;i++){
										Barang = Barang->next;
									}
									printf("Masukan Jumlah Barang : ");
									scanf("%d",&Qty);
									Pelanggan->Keranjang = Head_Keranjang;
									Create_Node_Keranjang(&Keranjang);
									Isi_Node_Keranjang(&Keranjang, Barang->Harga, Barang->Nm_brg, Qty);
									Ins_Akhir_Keranjang(&Pelanggan->Keranjang,Keranjang);
									menu_pelanggan = false;
									Head_Keranjang = Pelanggan->Keranjang;
									getch();
								break;
								case 2 :
									printf("\n Isi pada dompet anda ada Rp.%d \n",Pelanggan->Dompet);
									menu_pelanggan = false;
									getch();
								break;
								case 3 :
									printf("List Keranjang : \n");
									Tampil_List_Keranjang(Head_Keranjang);
									getch();
								break;
								case 4 :
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
		        printf("--------------------------------------------------\n");
		        printf("||    Pilih kasir 1/2/3?          ||\n");
		        printf("--------------------------------------------------\n");
		        printf("Input pilihan: ");
		        scanf("%d", &nomor);
		
		        if (nomor < 1 || nomor > 3) {
		            printf("Kasir tidak ada.\n");
		            getch();
		            break; // Exit the do-while loop and go back to the main menu
	        }
	
	        nomor = nomor - 1;
	        do {
	            menu_kasir = false;
	            system("cls");
	            printf("--------------------------------------------------\n");
	            printf("Nomor Kasir : %d \n", A[nomor].no_kasir);
	            printf("--------------------------------------------------\n");
	            printf("1. Lihat Antrian \n");
	            printf("2. Proses Antrian Pertama \n");
	            printf("3. Back To Kasir\n");
	            printf("4. Back To Menu\n");
	            printf("Input Pilihan : ");
	            scanf("%d", &pil);
	            switch(pil) {
	                case 1:
	                    printf("List Antrian : \n");
	                    Tampil_List_Antrian(A[nomor].p);
	                    getch();
	                    break;
	                case 2:
	                    Del_Awal_Antrian(&A[nomor].p, &riwayat);
	                    printf("Menghapus Antrian : %s", &riwayat);
	                    getch();
	                    break;
	                case 3:
	                    menu_kasir = true;
	                    break;
	                case 4:
	                    menu_kasir = true;
	                    back_1 = true;
	                    break;
	            }
	        } while (menu_kasir != true);
	    } while (back_1 != true);
	    break;
	
				default: printf("menu yang dipilih tidak ada");
			}
		}while(back_mn != true);
}
	
	
