#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void *count(void * arg){
	char *key=(void *)arg;
	char command[1000]="";
	printf("%s : ",key);
	strcat(command,"grep -o '");
	strcat(command,key);
	strcat(command,"' Novel.txt | wc -l");
	system(command);
	sleep(1);
}

int main(int argc, char **argv){
	pthread_t tid[argc-1];
	int i;

	for(i=1;i<argc;i++){
		if(pthread_create(&(tid[i]),NULL,&count,argv[i])!=0){
			exit(EXIT_FAILURE);
		}
		pthread_join(tid[i],NULL);
	}
}