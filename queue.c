#include "queue.h"


struct Queue initQueue(){
	struct Queue new_queue; 
	new_queue.currSize = 0; 
	new_queue.front = NULL;
	new_queue.rear = NULL; 
	return new_queue; 
}

void enqueue(struct Queue *qPtr, struct Data d){
	struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = d; 
	new_node->next = NULL;
	if (qPtr->currSize ==0){ //
		qPtr->rear = new_node; 
		qPtr->front = new_node; 
	}
	else{
		qPtr->rear->next = new_node; 
		qPtr->rear = new_node; 
	}
	qPtr->currSize++;	
}
struct Data dequeue(struct Queue *qPtr){
	struct Node * temp = qPtr->front->next; 
	struct Data returnData = qPtr->front->data; 
	free(qPtr->front); 
	qPtr->front = temp;
	qPtr->currSize--; 
	if(qPtr->currSize == 0) qPtr->rear = NULL;
	return returnData; 
/*	struct Data d; 
	if(qPtr->currSize != 0){
		struct Node * old_front = qPtr->front;
		d = old_front->data; 
		qPtr->front = old_front->next;
		qPtr->currSize--;  
		free(old_front);  
	}
	return d; 
*/
}

void freeQueue(struct Queue *qPtr){
	while(qPtr->currSize >0){//qPtr->front != NULL){
		dequeue(qPtr);
	}	
}

