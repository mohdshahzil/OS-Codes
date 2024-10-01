#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

struct Customer {
    int id;
    int billingTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};


int main(){
    int n = 5;
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0 ;

    struct Customer customers[5] = {
        {1, 4, 0, 0, 0},
        {2, 10, 2, 0, 0},
        {3, 2, 4, 0, 0},
        {4, 20, 6, 0, 0},
        {5, 2, 8, 0, 0}
    };

    int currentTime = 0;
    for(int i=0;i<n;i++){
        if(currentTime<customers[i].arrivalTime){
            currentTime = customers[i].arrivalTime;
        }

        customers[i].waitingTime = currentTime - customers[i].arrivalTime;
        int completionTime = customers[i].billingTime  + currentTime;
        customers[i].turnaroundTime = completionTime - customers[i].arrivalTime;

        currentTime += customers[i].billingTime;
        totalWaitingTime += customers[i].waitingTime;
        totalTurnaroundTime += customers[i].turnaroundTime;
    }

    printf("Customer ID\tBilling Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", customers[i].id, customers[i].billingTime, customers[i].arrivalTime, customers[i].waitingTime, customers[i].turnaroundTime);
    }

    printf("Average Waiting Time: %f\n", totalWaitingTime/n);
    printf("Average Turnaround Time: %f\n", totalTurnaroundTime/n);


    return 0;
}