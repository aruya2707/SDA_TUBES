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
    infotype pilih, jumlah, menu, idx, harga, lagi;

    // meminta input nama pelanggan
    printf("Masukkan nama Pelanggan : ");
    scanf("%s", &nama);
    printf("Masukkan pilihan bawaan anda : (1.Troli/2.Keranjang)\n");
    scanf("%d", &pilih);
    InsVLastQ(&MyQueue, nama, pilih);

    system("cls");
    printf("\n");

    /**/
    idx = ReadProduct();
    /*meminta inputan user*/
    do {
        printf("\nMasukkan nomor barang yang ingin dibeli : ");
        scanf("%d", &menu);
    } while (menu < 1 || menu > idx);

    /*mengambil informasi dalam file*/
    FILE *file;
    char *lis = "list_barang.txt";
    file = fopen(lis, "r");
    do{
    for (int i = 0; i < menu; i++) {
        infochar nama;
        infotype harga, stok;
        fscanf(file, "%*d;%m[^;];%d;%d\n", &nama, &harga, &stok);
	if (i == 0) {
	    printf("Masukkan jumlah barang yang ingin dibeli : ");
	    scanf("%d", &jumlah);
	    getchar(); // membaca karakter newline yang tersisa di buffer input
	    brg = Alokasi_Barang(nama, harga, jumlah);
	} else {
	    printf("Masukkan jumlah barang yang ingin dibeli : ");
	    scanf("%d", &jumlah);
	    getchar(); // membaca karakter newline yang tersisa di buffer input
	    
	    
	    
	    newBrg = Alokasi_Barang(nama, harga, jumlah);
	    if (newBrg != Nil) {
        NextBrg(brg) = newBrg;
        brg = newBrg;
	    }
	}
        free(nama);
    }
    fclose(file);
        
    printf("\nApakah anda ingin membeli lagi? (Y/N)\n");
    scanf("%c", &lagi);
	}while (lagi == 'Y' || lagi == 'y');
    
	Kondisi_Enqueue(K);
	
}
void Transaksi (){	
}
