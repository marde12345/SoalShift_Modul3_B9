#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int p1[16],p2[16];
int sc1=0,sc2=0;
char player1[100],player2[100];

void view(){
	time_t now;
	now=time(NULL);
	printf("Score pada permainan ini %s\n", ctime(&now));
	printf("Score %s\n",player1);
	printf("Score %s\n",player2);
}

int main(){
	pthread_t tid[2];
	printf("Masukkan Nickname Player 1 : "); scanf("%s",player1);
	printf("Masukkan Nickname Player 2 : "); scanf("%s",player2);


}