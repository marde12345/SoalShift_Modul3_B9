#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void *fact(void *arg){
	int num=*((int *)arg);
	int i,con=1;
	for(i=1;i<=num;i++) con*=i;
	printf("Hasil %d! = %d\n",num,con );
	sleep(1);
}

int main(int argc, char **argv){
	pthread_t tid[argc-1];
	int x=argc;
	int data[x-1];
	for(x=0;x<argc-1;x++){
		char temp[256];
		strcpy(temp,argv[x+1]);
		data[x]=atoi(temp);
	}
	bubbleSort(data,x);
	for(x=0;x<argc-1;x++){
			if(pthread_create(&(tid[x]),NULL,&fact,&data[x])!=0){
				exit(EXIT_FAILURE);
			}
			pthread_join(tid[x],NULL);
		}
	return 0;
}