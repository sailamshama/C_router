#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S){
	double averageWaitingTime = 0; 
	struct Node * queuePtr = S->eventQueue.front; 
	while(queuePtr!=NULL){
		averageWaitingTime +=((queuePtr->data.departureTime) - (queuePtr->data.arrivalTime)); 
		queuePtr = queuePtr->next; 
	}
	averageWaitingTime= averageWaitingTime/S->eventQueue.currSize; 
;
	freeQueue(&(S->eventQueue));
	freeQueue(&(S->buffer));
	return averageWaitingTime; 
}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime){
	struct Simulation S; 
	S.currTime = 0; 
	S.arrivalRate = arrivalRate; 
	S.serviceTime = serviceTime; 
	S.timeForNextArrival = getRandTime(arrivalRate);
	S.timeForNextDeparture = serviceTime + S.timeForNextArrival; 
	S.totalSimTime = simTime; 
	S.buffer = initQueue(); 
	S.eventQueue = initQueue(); 
	S.e = ARRIVAL;
	return S;  
}

double runSimulation(double arrivalRate, double serviceTime, double simTime){
	struct Simulation S = initSimulation(arrivalRate, serviceTime, simTime); 
	while(S.currTime <= S.totalSimTime){

		if (S.e == ARRIVAL){
			//update packet logistics
			S.currTime = S.timeForNextArrival; 
			struct Data packet; 
			packet.arrivalTime = S.timeForNextArrival; 
			//enqueue in buffer
			enqueue(&(S.buffer), packet);
			//update simulation logistisc
			S.timeForNextArrival = S.currTime + getRandTime(S.arrivalRate);
		}
		else {
			//if (S.timeForNextDeparture == -1) S.timeForNextDeparture = serviceTime + S.timeForNextArrival;
			//update packet logistics

				S.currTime = S.timeForNextDeparture;  
				//dequeue from buffer and push into eventQueue
				struct Data dequeued_packet = dequeue(&S.buffer);//
				dequeued_packet.departureTime = S.currTime; 
				enqueue(&(S.eventQueue), dequeued_packet);
				if ((S.buffer).currSize>0){
					S.timeForNextDeparture=S.currTime+serviceTime;
				}
				else{
					S.timeForNextDeparture = S.timeForNextArrival+serviceTime;
				}
					
		}
		if (S.timeForNextArrival < S.timeForNextDeparture) S.e = ARRIVAL;		
		else S.e = DEPARTURE; 
	}
	//calculate average waiting time
	double averageWaitingTime = calcAverageWaitingTime(&S);
	return averageWaitingTime;
}



