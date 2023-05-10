/* File : linked.h */
/* Deskripsi : ADT linked list dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include "boolean.h"

#define nama(P) (P)->nama
#define BarangBelian(P) (P)->BarangBelian
#define Dompet(P) (P)->Dompet
#define Nama_Pembeli(P) (P)->Nama_Pembeli
#define No_Kasir(P) (P)->No_Kasir
#define Harga(P) (P)->Harga
#define Jumlah_Barang(P) (P)->Jumlah_Barang	
#define Nama_Barang(P) (P)->Nama_Barang
#define next(P) (P)->next
#define Nil NULL

typedef int infotype;
typedef const char *infochar;
typedef struct List_Pembeli *address_P;
typedef struct List_Barang *address_B;
typedef struct List_BarangBelian *address_BB;
typedef struct List_Antrian *address_A;


typedef struct List_Pembeli {
address_BB BarangBelian;
infochar Nama_Pembeli;
infotype No_Kasir;
address_P next;
} List_Pembeli;
typedef struct List_Barang{
infochar nama;
infotype stok;
infotype harga; 	
}DataBarang;
typedef struct ListBarang{
	char NmBrng[20];	
	infotype StokBrng, HrgBrng, no;
	address_B next;
}ListBrng[100];
typedef struct List_BarangBelian {
infochar Nama_Barang;
infotype Harga;
infotype Jumlah_Barang;
address_BB next;
} List_BarangBelian;
typedef struct List_Antrian {
infochar nama;
address_A next;
} List_Antrian;
typedef struct Kasir{
infotype Nomor;
address_A next;
}datakasir;
typedef struct Login_Kasir{
    char username[50];
    char password[50];
} Login_Kasir;


// List Pembeli
int MenuPembeli();
void Login_Admin();

boolean isEmpty_Pembeli(address_P p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_Pembeli (address_P *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node_Pembeli (address_P *p ,address_BB *q, infochar Nama_Pembeli, infotype No_Kasir);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Ins_Awal_Pembeli (address_P *p, address_P PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir_Pembeli (address_P *p, address_P PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

// List BarangBelian

boolean isEmpty_BarangBelian(address_BB p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_BarangBelian (address_BB *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar Nama_Barang, infotype Jumlah_Barang);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
void Del_Awal_BarangBelian (address_BB * p, infochar * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir_BarangBelian (address_BB * p, infotype * X, infochar * Y);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */

// List Antrian

boolean isEmpty_Antrian(address_A p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_Antrian (address_A *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)	
void Isi_Node_Antrian (address_A *p , infochar nama);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List_Antrian (address_A p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)

void Ins_Akhir_Antrian (address_A *p, address_A PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

void Del_Awal_Antrian (address_A * p, infochar * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
#endif
