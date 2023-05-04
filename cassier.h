#ifndef cassier_H
#define cassier_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include "boolean.h"

/***Deklarasi Kamus data***/
/*Node yang berisi list2 barang dagangan ada stok dan harga
dimana setiap pembelianstok akan berkurang dan data pilihan
dimasukkan ke node BrgBelian */
typedef char* infochar;
typedef int infotype;

typedef struct ListBarang{
	infochar NmBrng[20];	
	infotype StokBrng, HrgBrng, no;
}ListBrng[100];

typedef struct Login_Kasir{
    char username[50];
    char password[50];
} Login_Kasir;

typedef struct Date{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
} Date;




/***Deklarasi Modul Barang***/
int ListEmpty(ListBarang Brng);
/*fungsi untuk memeriksa apakah ada list barang pada file*/
int readProduct();
//Fungsi membaca isi file dan menampilkannya ke layar
void AddBarang(int b);
//Menambah barang di file
void deleteProduct(int b);
//Menghapus barang yang ada di dalam file
void list_barang();
//Membaca dan menampilkan file berupa list
int MenuAdmin();

int ReadProduct();

void AddBarang(int b);

void DeleteProduct(int b);

/***Deklarasi Modul Kasir***/
int cek_akun(Login_Kasir *akun, int jml_akun, char *username, char *password);
void Login_Admin();
void Login_Customer();
void MenuCustomer();
Date Create_Date();
//int hitungsubtotal(); //function untuk hitung subtotal
//int hitungkembalian(); //function untuk hitung kembalian

#endif
