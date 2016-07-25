#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "queue.h"

typedef enum {ARRIVAL, DEPARTURE} Event;

struct Simulation{
    double currTime;
    double arrivalRate;
    double serviceTime;
    double timeForNextArrival;
    double timeForNextDeparture;
    double totalSimTime;
    struct Queue buffer, eventQueue;
    Event e;
};

double runSimulation(double arrivalRate, double serviceTime, double simTime);
struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime);
double getRandTime(double arrivalRate);
double calcAverageWaitingTime(struct Simulation * S);
