#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define TIME_QUANTUM_1 2 // Time quantum for high priority queue
#define TIME_QUANTUM_2 4 // Time quantum for low priority queue

typedef struct {
    int id;
    int burstTime;
    int remainingTime;
    int queueLevel; // 0 for high priority, 1 for low priority
} Process;

void initializeProcesses(Process processes[]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = i + 1;
        processes[i].burstTime = rand() % 10 + 1; // Random burst time between 1 and 10
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].queueLevel = 0; // Start in high priority queue
    }
}

void scheduleProcesses(Process processes[]) {
    int allDone = 0;
    
    while (!allDone) {
        allDone = 1; // Assume all are done until proven otherwise
        
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].remainingTime > 0) {
                allDone = 0; // There is at least one process not finished
                
                int timeQuantum = (processes[i].queueLevel == 0) ? TIME_QUANTUM_1 : TIME_QUANTUM_2;
                int timeSpent = (processes[i].remainingTime < timeQuantum) ? processes[i].remainingTime : timeQuantum;
                
                processes[i].remainingTime -= timeSpent;
                printf("Process %d executed for %d units. Remaining time: %d\n", processes[i].id, timeSpent, processes[i].remainingTime);
                
                if (processes[i].remainingTime == 0) {
                    printf("Process %d finished.\n", processes[i].id);
                } else if (processes[i].queueLevel == 0) {
                    processes[i].queueLevel = 1; // Move to low priority queue after first execution
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Process processes[MAX_PROCESSES];

    initializeProcesses(processes);
    
    printf("Process Details:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d - Burst Time: %d\n", processes[i].id, processes[i].burstTime);
    }

    scheduleProcesses(processes);

    return 0;
}
