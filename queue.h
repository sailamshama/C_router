#include <stdio.h>
#include <stdlib.h>

struct Data{
	double arrivalTime;
	double departureTime;  
	
};

struct Node{
	struct Data data; 
	struct Node *next; 
};

struct Queue{
	int currSize; 
	struct Node *front; 
	struct Node *rear; 
};

struct Queue initQueue();
void enqueue(struct Queue *qPtr, struct Data d);
struct Data dequeue(struct Queue *qPtr);
void freeQueue(struct Queue *qPtr);

