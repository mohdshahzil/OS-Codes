#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

void childProcess(int *common){
    printf("Child Process\n");
    printf("Common Variable Value from Child Process : %d\n",*common);
}

void parentProcess(int *common){
    *common+=5;
    printf("Parent Process\n");
    printf("Common Variable Value from Parent Process : %d\n",*common);      
}

int main(){
    int common = 2;
    pid_t child_pid;

    child_pid = fork();
    if(child_pid==0){
        childProcess(&common);
    }else if(child_pid>0){
        parentProcess(&common);
    }else{
        perror("Fork Failed");
    }
    
    return 0;
}
