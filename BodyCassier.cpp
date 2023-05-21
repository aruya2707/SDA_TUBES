#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include "queue.h"

char *filename = "list_barang.txt";
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
	        printf("\t\t\t\tFile tidak dapat dibuka\n");
	        exit(1);
	    }
	
	    for (int i = 0; i < jml_akun; i++) {
	        fscanf(file, "%s %s", akun[i].username, akun[i].password);
	    }
	    fclose(file);
	
	    char username[50];
	    char password[50];
	
		system ("cls");
		printf("\t\t\t\t[MENU GUDANG]                                          \n");
		printf("\t\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t\t||Silahkan Masukan Username dan Password Admin Gudang||\n");
		printf("\t\t\t\t-------------------------------------------------------\n");	            
	    printf("\t\t\t\tUsername: ");
	    scanf("%s", username);
	    printf("\t\t\t\tPassword: ");
	    scanf("%s", password);
		printf("\t\t\t\t-------------------------------------------------------\n");
		
	    int kasir = cek_akun(akun, jml_akun, username, password);
	    if (kasir != -1) {
	        printf("\t\t\t\tLog in berhasil. Selamat datang, %s.\n", akun[kasir].username);
	        system ("cls");
	        MenuAdmin();
	    } else {
	        printf("\t\t\t\tLog in gagal. Username atau password salah. (klik untuk login ulang)\n");
	    }
}

void Transaksi (){	
}

int MenuAdmin() {

    int n = 0, infal, pilih;
    do {
        menu:
        infal = 0;
        printf("\t\t\t\t[MENU GUDANG]                                          \n");
        printf("\t\t\t\t-------------------------------------------------------\n");
        n = ReadProduct(); 
		printf("\n\t\t\t\t-------------------------------------------------------\n");	            
	    printf("\t\t\t\t|| 1. Tambah Barang                                  ||\n");
		printf("\t\t\t\t|| 2. Hapus Barang                                   ||\n");					
		printf("\t\t\t\t|| 3. Edit Barang                                    ||\n");	
		printf("\t\t\t\t|| 4. Kembali                                        ||\n");
		printf("\t\t\t\t-------------------------------------------------------\n");
        printf("\n\t\t\t\tInputkan Pilihan : ");
        scanf("%d", &pilih); 
        switch (pilih) {
            case 1 : { 
                AddBarang(n);
                goto menu;
                break;
            }
            case 2 : { 
                DeleteProduct(n);
                goto menu;
                break;
            }
            case 3 : {
            	UpdateBrng(n);
            	goto menu;
		break;
	    }
	    case 4 : {
		    exit(0);
	    }
		
        }
    } while (pilih != 0);
    //system("cls);

    return 0;
}

int ReadProduct(){
	FILE *file;
	int a=0;
	int ch;
	char *lis = "list_barang.txt";
	ListBrng brg;
	
//	file = fopen("list_barang.txt", "r");
	// 
	if ( (file = fopen(lis,"r"))== NULL )
	{
		printf("\t\t\t\tFile tidak dapat dibuka!\r\n");
	}
	
/*Menampilkan List barang*/
//	printf("---------------------------------------------\n");
	printf("\t\t\t\tNo\tNama Barang\t\t\tHarga\tStok\n");
	printf("\t\t\t\t-------------------------------------------------------\n");
	while (fscanf(file,"\t\t\t\t%d;%[^;];%d;%d\n", &brg[a].no, &brg[a].NmBrng, &brg[a].HrgBrng, &brg[a].StokBrng) != EOF)
	{
		printf("\t\t\t\t%d\t%-20s\t\t%d\t%d\n", brg[a].no, brg[a].NmBrng, brg[a].HrgBrng, brg[a].StokBrng);
		a++;
	}	
	fclose(file);
	
	printf("\n\t\t\t\tjumlah jenis produk : %d",a);	
	return a;
}

void AddBarang(int b) {
	FILE *file;
	char *dir = "list_barang.txt";
	int stok;
	ListBrng brg;

	if ((file = fopen(dir, "a")) == NULL) {
		printf("\t\t\t\tFile tidak dapat dibuka!\r\n");
		exit(1);
	}

	system("cls");
	printf("\n");

	brg[b].no = b;
	printf("\t\t\t\t[TAMBAH BARANG]                                        \n");
    printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\tNama Produk\t: ");
	fflush(stdin);
	scanf("%[^\n]", &brg[b].NmBrng);
	printf("\t\t\t\tHarga Produk\t: ");
	scanf("%d", &brg[b].HrgBrng);	
	do {
		printf("\t\t\t\tStok Produk\t: ");
		scanf("%d", &stok);

		if (stok < 0) {
			printf("\t\t\t\tInput stok tidak valid. Harap masukkan angka yang lebih besar dari atau sama dengan nol!\n");
		}
	} while (stok < 0);

	brg[b].StokBrng = stok;

	fprintf(file, "\n\t\t\t\t%d;%s;%d;%d", brg[b].no, brg[b].NmBrng, brg[b].HrgBrng, brg[b].StokBrng);
	fclose(file);
	system("cls");
}

void DeleteProduct(int b){
	FILE *file, *fl;
	char *dir = "list_barang.txt";
	ListBrng brg;
	int id, x=0, y=0, z;
	char confirm, confirm2;
	
	ulang :
	system("cls");
	printf("\n");
	printf("\t\t\t\t[HAPUS BARANG]                                         \n");
	printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\tMasukkan nomor produk yang akan dihapus : "); scanf("%d",&id);
	if (id < 0 || id > b){
		goto ulang;
	}
	else{
		fl = fopen(dir,"r");
		do{
			fscanf(fl,"%d;%[^;];%d;%d\n", &brg[y].no, &brg[y].NmBrng, &brg[y].HrgBrng, &brg[y].StokBrng);
			y++;
		}
		while(!feof(fl));
		fclose(fl);
		
		printf("\t\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t\tNo\tNama Barang\t\t\tHarga\tStok\n");
		printf("\t\t\t\t%d\t%-20s\t\t%d\t%d\n", brg[id].no, brg[id].NmBrng, brg[id].HrgBrng, brg[id].StokBrng);
		printf("\t\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t\tAnda yakin ingin menghapus produk (%d. %s) ? y/t ",brg[id].no, brg[id].NmBrng);
		fflush(stdin);
		scanf("%c",&confirm);
		confirm2 = toupper(confirm);
				
		if(confirm2 == 'Y'){
			for (z=id; z<b; z++){
				brg[z].NmBrng, brg[z+1].NmBrng;
				brg[z].HrgBrng = brg[z+1].HrgBrng;
				brg[z].StokBrng = brg[z+1].StokBrng;
			}
			//proses penulisan ulang pada file		
			b--;
			file = fopen(dir,"w");
			do{
				fprintf(file, "%d;%s;%d;%d", brg[x].no, brg[x].NmBrng, brg[x].HrgBrng, brg[x].StokBrng);
				x++;
				if(x<b){
					fprintf(file,"\n");
				}
			}	
			while(x<b);
			fclose(file);
			system("cls");
		}
	}
}

void UpdateBrng(int b) {
	FILE *file;
	char *dir = "list_barang.txt";
	ListBrng brg;
	int id, d = 0, c, stok;

	system("cls");
	printf("\n");

	do { // Repeat if input is invalid
		printf("\t\t\t\t[EDIT BARANG]                                          \n");
        printf("\t\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t\tMasukkan nomor produk yang akan diubah: ");
		scanf("%d", &id);
		for (c = 0; c <= id; c++) {
			if (id == brg[c].no) {
				printf("\t\t\t\t-------------------------------------------------------\n");
				printf("\t\t\t\tNo\tNama Barang\t\t\tHarga\tJumlah\n");
				printf("\t\t\t\t%d\t%-20s\t\t%d\t%d\n", brg[c].no, brg[c].NmBrng, brg[c].HrgBrng, brg[c].StokBrng);
				printf("\t\t\t\t-------------------------------------------------------\n");
				printf("\t\t\t\tNama Barang yang Baru\t: ");
				fflush(stdin);
				scanf("%[^\n]", &brg[c].NmBrng);
				printf("\t\t\t\tHarga Barang yang Baru\t: ");
				scanf("%d", &brg[c].HrgBrng);
				do {
					printf("\t\t\t\tStok Barang yang Baru\t: ");
					scanf("%d", &stok);
					if (stok < 0) {
						printf("\t\t\t\tInput stok tidak valid. Silakan masukkan nilai stok yang lebih besar dari 0.\n");
					}
				} while (stok < 0);
				brg[c].StokBrng = stok;

				file = fopen(dir, "w");
				system("cls");
				do {
					fprintf(file, "%d;%s;%d;%d", brg[d].no, brg[d].NmBrng, brg[d].HrgBrng, brg[d].StokBrng);
					d++;
					if (d < b) {
						fprintf(file, "\n");
					}
				} while (d < b);
				fclose(file);
			}
			else continue;
		}
	} while (id < 0 && id > b);
}

// Prosedur dari referensi internet untuk menentukan posisi 
void gotoxy(int x, int y){
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

// Menampilkan judul kalkulator
void tampilan(){
int i;
system("cls");
i=1;
gotoxy(5,1);printf("##================================[ S E L A M A T   D A T A N G ]=================================##");
gotoxy(5,3);printf("##================================              D I              =================================##");
while (i<=10){
	gotoxy(5,4);	printf("||");																	gotoxy(110,4);	printf("||");
	gotoxy(5,5);	printf("||");																	gotoxy(110,5);	printf("||");
	gotoxy(5,6);	printf("||");																	gotoxy(110,6);	printf("||");
	gotoxy(5,7);	printf("||");																	gotoxy(110,7);	printf("||");
	gotoxy(5,8);	printf("||");																	gotoxy(110,8);	printf("||");
	gotoxy(5,9);	printf("||");																	gotoxy(110,9);	printf("||");
	gotoxy(5,10);	printf("||");																	gotoxy(110,10);	printf("||");
	gotoxy(5,11);	printf("||");																	gotoxy(110,11);	printf("||");
	
	
	
	
	
	gotoxy(i,5);	printf("\t\t    *#*    ##         *#*    *#     #*    *#*    *######*  *######*  \n");
	gotoxy(19-i,6);	printf("\t\t   #   #   ##        #   #   ###   ###   #   #   ##     #     ##     \n");
	gotoxy(i-1,7);	printf("\t\t  #     #  ##       #     #  ## # # ##  #     #  #######*     ##     \n");
	gotoxy(19-i,8);	printf("\t\t  #######  ##       #######  ##  *  ##  #######  ##*##        ##     \n");
	gotoxy(i-1,9);	printf("\t\t  ##   ##  ##       ##   ##  ##     ##  ##   ##  ##   #       ##     \n");
	gotoxy(19-i,10);printf("\t\t  ##   ##  #######  ##   ##  ##     ##  ##   ##  ##    #      ##     \n");
	Sleep(300);
	i++;
	}
gotoxy(5,12);printf("##=========================== S E L A M A T  B E R B E L A N J A ====================================##");
}

