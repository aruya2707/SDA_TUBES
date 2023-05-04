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

void MenuCustomer(){
	Queue MyQueue;
	
}

void MenuAdmin(){
	ListBarang L[100];
	int n = 0;
	char choice;
	
	do{
		printf("Menu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Hapus Barang\n");
        printf("3. Tampilkan List Barang\n");
        printf("4. Keluar\n");
        
        printf("Pilihan Anda: ");
        scanf(" %c", &choice);
        
        switch(choice){
    		  case '1':
            	
                break;
            case '2':

                break;
            case '3':
             
                break;
            case '4':
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
	   printf("\n");        	
		} while(choice != '4');

	}

