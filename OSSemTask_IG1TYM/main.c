#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int p[2];

    if(pipe(p)<0) //Létrehozzuk a csővezetéket és egyben le is ellenőrizzük
    {
        perror("Hiba tortent a csovezetek letrehozasakor!");
        exit(1);
    }

    pid_t pid = fork(); //Létrehozzuk a gyereket

    if(pid<0) //Hibaellenőrzés
    {
        perror("Hiba tortent a gyerek processz letrehozasakor!");
        exit(2);
    }

    switch(pid)
    {
        case 0: //Ha a pid = 0 akkor a gyerek fog futni
        {
            char readBuffer[128]; //Tömb amibe beolvasunk
            wait(NULL);
            int bytes = read(p[0], readBuffer, sizeof(readBuffer)); //Child most olvassa a pipebol
            printf("A gyerek processz ezt olvasta ki: %s (%d Byte)\n",readBuffer,bytes);
        } break;
        default: //Ha a pid > 0 akkor a szülő fog futni
        {
            //Szulo ir a pipeba
            write(p[1], "BB IG1TYM", 10);
            //Szulo irt a pipe-ba, lehet olvasni
        }
    }

    return 0;
}
