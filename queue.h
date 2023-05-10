#ifndef queue_H
#define queue_H
#include"linked.h"

typedef address_P Queue_P;
typedef address_B Queue_B;
typedef address_BB Queue_BB;
typedef address_A Queue_A;


// List Pelanggan

//// void CreateEmpty_Pembeli(Queue_P *Q);

//// boolean IsEmpty_Pembeli(Queue_P Q);

void Enqueue_Pembeli(Queue_P *Q, Queue_BB *K, infochar Y, infotype Z);

//// void Dequeue_Pembeli(Queue_P *Q,infochar *X);


// List BarangBelian

//// void CreateEmpty_BarangBelian(Queue_BB *Q);

//// boolean IsEmpty_BarangBelian(Queue_BB Q);

void Enqueue_BarangBelian(Queue_BB *Q,infotype X, infochar Y, infotype Z);

//// void Dequeue_BarangBelian(Queue_BB *Q,infochar *X);

// List Antrian

//// void CreateEmpty_Antrian(Queue_A *Q);

//// boolean IsEmpty_Antrian(Queue_A Q);

//// void Enqueue_Antrian(Queue_A *Q,infochar X,infotype Z);

void Dequeue_Antrian(Queue_A *Q,infochar *X);

#endif

