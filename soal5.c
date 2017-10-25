#include<stdio.h>
#include<unistd.h>

void *count(void * arg){
	char key[100]=(void *)arg;
	char command[1000]="";
	strcat(command,"grep -o '");
	strcat(command,key);
	strcat(command,"' Novel.txt | wc -l");
	system(command);
}