#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


// void* myTurn(void* arg){
//     int *iptr = (int*)arg;
//     for(int i=0;i<5;i++){
//         sleep(1);
//         printf("%d",*iptr);
//         (*iptr)++;
//     }
//     return NULL;
// }

// void yourTurn(){
//     while(1){
//         sleep(2);
//         printf("Your Turn\n");
//     }
// }

void* myFunction(void* arg){
    pthread_t id = pthread_self();
    sleep(1);
    printf("Thread id is %lu\n",id);
    pthread_exit(NULL);
}

int main(){
    // int v = 0;
    // pthread_t newThread;
    // pthread_create(&newThread,NULL,myTurn,&v);
    // yourTurn();
    // pthread_join(newThread,NULL);

    //question 1
    pthread_t mythread;
    pthread_create(&mythread,NULL,myFunction,NULL);
    pthread_join(mythread,NULL);

    
    return 0;
}