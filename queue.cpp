#include"queue.h"

// List Pembeli

//void CreateEmpty_Pembeli(Queue_P *Q){	// gakepake
//	
//	*Q = NULL;
//	
//}

//boolean IsEmpty_Pembeli(Queue_P Q){	// gakepake
//	
//	return(isEmpty_Pembeli(Q));
//	
//}

void Enqueue_Pembeli(Queue_P *Q, Queue_BB *P, infochar Y, infotype Z){ // check
	
	address_P a = NULL;
	address_BB b = NULL;
	
	Create_Node_Pembeli(&a);
	Create_Node_BarangBelian(&b);
	Isi_Node_Pembeli(&a, &b, Y, Z);
	Ins_Akhir_Pembeli(&(*Q),a);
	
}

//void Dequeue_Pembeli(Queue_P *Q,infochar *X){
//	
//	Del_Awal_Pembeli(&(*Q),&(*X));
//	
//}

// List BarangBelian

//void CreateEmpty_BarangBelian(Queue_BB *Q){	// gakepake
//	
//	*Q = NULL;
//	
//}

//boolean IsEmpty_BarangBelian(Queue_BB Q){		// gakepake
//		
//	return(isEmpty_BarangBelian(Q));
//	
//}

void Enqueue_BarangBelian(Queue_BB *Q,infotype X, infochar Y, infotype Z){	// check
	
	address_BB a = NULL;
	
	Create_Node_BarangBelian(&a);
	Isi_Node_BarangBelian(&a, X, Y, Z);
	Ins_Akhir_BarangBelian(&(*Q),a);
	
}

//void Dequeue_BarangBelian(Queue_BB *Q,infochar *X){	// gakepake
//	
//	Del_Awal_BarangBelian(&(*Q),&(*X));
//	
//}

// List Antrian


//void CreateEmpty_Antrian(Queue_A *Q){	// gakepake
//	
//	*Q = NULL;
//	
//}

//boolean IsEmpty_Antrian(Queue_A Q){	// gakepake
//	
//	return(isEmpty_Antrian(Q));
//	
//}

//void Enqueue_Antrian(Queue_A *Q,infochar X,infotype Z){	// gakepake
//	
//	address_A a = NULL;
//	
//	Create_Node_Antrian(&a);
//	Isi_Node_Antrian(&a, X);
//	Ins_Akhir_Antrian(&(*Q),a);
//	
//}

void Dequeue_Antrian(Queue_A *Q,infochar *X){	// memberikan nomor antrian dan nama di antrian
	
	Del_Awal_Antrian(&(*Q),&(*X));	// Q disini bertipe address A, dan X passing parameter by address
	
}
