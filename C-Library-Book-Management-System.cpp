#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct buku{
	int id[101];
	char judul[101][30];
	char penulis[101][30];
	int tahun[101];	
};

int index = 0;

struct buku info; 

void read(){
	FILE *read;
	read = fopen("perpus.txt", "r");
	
	while(!feof(read)){
		fscanf(read, "%d#%[^#]#%[^#]#%d\n", &info.id[index], &info.judul[index], &info.penulis[index], &info.tahun[index]);
		index++;
	}
	fclose(read);
}

void printdata(){
	printf("Library :\n");
	printf("===========================================\n");
	for(int i = 0; i < index; i++){
		if(info.id[i] != 0){
			printf("%2d | %-10s | %-10s | %-10d \n",info.id[i], info.judul[i], info.penulis[i], info.tahun[i]);
		}
	}
	printf("===========================================\n");	
	printf("\n");
}


void tambahbuku(){
	if(index < 100){
	backmenu:
		printf("Masukan ID\n");
		scanf("%d", &info.id[index]);
		
		for(int i = 0; i < index; i++){
			if(info.id[index] == info.id[i]){
				printf("ID Sudah Terdaftar\n");
				goto backmenu;
			}
		}

		printf("Masukan Judul\n");getchar();
		scanf("%[^\n]", &info.judul[index]);
		printf("Masukan Penulis\n");getchar();
		scanf("%[^\n]", &info.penulis[index]);
		printf("Masukan Tahun\n");
		scanf("%d", &info.tahun[index]);
		
		index++;
		printf("\n");
		printdata();

	}else if(index >= 100){	
		printf("Daftar Buku Sudah Penuh\n");getchar();	
	}
}

void bubblesortname(){
	char tempname[200];
	int tempID;
	int tempTahun;
	char temppenulis[200];
	
	for(int i = 0; i < index; i++){
		for(int j = 0; j < index - 1; j++){
			if(strcmp(info.judul[j], info.judul[j + 1]) > 0){
				strcpy(tempname, info.judul[j]);
				strcpy(info.judul[j], info.judul[j+ 1]);
				strcpy(info.judul[j + 1], tempname);
				//
				tempID = info.id[j];
				info.id[j] = info.id[j + 1];
				info.id[j + 1] = tempID;
				//
				tempTahun = info.tahun[j];
				info.tahun[j] = info.tahun[j + 1];
				info.tahun[j + 1] = tempTahun;
				//
				strcpy(temppenulis, info.penulis[j]);
				strcpy(info.penulis[j], info.penulis[j+ 1]);
				strcpy(info.penulis[j + 1], temppenulis);
			}
		}
	}
	printdata();
}

void judul(){
	printf("=====================\n");
	printf("     PERPUSTAKAAN\n");
	printf("=====================\n\n");	
}

void update(){
	printdata();
	int poinID;
	int find = 0;
	updatepoin:
	printf("Masukan ID :\n");
	scanf("%d", &poinID);
	
	for(int i = 0; i < index; i++){
		if(poinID == info.id[i]){
			printf("Masukan Judul Baru\n");getchar();
			scanf("%[^\n]", &info.judul[i]);
			printf("Masukan Penulis Baru\n");getchar();
			scanf("%[^\n]", &info.penulis[i]);
			printf("Masukan Tahun Baru\n");
			scanf("%d", &info.tahun[i]);
			find = 1;
			break;
		}
	}
	if(find == 0){
		printf("ID tidak terdaftar\n");
		goto updatepoin;	
	}	
	printdata();
}

void erasedata(){
	printdata();
	int tandaID;
	int tanda = 0;
	updatepoin:
	printf("Masukan ID :\n");
	scanf("%d", &tandaID);
	
	for(int i = 0; i < index; i++){
		if(tandaID == info.id[i]){
			info.id[i] = '\0';
			tanda = 1;
			break;
		}
	}
	if(tanda == 0){
		printf("ID tidak terdaftar\n");
		goto updatepoin;	
	}
	printf("\n");
	printdata();		
}


int main(){
	read();
	
	mainmenu:
		system("cls");
	
		int nomor;
		do{
			system("cls");
			judul();
			printf("Menu Utama : \n"); 
			printf("\n");
			printf("1. Input Book Record\n");
			printf("2. Display Book Record\n");
			printf("3. Update Book Record\n");
			printf("4. Erase Book Record\n");
			printf("5. Save and Exit\n");
			printf("Nomor : ");
			scanf(" %d", &nomor);
		}while ( 1 > nomor || 5 < nomor);
		
		char enter;
		switch(nomor){
			case(1):
				system("cls");
				printdata();
				tambahbuku();getchar();
				printf("Enter untuk lanjut...\n");
				scanf("%c", &enter);
				goto mainmenu;
				break;
			
			case(2):
				system("cls");
				bubblesortname();getchar();
				printf("Enter untuk lanjut...\n");
				scanf("%c", &enter);
				goto mainmenu;
				break;
		
			case(3):
				system("cls");
				update();
				printf("Enter untuk lanjut...\n");
				scanf("%c", &enter);
				goto mainmenu;
				break;
			
			case(4):
				system("cls");
				erasedata();getchar();
				printf("Enter untuk lanjut...\n");
				scanf("%c", &enter);
				goto mainmenu;
				break;
				
			case(5):
				printf("\n");
				printdata();
				printf("\nTerima Kasih, Ditunggu Kunjungan Selanjutnya\n");
				break;		
		}
	
	return 0;
}

