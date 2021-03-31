#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void interruptHandler(int);
void quitHandler(int);

unsigned int Interrupts = 0;

int main()
{
    if (signal(SIGINT, interruptHandler) == SIG_ERR)
    {
        printf("Hiba tortent!\n");
        return 0;
    }

    if (signal(SIGQUIT, quitHandler) == SIG_ERR)
    {
        printf("Hiba tortent!\n");
        return 0;
    }

    while(Interrupts < 2)
    {
        printf("Varunk a jelre...\n");
        sleep(1);
    }

    printf("Megerkezett a masodik \"SIGINT\" jel!");
    return 0;
}

void interruptHandler(int sig)
{
    printf("SIGINT signal: %d\n", sig);
    Interrupts++;
}

void quitHandler(int sig)
{
    printf("SIGQUIT signal: %d\n", sig);
}
