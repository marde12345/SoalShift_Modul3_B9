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

struct Weapon weap[6];
struct Weapon *p_weap;

void init(){
	strcpy(weap[0].name,"MP4A1");
	strcpy(weap[1].name,"PM2-V1");
	strcpy(weap[2].name,"SPR-3");
	strcpy(weap[3].name,"SS2-V5");
	strcpy(weap[4].name,"SPG1-V3");
	strcpy(weap[5].name,"MINE");
}

int main(){
	//obtain access
	key_t key=112358;
	int shmid;

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

	init();

	


	//Detach
	shmdt(p_weap);
	//control
	shmctl(shmid, IPC_RMID, NULL);	
		
	return 0;
}