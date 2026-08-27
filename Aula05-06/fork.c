#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void){
    for (int i = 0;  i < 3; i++){
        pid_t pid = fork();

        if (pid < 0){
            perror("Ocorreu um erro");
            return 1;
        } else if(pid == 0) {
            printf("Filho %d, PID=%d\n", i, pid);
            return 0;
        }
    }
    for (int i = 0; i < 3; i++){
        wait(NULL);
    }
    printf("Pai: todos Terminaram");
    return 0;
    
}