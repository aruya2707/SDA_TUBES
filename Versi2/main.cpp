#include <stdio.h>
#include <stdlib.h>
//#include "cassier"
#include "antrian.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Kasir kasir[3];
	Queue MyQueue;
	
	int pilih;
	printf("#  S E L A M A T   D A T A N G   D I   A L A M A R T   #\n");
	printf("########################################################\n");
	printf("1. Login Admin\n2. Login Kasir\n3. Kembali\n");
	printf("########################################################\n");
	printf("Pilih :");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 :
			Login_Admin();
			system ("cls");
			break;
		case 2 :
			Login_Customer();
			break;
		case 3 :
			exit(1);
			break;
	}
	return 0;
}

