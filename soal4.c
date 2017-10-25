#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, char **argv){
	int x=argc;
	int data[x-1];
	for(x=0;x<argc-1;x++){
		char temp[256];
		strcpy(temp,argv[x+1]);
		data[x]=atoi(temp);
	}
	for(x=0;x<argc-1;x++) printf("%s %d\n",argv[x+1],data[x]);
}