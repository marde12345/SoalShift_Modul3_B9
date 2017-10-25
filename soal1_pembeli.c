#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

typedef struct weapon{
	char name[6][7];
	strcpy(name[0],"MP4A1");
	strcpy(name[1],"PM2-V1");
	strcpy(name[2],"SPR-3");
	strcpy(name[3],"SS2-V5");
	strcpy(name[4],"SPG1-V3");
	strcpy(name[5],"MINE");
	int count[6];
} weapon_entry;

int main(){
	key_t key = 1123458;
	struct weapon_entry *supply;
	int shmid = shmget(key,sizeof(weapon_entry), IPC_CREAT | 0666);
	supply=(weapon_entry *) shmat(shmid,NULL,0);
	return 0;
}