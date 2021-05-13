#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

#define KEY 123L

void up(int);
void down(int);

int main(void) 
{  
  
    int semID = semget(KEY, 0, 0);
    
    if (semID == -1) 
    {
        perror("Hiba tortent!\n");
        exit(-1);
    }

    printf("Belepunk a kritikus szakaszba!\n");

    down(semID);

    sleep(3);

    printf("Pid : %d\n", getpid());

    printf("%d \n", semctl(semID, 0, GETVAL));

    up(semID);

    printf("Kilepunk a kritikus szakaszbol!\n");

}


void up(int semId) 
{

    struct sembuf buffer;

    buffer.sem_num = 0;
    buffer.sem_op = 1;
    buffer.sem_flg = 0;

    semop(semId, &buffer, 1);
}

void down(int semId) 
{

    struct sembuf buffer;

    buffer.sem_num = 0;
    buffer.sem_op = -1;
    buffer.sem_flg = 0;

    semop(semId, &buffer, 1);
}
