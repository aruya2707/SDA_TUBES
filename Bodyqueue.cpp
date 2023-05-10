#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"queue.h"
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
	        printf("File tidak dapat dibuka\n");
	        exit(1);
	    }
	
	    for (int i = 0; i < jml_akun; i++) {
	        fscanf(file, "%s %s", akun[i].username, akun[i].password);
	    }
	    fclose(file);
	
	    char username[50];
	    char password[50];
	
		system ("cls");
	    printf("Silakan masukkan username dan password\n");
	
	    printf("Username: ");
	    scanf("%s", username);
	    printf("Password: ");
	    scanf("%s", password);
	
	    int kasir = cek_akun(akun, jml_akun, username, password);
	    if (kasir != -1) {
	        printf("Log in berhasil. Selamat datang, %s.\n", akun[kasir].username);
	        system ("cls");
	        //MenuAdmin();
	    } else {
	        printf("Log in gagal. Username atau password salah.\n");
	    }
}


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
