#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("This is a special signal handler for SIGINT\n");
    else if (signo == SIGTSTP)
        printf("This is a special sinal handler for SIGTSTP\n");
    else if (signo == SIGQUIT)
        printf("This is a special signal handler for SIGQUIT\n");
}

int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    if (signal(SIGTSTP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGTSTP\n");
    if (signal(SIGQUIT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGQUIT\n");
    
    while(1) 
        sleep(1);
    return 0;
}
