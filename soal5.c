#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void *count(void * arg){
	char *key=(void *)arg;
	char command[1000]="";
	strcat(command,"grep -o '");
	strcat(command,key);
	strcat(command,"' Novel.txt | wc -l");
	system(command);
	sleep(1);
}

int main(int argc, char **argv){
	pthread_t tid[argc-1];

	while(--argc){
		if(pthread_create(&(tid[argc]),NULL,&count,argv[argc])!=0){
			exit(EXIT_FAILURE);
		}
		pthread_join(tid[argc],NULL);
	}
}