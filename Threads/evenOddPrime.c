#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

void* evenOdd(void* arg){
    int *num = (int *)arg;
    if(*num%2==0){
        printf("Even\n");
    }
    else{
        printf("Odd\n");
    }

    return NULL;
}

void* primeCheck(void* arg){
    int *num = (int *)arg;
    int flag = 0;
    for(int i=2;i<=*num/2;i++){
        if(*num%i==0){
            flag = 1;
            break;
        }
    }

    if(flag==0){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }

    return NULL;
}


int main(){
    pthread_t evenOddThread, primeThread;
    printf("Enter a number : ");
    int num;
    scanf("%d",&num);

    pthread_create(&evenOddThread,NULL,evenOdd,&num);
    pthread_create(&primeThread,NULL,primeCheck,&num);

    pthread_join(evenOddThread,NULL);
    pthread_join(primeThread,NULL);
    
    return 0;
}