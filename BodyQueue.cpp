#include"queue.h"

// List Pelanggan

void CreateEmpty_Pelanggan(Queue_P *Q){
	
	*Q = NULL;
	
}

boolean IsEmpty_Pelanggan(Queue_P Q){
	
	return(isEmpty_Pelanggan(Q));
	
}

void Enqueue_Pelanggan(Queue_P *Q, Queue_K *K, infotype X, infotype2 Y, infotype Z){
	
	address_P a = NULL;
	address_K b = NULL;
	
	Create_Node_Pelanggan(&a);
	Create_Node_Keranjang(&b);
	Isi_Node_Pelanggan(&a, &b, X, Y, Z);
	Ins_Akhir_Pelanggan(&(*Q),a);
	
}

void Dequeue_Pelanggan(Queue_P *Q,infotype2 *X){
	
	Del_Awal_Pelanggan(&(*Q),&(*X));
	
}

// List Barang

void CreateEmpty_Barang(Queue_B *Q){
	
	*Q = NULL;
	
}

boolean IsEmpty_Barang(Queue_B Q){
	
	return(isEmpty_Barang(Q));
	
}

void Enqueue_Barang(Queue_B *Q,infotype X, infotype2 Y){
	
	address_B a = NULL;
	
	Create_Node_Barang(&a);
	Isi_Node_Barang(&a, X, Y);
	Ins_Akhir_Barang(&(*Q),a);
	
}

void Dequeue_Barang(Queue_B *Q,infotype2 *X){
	
	Del_Awal_Barang(&(*Q),&(*X));
	
}

// List Keranjang

void CreateEmpty_Keranjang(Queue_K *Q){
	
	*Q = NULL;
	
}

boolean IsEmpty_Keranjang(Queue_K Q){
	
	return(isEmpty_Keranjang(Q));
	
}

void Enqueue_Keranjang(Queue_K *Q,infotype X, infotype2 Y, infotype Z){
	
	address_K a = NULL;
	
	Create_Node_Keranjang(&a);
	Isi_Node_Keranjang(&a, X, Y, Z);
	Ins_Akhir_Keranjang(&(*Q),a);
	
}

void Dequeue_Keranjang(Queue_K *Q,infotype2 *X){
	
	Del_Awal_Keranjang(&(*Q),&(*X));
	
}

// List Antrian


void CreateEmpty_Antrian(Queue_A *Q){
	
	*Q = NULL;
	
}

boolean IsEmpty_Antrian(Queue_A Q){
	
	return(isEmpty_Antrian(Q));
	
}

void Enqueue_Antrian(Queue_A *Q,infotype2 X,infotype Z){
	
	address_A a = NULL;
	
	Create_Node_Antrian(&a);
	Isi_Node_Antrian(&a, X);
	Ins_Akhir_Antrian(&(*Q),a);
	
}

void Dequeue_Antrian(Queue_A *Q,infotype2 *X){
	
	Del_Awal_Antrian(&(*Q),&(*X));
	
}
