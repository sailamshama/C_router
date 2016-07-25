#include "assignment2.h"

double getRandTime(double arrivalRate)
{
    double num, time1, max=1, min=0;
    double randNUM= (double)rand() /(RAND_MAX+1.0);
    if (randNUM<0) {
        randNUM=randNUM*-1;
    }
    time1= (-1/arrivalRate) * (log(1-randNUM));
    return time1;
}

void p1(void)
{
    int i,n;
    struct Queue Q=initQueue();
    struct Data d;
    d.arrivalTime=3;
    d.departureTime=3.1;
    enqueue(&Q, d);
    d.arrivalTime=3.5;
    d.departureTime=3.6;
    enqueue(&Q, d);
    d.arrivalTime=3.8;
    d.departureTime=3.9;
    enqueue(&Q, d);
    d.arrivalTime=4.1;
    d.departureTime=4.2;
    enqueue(&Q,d);
    
    n=Q.currSize;
    
    for (i=0; i<n-1; i++) {
        d=dequeue(&Q);
        printf("Arrival Time: %f, Departure Time: %f\n", d.arrivalTime, d.departureTime);
    }
    freeQueue(&Q);
}

void p2(void)
{
 
    printf("\n");
    printf("Simulated for 10000000s with Arrival Rate of 1 packets/sec and Service Rate of 10 packets/sec:\n");
    printf("Sojourn time is %f seconds\n",runSimulation(1,0.1,10000000));
    printf("\n");
    
    printf("Simulated for 10000000s with Arrival Rate of 5 packets/sec and Service Rate of 10 packets/sec:\n");
    printf("Sojourn time is %f seconds\n",runSimulation(5,0.1,10000000));
    printf("\n");
    
    printf("Simulated for 10000000s with Arrival Rate of 7 packets/sec and Service Rate of 10 packets/sec:\n");
    printf("Sojourn time is %f seconds\n",runSimulation(7,0.1,10000000));
    printf("\n");
    
    printf("Simulated for 10000000s with Arrival Rate of 9 packets/sec and Service Rate of 10 packets/sec:\n");
    printf("Sojourn time is %f seconds\n",runSimulation(9,0.1,10000000));
    printf("\n");
    
    printf("Simulated for 10000000s with Arrival Rate of 10 packets/sec and Service Rate of 10 packets/sec:\n");
    printf("Sojourn time is %f seconds\n",runSimulation(10,0.1,10000000));
    printf("\n");
}

int main( int argc, char *argv[] ){
    srand(1);
    if( argc < 2 ){
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2){
        if(atoi(argv[1])==1){
            p1();
        }
        else if(atoi(argv[1])==2){
            p2();
        }

        else{
            printf("Incorrect argument supplied.\n");
        }
    }
    else
    {
        printf("Expecting only one argument\n");
    }
}

