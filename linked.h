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
#include <ctype.h>
#include <string.h>

#define nama(P) (P)->nama
#define Keranjang(P) (P)->Keranjang
#define Dompet(P) (P)->Dompet
#define Nm_pelanggan(P) (P)->Nm_pelanggan
#define Nmr_ksr(P) (P)->Nmr_ksr
#define HrgBrng(P) (P)->HrgBrng
#define NmBrng(P) (P)->NmBrng
#define Qty(P) (P)->Qty
#define next(P) (P)->next
#define Nil NULL

typedef int infotype;
typedef char *infotype2;
typedef struct List_Pelanggan *address_P;
typedef struct ListBarang *address_B;
typedef struct List_Keranjang *address_K;
typedef struct List_Antrian *address_A;


typedef struct List_Pelanggan {
	address_K Keranjang;
	infotype2 Nm_pelanggan;
	infotype Dompet;
	infotype Nmr_ksr;
	address_P next;
} List_Pelanggan;
//typedef struct List_Barang {
//	infotype2 Nm_brg;
//	infotype Harga;
//	address_B next;
//} List_Barang;
typedef struct List_Keranjang {
	infotype2 NmBrng;
	infotype HrgBrng;
	infotype Qty;
	address_K next;
} List_Keranjang;
	typedef struct List_Antrian {
	infotype2 nama;
	address_A next;
} List_Antrian;

typedef struct Kasir{
	infotype no_kasir;
	address_A p;
}datakasir;
typedef struct Login_Kasir{
    char username[50];
    char password[50];
} Login_Kasir;
typedef struct ListBarang{
	char NmBrng[20];	
	infotype StokBrng, HrgBrng, no;
	address_B next;
}ListBrng[100];

int ReadProduct();

void AddBarang(int b);

void DeleteProduct(int b);

void UpdateBrng(int b);

int MenuAdmin();

void Login_Admin();

int cek_akun(Login_Kasir *akun, int jml_akun, char *username, char *password);

// List Pelanggan

boolean isEmpty_Pelanggan(address_P p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_Pelanggan (address_P *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node_Pelanggan (address_P *p ,address_K *k, infotype dompet, infotype2 nm_pelanggan, infotype Nmr_ksr);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List_Pelanggan (address_P p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal_Pelanggan (address_P *p, address_P PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir_Pelanggan (address_P *p, address_P PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

void InsertAfter_Pelanggan (address_P * pBef, address_P PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
void Del_Awal_Pelanggan (address_P * p, infotype2 * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir_Pelanggan (address_P * p, infotype * X, infotype2 * Y);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
void Del_After_Pelanggan (address_P * pBef, infotype * X, infotype2 * Y);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
/* dan alamat elemen setelah pBef di dealokasi */
void DeAlokasi_Pelanggan (address_P * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

// List Barang

boolean isEmpty_Barang(address_B p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_Barang (address_B *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node_Barang (address_B *p , infotype harga, infotype2 nm_brg);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List_Barang (address_B p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal_Barang (address_B *p, address_B PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir_Barang (address_B *p, address_B PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

void InsertAfter_Barang (address_B * pBef, address_B PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
void Del_Awal_Barang (address_B * p, infotype2 * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir_Barang (address_B * p, infotype * X, infotype2 * Y);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
void Del_After_Barang (address_B * pBef, infotype * X, infotype2 * Y);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
/* dan alamat elemen setelah pBef di dealokasi */
void DeAlokasi_Barang (address_B * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

// List Keranjang

boolean isEmpty_Keranjang(address_K p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_Keranjang (address_K *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node_Keranjang (address_K *p , infotype harga, infotype2 nm_brg, infotype qty);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List_Keranjang (address_K p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal_Keranjang (address_K *p, address_K PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir_Keranjang (address_K *p, address_K PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

void InsertAfter_Keranjang (address_K * pBef, address_K PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
void Del_Awal_Keranjang (address_K * p, infotype2 * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir_Keranjang (address_K * p, infotype * X, infotype2 * Y);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
void Del_After_Keranjang (address_K * pBef, infotype * X, infotype2 * Y);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
/* dan alamat elemen setelah pBef di dealokasi */
void DeAlokasi_Keranjang (address_K * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

// List Antrian

// List Pelanggan

boolean isEmpty_Antrian(address_A p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node_Antrian (address_A *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node_Antrian (address_A *p , infotype2 nama);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List_Antrian (address_A p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal_Antrian (address_A *p, address_A PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir_Antrian (address_A *p, address_A PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

void InsertAfter_Antrian (address_A * pBef, address_A PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
void Del_Awal_Antrian (address_A * p, infotype2 * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir_Antrian (address_A * p, infotype * X, infotype2 * Y);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
void Del_After_Antrian (address_A * pBef, infotype * X, infotype2 * Y);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
/* dan alamat elemen setelah pBef di dealokasi */
void DeAlokasi_Antrian (address_A * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
#endif
