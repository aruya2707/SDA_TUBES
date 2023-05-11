//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <malloc.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <ctype.h>
//#include <string.h>
//#include "queue.h"
//
//char *filename = "list_barang.txt";
//// Fungsi untuk memeriksa apakah username dan password sesuai dengan akun yang terdaftar
//int cek_akun(Login_Kasir *akun, int jml_akun, char *username, char *password) {
//    int i;
//	for (i = 0; i < jml_akun; i++) {
//        if (strcmp(akun[i].username, username) == 0 && strcmp(akun[i].password, password) == 0) {
//            return i; // username dan password sesuai
//        }
//    }
//    return -1; // username dan password tidak sesuai
//}
//
//void Login_Admin(){
//	int jml_akun = 3;
//	    Login_Kasir akun[jml_akun];
//	
//	    FILE *file;
//	    file = fopen("Admin.txt", "r");
//	
//	    if (file == NULL) {
//	        printf("File tidak dapat dibuka\n");
//	        exit(1);
//	    }
//	
//	    for (int i = 0; i < jml_akun; i++) {
//	        fscanf(file, "%s %s", akun[i].username, akun[i].password);
//	    }
//	    fclose(file);
//	
//	    char username[50];
//	    char password[50];
//	
//		system ("cls");
//	    printf("Silakan masukkan username dan password\n");
//	
//	    printf("Username: ");
//	    scanf("%s", username);
//	    printf("Password: ");
//	    scanf("%s", password);
//	
//	    int kasir = cek_akun(akun, jml_akun, username, password);
//	    if (kasir != -1) {
//	        printf("Log in berhasil. Selamat datang, %s.\n", akun[kasir].username);
//	        system ("cls");
//	        MenuAdmin();
//	    } else {
//	        printf("Log in gagal. Username atau password salah.\n");
//	    }
//}
//void Transaksi (){	
//}
//
//int MenuAdmin() {
//
//    int n = 0, infal, pilih;
//    do {
//        menu:
//        infal = 0;
//        n = ReadProduct(); 
//        printf("\nPilihan : ");
//        printf("\n1.Tambah Produk\n2.Hapus Produk\n0.Keluar");
//        printf("\nPilih : ");
//        scanf("%d", &pilih); 
//        switch (pilih) {
//            case 1 : { 
//                AddBarang(n);
//                goto menu;
//                break;
//            }
//            case 2 : { 
//                DeleteProduct(n);
//                goto menu;
//                break;
//            }
////            case 3 : {
////            	goto menu;
////				break;
////			}
//        }
//    } while (pilih != 0);
//
//    return 0;
//}
//
//int ReadProduct(){
//	FILE *file;
//	int a=0;
//	int ch;
//	char *lis = "list_barang.txt";
//	ListBrng brg;
//	
////	file = fopen("list_barang.txt", "r");
//	// 
//	if ( (file = fopen(lis,"r"))== NULL )
//	{
//		printf("File tidak dapat dibuka!\r\n");
//	}
//	
///*Menampilkan List barang*/
//	printf("---------------------------------------------\n");
//	printf("No\tNama Produk\t\tHarga\tStok\n");
//	printf("---------------------------------------------\n");
//	while (fscanf(file,"%d;%[^;];%d;%d\n", &brg[a].no, &brg[a].NmBrng, &brg[a].HrgBrng, &brg[a].StokBrng) != EOF)
//	{
//		printf("%d\t%-20s\t%d\t%d\n", brg[a].no, brg[a].NmBrng, brg[a].HrgBrng, brg[a].StokBrng);
//		a++;
//	}	
//	fclose(file);
//	
//	printf("\njumlah jenis produk : %d",a);	
//	return a;
//}
//
//void AddBarang(int b){
//	FILE *file;
//	char *dir = "list_barang.txt";
//	ListBrng brg;
//
//	if ( (file = fopen(dir,"a")) == NULL )
//	{
//		printf("File tidak dapat dibuka!\r\n");
//		exit(1);
//	}
//		
//	system("cls");
//	printf("\n");
//		
//	brg[b].no = b;
//	printf("Nama Produk\t: "); 
//	fflush(stdin);
//	scanf("%[^\n]", &brg[b].NmBrng);
//	printf("Harga Produk\t: "); 
//	scanf("%d", &brg[b].HrgBrng);
//	printf("Stok Produk\t: " ); 
//	scanf("%d", &brg[b].StokBrng);
//		
//	fprintf(file, "\n%d;%s;%d;%d", brg[b].no, brg[b].NmBrng, brg[b].HrgBrng, brg[b].StokBrng);
//	fclose(file);
//}
//void DeleteProduct(int b){
//	FILE *file, *fl;
//	char *dir = "list_barang.txt";
//	ListBrng brg;
//	int id, x=0, y=0, z;
//	char confirm, confirm2;
//	
//	ulang :
//	system("cls");
//	printf("\n");
//	printf("Masukkan nomor produk yang akan dihapus : "); scanf("%d",&id);
//	if (id < 0 || id > b){
//		goto ulang;
//	}
//	else{
//		fl = fopen(dir,"r");
//		do{
//			fscanf(fl,"%d;%[^;];%d;%d\n", &brg[y].no, &brg[y].NmBrng, &brg[y].HrgBrng, &brg[y].StokBrng);
//			y++;
//		}
//		while(!feof(fl));
//		fclose(fl);
//		
//		printf("-----------------------------------------\n");
//		printf("No\tNama Produk\t\tHarga\tStok\n");
//		printf("%d\t%-20s\t%d\t%d\n", brg[id].no, brg[id].NmBrng, brg[id].HrgBrng, brg[id].StokBrng);
//		printf("-----------------------------------------\n");
//		printf("Anda yakin ingin menghapus produk (%d. %s) ? y/t ",brg[id].no, brg[id].NmBrng);
//		fflush(stdin);
//		scanf("%c",&confirm);
//		confirm2 = toupper(confirm);
//				
//		if(confirm2 == 'Y'){
//			for (z=id; z<b; z++){
//				brg[z].NmBrng, brg[z+1].NmBrng;
//				brg[z].HrgBrng = brg[z+1].HrgBrng;
//				brg[z].StokBrng = brg[z+1].StokBrng;
//			}
//					
//			b--;
//			file = fopen(dir,"w");
//			do{
//				fprintf(file, "%d;%s;%d;%d", brg[x].no, brg[x].NmBrng, brg[x].HrgBrng, brg[x].StokBrng);
//				x++;
//				if(x<b){
//					fprintf(file,"\n");
//				}
//			}	
//			while(x<b);
//			fclose(file);
//		}
//	}
//}
//void UpdateBrng{
//
//}
