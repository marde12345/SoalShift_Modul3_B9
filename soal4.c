#include <stdio.h>
#include <string.h>

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
	int x=argc-1;
	int data[x];
	// while(x--){
	// 	char temp[256];
	// 	strcpy(temp,argv[x]);
	// 	data[x]=atoi(temp)-1;
	// }
	// for(x=0;x<argc-1;x++) printf("%d\n",data[x]);
}