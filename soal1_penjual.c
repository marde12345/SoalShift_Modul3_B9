#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Weapon{
	char name[8];
	int stock;
}wweapon;

void list(struct Weapon weap[],int p_shmid){
	system("clear");
	printf("Persediaan senjata black-market HAWARI\n\n");
	printf("Connected to SHMID : %d\n", p_shmid);
	printf("**************************************\n\n");
	if(weap[0].stock>0)printf("%s %d\n",weap[0].name,weap[0].stock);
	if(weap[1].stock>0)printf("%s %d\n",weap[1].name,weap[1].stock);
	if(weap[2].stock>0)printf("%s %d\n",weap[2].name,weap[2].stock);
	if(weap[3].stock>0)printf("%s %d\n",weap[3].name,weap[3].stock);
	if(weap[4].stock>0)printf("%s %d\n",weap[4].name,weap[4].stock);
	if(weap[5].stock>0)printf("%s %d\n",weap[5].name,weap[5].stock);
}

void tambah(struct Weapon weap[],int p_shmid){
	system("clear");
	printf("Kula'an senjata black-market HAWARI\n\n");
	printf("Connected to SHMID : %d\n", p_shmid);
	printf("**************************************\n");
	printf("Ex. --> MP4A1 100\n\n--> ");
	char stemp[8];
	int temp;
	scanf("%s%d",stemp,&temp);

	if(strcmp(weap[0].name,stemp)==0)weap[0].stock+=temp;
	if(strcmp(weap[1].name,stemp)==0)weap[1].stock+=temp;
	if(strcmp(weap[2].name,stemp)==0)weap[2].stock+=temp;
	if(strcmp(weap[3].name,stemp)==0)weap[3].stock+=temp;
	if(strcmp(weap[4].name,stemp)==0)weap[4].stock+=temp;
	if(strcmp(weap[5].name,stemp)==0)weap[5].stock+=temp;
}

void init(struct Weapon weap[]){
	strcpy(weap[0].name,"MP4A1");weap[0].stock=10;
	strcpy(weap[1].name,"PM2-V1");weap[1].stock=10;
	strcpy(weap[2].name,"SPR-3");weap[2].stock=10;
	strcpy(weap[3].name,"SS2-V5");weap[3].stock=10;
	strcpy(weap[4].name,"SPG1-V3");weap[4].stock=10;
	strcpy(weap[5].name,"MINE");weap[5].stock=10;
}

int main(){
	//obtain access
	key_t key=112358;
	int shmid;

	struct Weapon weap[6];
	struct Weapon *p_weap;

	p_weap = &weap[0];

	if((shmid=shmget(key,sizeof(weap),IPC_CREAT | 0666)) < 0){
		perror("SHMGET");
		exit(1);
	}

	//attaching
	if((p_weap=shmat(shmid,NULL,0))==(struct Weapon *) -1){
		perror("SHMAT");
		exit(1);
	}

	init(p_weap);

	


	//Detach
	shmdt(p_weap);
	//control
	shmctl(shmid, IPC_RMID, NULL);	
		
	return 0;
}