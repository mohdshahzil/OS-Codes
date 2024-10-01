#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t pid1,pid2,pid3,pid4;

    printf("Parent Process : %d\n",getpid());

    pid1 = fork();

    if(pid1==0){
        //Frist Child Process
        printf("First Child Process Started : %d\n", getpid());
        sleep(3);
        printf("First Child Process Ended : %d\n", getpid());
    }else{
        pid2=fork();

        if(pid2==0){
            //Second Child Process
            printf("Second Child Process Started : %d\n", getpid());
            sleep(2);
            printf("Second Child Process Ended : %d\n", getpid());

        }else{
            pid3 = fork();
            if(pid3==0){
                //Third Child Process
                printf("Third Child Process Started : %d\n", getpid());
                sleep(1);
                printf("Third Child Process Ended : %d\n", getpid());
            }else{
                pid4 = fork();
                if(pid4==0){
                    //Fourth Child Process
                    printf("Fourth Child Process Started : %d\n", getpid());
                    sleep(4);
                    printf("Fourth Child Process Ended : %d\n", getpid());
                }else{
                    //Parent Process
                    sleep(5);
                    printf("Parent Process Ended : %d\n", getpid());

                }

            }

        }

    }
    
    return 0;
}