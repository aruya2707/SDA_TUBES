#include "cassier.h"
#include <stdio.h>
#include <stdlib.h>


int ListEmpty(ListBarang Brng){
	int c = 0;
	FILE *listBarangnya;
	
	listBarangnya = fopen("daftarbarang.dat", "rb");
	while (fread(&Brng, sizeof(Brng), 1, listBarangnya))
	c = 1;
	fclose(listBarangnya);
	return c;
}

int readProduct(){
	FILE *filebarang;
	int a, ch;
	a = 0;
	char *list = "..\\TUBESSDAsms2\\list_barang.txt";
	ListBarang brg;
	
	if ( (filebarang = fopen(list,"r")) == NULL )
	{
		printf("File tidak dapat dibuka!\r\n");
	}
	
	system("cls");
	printf("\t\t=========================================\n");
	printf("\n");
	
	//tampil produk	
	printf("\t\tNo\tNama Produk\t\tHarga\tJumlah\n");
	while (fscanf(filebarang,"%d;%[^;];%d;%d\n", &brg[a].no, &brg[a].NmBrng, &brg[a].StokBrng, &brg[a].HrgBrng) != EOF)
	{
		printf("\t\t%d\t%-20s\t%d\t%d\n", brg[a].no, brg[a].NmBrng, brg[a].StokBrng, brg[a].HrgBrng);
		a++;
	}	
	fclose(file);
	
	printf("\n\t\tjumlah baris : %d",a);
	printf("\n\t\t-----------------------------------------\n");
	printf("\t\t                  Menu\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t1.Tambah Produk\n\t\t2.Ubah Produk\n\t\t3.Hapus Produk\n\t\t0.Keluar\n");
	printf("\t\tPilih : ");	
	
	return a;
}

void AddBarang(int b){
	FILE *filebarang;
	char *list = "..\\TUBESSDAsms2\\list_barang.txt";
	ListBarang brg;

	if ( (file = fopen(list,"a")) == NULL )
	{
		printf("File tidak dapat dibuka!\r\n");
		exit(1);
	}
		
	system("cls");
	printf("\t\t=========================================\n");
	printf("\n");
		
	brg[b].no = b;
	printf("\t\tNama Produk\t: "); 
	fflush(stdin);
	scanf("%[^\n]", &brg[b].NmBrng);
	printf("\t\tHarga Produk\t: "); 
	scanf("%d", &brg[b].HrgBrng);
	printf("\t\tStok Produk\t: " ); 
	scanf("%d", &brg[b].StokBrng);
		
	fprintf(file, "\n%d;%s;%d;%d", brg[b].no, brg[b].NmBrng, brg[b].HrgBrng, brg[b].StokBrng);
	fclose(file);
}

void deleteProduct(int b){
	FILE *filebarang, *file1;
	char *list = "..\\TUBESSDAsms2\\list_barang.txt";
	ListBarang brg;
	infotype no, k=0, l=0, j;
	infochar konfir1, konfir2;
	
	ulang :
	system("cls");
	printf("\t\t=========================================\n");
	printf("\n");
	printf("\t\tMasukkan nomor produk yang akan dihapus : "); scanf("%d",&no); //input nomor
	if (no < 0 || no > b){
		goto ulang;
	}
	else{
		filel = fopen(list,"r");
		do{
			fscanf(fl,"%d;%[^;];%d;%d\n", &brg[l].no, &brg[l].NmBrng, &brg[l].HrgBrng, &brg[l].StokBrng);
			y++;
		}
		while(!feof(filel));
		fclose(filel);
		
		printf("\t\t-----------------------------------------\n");
		printf("\t\tNo\tNama Produk\t\tHarga\tJumlah\n");
		printf("\t\t%d\t%-20s\t%d\t%d\n", brg[no].no, brg[no].NmBrng, brg[no].HrgBrng, brg[no].StokBrng);
		printf("\t\t-----------------------------------------\n");
		printf("\t\tAnda yakin ingin menghapus produk (%d. %s) ? [y/t] ",brg[no].no, brg[no].NmBrng);
		fflush(stdin);
		scanf("%c",&konfir1);
		konfir2 = toupper(konfir1);
				
		if(konfir2 == 'Y'){
			for (j=no; j<b; j++){
				strcpy(brg[j].NmBrng, brg[j+1].NmBrng);
				brg[j].HrgBrng = brg[j+1].HrgBrng;
				brg[j].StokBrng = brg[j+1].StokBrng;
			}
					
			b--;
			file = fopen(list,"w");
			do{
				fprintf(file, "%d;%s;%d;%d", brg[k].no, brg[k].NmBrng, brg[k].HrgBrng, brg[k].StokBrng);
				k++;
				if(k<b){
					fprintf(file,"\n");
				}
			}	
			while(k<b);
			fclose(filebarang);
		}
	}
}

void list_barang(){
	char barang[255];
	FILE *tlistbarang;
	
	(fkatalog = fopen("list_barang.txt","r")) == NULL;
	
	while(fgets(barang, sizeof(barang), tlistbarang))
	{
		printf("%s", barang);
    }
	
	fclose(tlistbarang);
}