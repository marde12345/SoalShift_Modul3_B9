#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
	sleep(10);
	Lohanstat-=15;
}

void *KepitingLapar(){
	sleep(20);
	Kepitingstat-=10;
}

int main(){
	hello();

}