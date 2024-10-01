#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t child_pid;
    child_pid = fork();
    if(child_pid==0){
        printf("Child Process : %d. I am from child and printing parent id %d\n",getpid(),getppid());
    }
    else if(child_pid>0){
        printf("Parent Process : %d & Child Process %d\n",getpid(),child_pid);
    }
    else{
        perror("Fork Failed");
    }
    return 0;
}