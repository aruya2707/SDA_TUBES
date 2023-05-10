#include"linked.h"

int main(){
	int pilih;
	printf("#  S E L A M A T   D A T A N G   D I   A L A M A R T   #\n");
	printf("########################################################\n");
	printf("1. Login Gudang\n2. Pembeli\n3. Kembali\n");
	printf("########################################################\n");
	printf("Pilih :");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 :
			Login_Admin();	//untuk update barang-barang
			break;
		case 2 :
			MenuPembeli(); //untuk transaksi kasir
			break;
		case 3 :
			exit(1);
			break;
	}
	return 0;
}