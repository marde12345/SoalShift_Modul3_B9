#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int counter(char *weapon){
	if(!strcmp(weapon,"MP4A1")) return 0;
	if(!strcmp(weapon,"PM2-V1")) return 1;
	if(!strcmp(weapon,"SPR-3")) return 2;
	if(!strcmp(weapon,"SS2-V5")) return 3;
	if(!strcmp(weapon,"SPG1-V3")) return 4;
	if(!strcmp(weapon,"Mine")) return 5;
}

void hello(){
	printf("Hello, selamat datang di sistem informasi toko ilegal HAWARI\n");
	printf("Disini kami menyediakan beberapa pelayanan pembelian senjata ilegal\n");
	printf("Kami juga termasuk Black-Market, jadi identitas anda selalu menjadi Anonymous\n\n");
	printf("1. List Senjata Yang Tersedia\n");
	printf("2. Pembelian Senjata\n");
	printf("3. Exit\n\n");
	printf("Masukkan pilihan anda : ");
}

void list(int *data[]){
	char name[6][7]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
	int i;
	for(i=0;i<6;i++){
		if(*data[i]) printf("%s %d",name[i],*data[i]);
	}
}

int main(){
	int supply[6];
	key_t key = 112358;
	int **data;

	int shmid=shmget(key,6*sizeof(int), IPC_CREAT | 0666);
	data = shmat(shmid,NULL,0);

	while(1){
		int input;
		system("clear");
		hello();
		scanf("%d",&input);
		switch (input){
			case 1 :{
				system("clear");
				list(data);
				break;
			}
			case 2 :{
				system("clear");
				printf("Untuk pembelian masukkan [NAMA_SENJATA] [JUMLAH]\n");
				printf("MP4A1 %d\n",*data[0]);
				printf("PM2-V1 %d\n",*data[1]);
				printf("SPR-3 %d\n",*data[2]);
				printf("SS2-V5 %d\n",*data[3]);
				printf("SPG1-V3 %d\n",*data[4]);
				printf("MINE %d\n\n",*data[5]);

				beli();
				break;
			}
			case 3 :{
				break;
			}
			default :{
				continue;
			}
		}
	}

	system("clear");
	printf("Terima Kasih\n");
	int cd=5;
	while(cd--){
		printf(".\n");
		sleep(1);
	}
	return 0;
}