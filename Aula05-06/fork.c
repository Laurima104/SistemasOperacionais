#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

//fazendo ativ B
int main(void){
    for (int i = 0;  i < 3; i++){
        pid_t pid = fork();
        int n = 20;

        if (pid < 0){
            perror("Ocorreu um erro");
            return 1;
        } else if(pid == 0) {
            switch (i)
            {
            case 0:
                int sum=1;
                for(int ip = 0; ip <= n; ip++){
                    sum += n;
                }
                printf("Filho %d, PID=%d, Soma:%d\n", i, getpid(), sum);
                break;
            case 1:
                int par=0;
                for (int ip = 0; ip <= n; ip++){
                    if(ip%2==0){
                        par++;
                    }
                }
                printf("Filho %d, PID=%d, Numero de Pares:%d\n", i, getpid(), par);
                break;
            case 2:
                int pot = n*n;
                printf("Filho %d, PID=%d, Potencia:%d\n", i, getpid(), pot);
                break;
            }
            return 0;
        }
    }
    for (int i = 0; i < 3; i++){
        wait(NULL);
    }
    printf("Pai: todos Terminaram\n");
    return 0;
    
}