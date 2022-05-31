#pragma once
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define SIZE 4096
#define PathName "/home/ams/Workspace/SharedMemory/shm"
#define ProjID 0x66

int main()
{
	key_t k = ftok(PathName, ProjID);
	if (k < 0)
	{
		perror("ftok!");
		return k;
	}
	printf("k: %x\n", k);
	int shmid = shmget(k, SIZE, IPC_CREAT);
	if (shmid < 0)
	{
		perror("shmget");
		return shmid;
	}
	printf("shmid:%d\n", shmid);

	printf("attach begin:\n");
	sleep(3);
	char* mem = (char*)shmat(shmid, NULL, 0);
	printf("attach end: %d\n", (int)*mem);
	sleep(3);


	while (::strcmp(mem, "quit") != 0)
	{
		scanf("%s", mem);
	}

	printf("detach begin:\n");
	sleep(3);
	shmdt(mem);
	printf("detach end.\n");
	sleep(3);

	return 0;
}
