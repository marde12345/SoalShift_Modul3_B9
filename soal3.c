#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int Lohanstat=100,
	Kepitingstat=100,
	Makan=10;

void hello(){
	printf("Selamat datang di Game Aidil cari ikan\n");
	printf("Kami sediakan ikan Lohan dan Kepiting\n");
	printf("Start (Press any key)\n");
	system("pause");
}

void *LohanLapar(){
	while(1){
		sleep(10);
		Lohanstat-=15;
	}
}

void *KepitingLapar(){
	while(1){
		sleep(20);
		Kepitingstat-=10;
	}
}

void *Makanin(){
	printf("Beri makan :\n");
	printf("1. Untuk Lohan\n");
	printf("2. Untuk Kepiting\n");		
	int num;
	scanf("%d",&num);

	if(num==1) Lohanstat+=10;
	if(num==2) Kepitingstat+=10;
}

void view(){
	time_t now;
	now=time(NULL);
	printf("Status Peliharaan Aidil pada %s\n", ctime(&now));
	printf("Status Lohan saat ini %d\n",Lohanstat);
	printf("Status Kepiting saat ini %d\n",Kepitingstat );
}

int main(){
	pthread_t tid[3];
	hello();
	if(pthread_create(&(tid[1]),NULL,&LohanLapar,NULL)!=0){
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&(tid[2]),NULL,&KepitingLapar,NULL)!=0){
		exit(EXIT_FAILURE);
	}
	while(1){
		system("clear");
		view();
		if(Lohanstat<=0 || 
			Lohanstat >100 || 
			Kepitingstat<=0 || 
			Kepitingstat>100){
		system("clear");
		printf("Anda sudah kalah :(\n");
		break;
		}

		if(pthread_create(&(tid[0]),NULL,&Makanin,NULL)!=0){
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
}