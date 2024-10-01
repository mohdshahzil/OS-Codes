#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid;

    pid = fork();
    if(pid==0){
        printf("Child Process started : %d\n",getpid());
        exit(0);
    }
    else if(pid>0){
        printf("Parent Process started : %d\n",getpid());
        sleep(30);
        printf("Parent Process ended : %d\n",getpid());
    }
    else{
        perror("Fork Failed");
    }
    
    return 0;
}