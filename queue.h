#ifndef queue_H
#define queue_H
#include"linked.h"

typedef address_P Queue_P;
typedef address_B Queue_B;
typedef address_K Queue_K;
typedef address_A Queue_A;


// List Pelanggan

void CreateEmpty_Pelanggan(Queue_P *Q);

boolean IsEmpty_Pelanggan(Queue_P Q);

void Enqueue_Pelanggan(Queue_P *Q, Queue_K *K, infotype X, infotype2 Y, infotype Z);

void Dequeue_Pelanggan(Queue_P *Q,infotype2 *X);


// List Barang

void CreateEmpty_Barang(Queue_B *Q);

boolean IsEmpty_Barang(Queue_B Q);

void Enqueue_Barang(Queue_B *Q,infotype X, infotype2 Y);

void Dequeue_Barang(Queue_B *Q,infotype2 *X);


// List Keranjang

void CreateEmpty_Keranjang(Queue_K *Q);

boolean IsEmpty_Keranjang(Queue_K Q);

void Enqueue_Keranjang(Queue_K *Q,infotype X, infotype2 Y, infotype Z);

void Dequeue_Keranjang(Queue_K *Q,infotype2 *X);

// List Antrian

void CreateEmpty_Antrian(Queue_A *Q);

boolean IsEmpty_Antrian(Queue_A Q);

void Enqueue_Antrian(Queue_A *Q,infotype2 X);

void Dequeue_Antrian(Queue_A *Q,infotype2 *X);

#endif
