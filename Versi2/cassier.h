#ifndef cassier_H
#define cassier_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>
#include "boolean.h"
#define First(L) (L).First
#define NmPmbli(P) (P)->NmPmbli
#define Barang(P) (P)->barang
#define Next(P) (P)->next
#define NmBrg(P) (P)->NmBrg
#define StokBrg(P) (P)->StokBrg
#define HrgBrg(P) (P)->HrgBrg
#define JmlBrg(P) (P)->JmlBrg
#define NextBrg(P) (P)->NextBrg
#define Bawaan(P) (P)->Bawaan
#define Head(L) (L).Head
#define Nil NULL
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

#endif
