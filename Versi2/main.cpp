#include <stdio.h>
#include <stdlib.h>
//#include "cassier"
#include "antrian.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int jml_akun = 3;
    Login_Kasir akun[jml_akun];
    FILE *file;
    file = fopen("accounts.txt", "r");

    if (file == NULL) {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }

    char username[50];
    char password[50];

    // Membaca data akun dari file
	int i;
	for (i = 0; i < jml_akun; i++) {
        fscanf(file, "%s %s", akun[i].username, akun[i].password);
    }
	fclose(file);

    printf("Selamat datang di ALAMART\n");
    printf("Silakan masukkan username dan password Anda\n");

    printf("Username: "); scanf("%s", username);
	printf("Password: "); scanf("%s", password);
	

    int kasir = cek_akun(akun, jml_akun, username, password);
    if (kasir != -1) {
        printf("Log in berhasil. Selamat datang, %s.\n", akun[kasir].username);
    } else {
        printf("Log in gagal. Username atau password salah.\n");
    }

	return 0;
}