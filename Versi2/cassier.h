#ifndef cassier_H
#define cassier_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>
#include "boolean.h"

/***Deklarasi Kamus data***/
/*Node yang berisi list2 barang dagangan ada stok dan harga
dimana setiap pembelianstok akan berkurang dan data pilihan
dimasukkan ke node BrgBelian */
typedef char* infochar;
typedef int infotype;
typedef struct BrgBelian *addressbrg;	//node yg ditunjuk queue sebagai barang belian

typedef struct ListBarang{
	infochar NmBrng;	
	infotype StokBrng,HrgBrng;
}ListBarang;

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


/***Deklarasi Modul Kasir***/
int cek_akun(Login_Kasir *akun, int jml_akun, char *username, char *password);

#endif