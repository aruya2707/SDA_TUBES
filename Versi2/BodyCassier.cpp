#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "antrian.h"
// Fungsi untuk memeriksa apakah username dan password sesuai dengan akun yang terdaftar
int cek_akun(Login_Kasir *akun, int jml_akun, char *username, char *password) {
    int i;
	for (i = 0; i < jml_akun; i++) {
        if (strcmp(akun[i].username, username) == 0 && strcmp(akun[i].password, password) == 0) {
            return i; // username dan password sesuai
        }
    }
    return -1; // username dan password tidak sesuai
}
void Login_Admin(){
	int jml_akun = 3;
	    Login_Kasir akun[jml_akun];
	
	    FILE *file;
	    file = fopen("Admin.txt", "r");
	
	    if (file == NULL) {
	        printf("File tidak dapat dibuka\n");
	        exit(1);
	    }
	
	    for (int i = 0; i < jml_akun; i++) {
	        fscanf(file, "%s %s", akun[i].username, akun[i].password);
	    }
	    fclose(file);
	
	    char username[50];
	    char password[50];
	
		system ("cls");
	    printf("Silakan masukkan username dan password\n");
	
	    printf("Username: ");
	    scanf("%s", username);
	    printf("Password: ");
	    scanf("%s", password);
	
	    int kasir = cek_akun(akun, jml_akun, username, password);
	    if (kasir != -1) {
	        printf("Log in berhasil. Selamat datang, %s.\n", akun[kasir].username);
	        system ("cls");
	        MenuAdmin();
	    } else {
	        printf("Log in gagal. Username atau password salah.\n");
	    }
}
void Login_Customer(){
		
	int jml_akun = 3;
	    Login_Kasir akun[jml_akun];
	
	    FILE *file;
	    file = fopen("Kasir.txt", "r");
	
	    if (file == NULL) {
	        printf("File tidak dapat dibuka\n");
	        exit(1);
	    }
	
	    for (int j = 0; j < jml_akun; j++) {
	        fscanf(file, "%s %s", akun[j].username, akun[j].password);
	    }
	    fclose(file);
	
	    char username[50];
	    char password[50];
	
		system ("cls");
	    printf("Silakan masukkan username dan password\n");
	
	    printf("Username: ");
	    scanf("%s", username);
	    printf("Password: ");
	    scanf("%s", password);
	
	    int kasir = cek_akun(akun, jml_akun, username, password);
	    if (kasir != -1) {
	        printf("Log in berhasil. Selamat datang, %s.\n", akun[kasir].username);
	    	
		} else {
	        printf("Log in gagal. Username atau password salah.\n");
	    }
}
void MenuCustomer(Kasir K[]) {
    Queue MyQueue;
    addressbrg brg, newBrg;
    infochar nama, namab;
    infotype pilih, jumlah, menu, idx, harga, no;
    int a, n = 0;
    int b;
    ListBrng prd;
    cstmr cst;
    char pesan;
    FILE *file, *file2;
    const char *lis = "list_barang.txt";

    // meminta input nama pelanggan
    printf("Masukkan nama Pelanggan : ");
    scanf("%s", &nama);
    printf("Masukkan pilihan bawaan anda : (1.Troli/2.Keranjang)\n");
    scanf("%d", &pilih);
    InsVLastQ(&MyQueue, nama, pilih);
	
	do 
	{
    system("cls");
    printf("\n");
//    /*mengambil informasi dalam file*/
    a = 0;
    file = fopen(lis, "r");
    printf("No\tNama Produk\t\tHarga\tJumlah\n");
		printf("-------------------------------------------------\n");
		do{
			fscanf(file,"%d;%[^;];%d;%d\n", &prd[a].no, &prd[a].NmBrng, &prd[a].HrgBrng, &prd[a].StokBrng);
			printf("%d\t%-20s\t%d\t%d\n", prd[a].no, prd[a].NmBrng, prd[a].HrgBrng, prd[a].StokBrng);
			a++;
		}
		while(!feof(file));
		printf("------------------------------------------------\n");
		printf("\n");
		fclose(file);
		
		lagi :
		printf("Pilih no produk : ");
		scanf("%d", &cst[n].kode);
		no = cst[n].kode;
			
		if (cst[n].kode == prd[no].no){
			//tampil nama dan harga produk
			printf("Nama Barang \t: %s", prd[no].NmBrng);  
			strcpy(cst[n].order, prd[no].NmBrng);
			printf("\ntHarga Barang \t: Rp. %d", prd[no].HrgBrng);  
			cst[n].harga = prd[no].HrgBrng;	
			
			//jumlah
			printf("\nJumlah \t\t: ");		
			scanf("%d", &cst[n].jumlah);
			if (cst[n].jumlah > prd[no].StokBrng){
				printf("\n\t\t\tStok tidak cukup");
				goto lagi;
			}else{
				//mengurangi produk
				prd[no].StokBrng = prd[no].StokBrng - cst[n].jumlah;
				
				// Proses penulisan pada file
				file2 = fopen(lis, "w");

                if (file2 == NULL) {
                    printf("Gagal membuka file");
                } else {
                    for (b = 0; b < a; b++) {
                        fprintf(file2, "%d;%s;%d;%d\n", prd[b].no, prd[b].NmBrng, prd[b].HrgBrng, prd[b].StokBrng);
                    }
                    fclose(file2);
                }
//				while(b<a);
//				fclose(file2);
				
			}
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
		
	}
	while (pesan == 'Y' || pesan == 'y');
	
}
void Transaksi (){	
}
