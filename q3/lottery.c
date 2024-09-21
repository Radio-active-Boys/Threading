#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define LOTTERY_TICKETS 10

typedef struct {
    int id;
    int lotteryNumber;
} Process;

void generateLotteryNumbers(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].lotteryNumber = rand() % LOTTERY_TICKETS + 1;
    }
}

int selectWinner(Process processes[], int n) {
    int selectedNumber = rand() % LOTTERY_TICKETS + 1;
    printf("Selected Lottery Number: %d\n", selectedNumber);
    
    for (int i = 0; i < n; i++) {
        if (processes[i].lotteryNumber == selectedNumber) {
            return processes[i].id;
        }
    }
    return -1; 
}

int main() {
    srand(time(NULL));
    Process processes[MAX_PROCESSES];

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = i + 1;
    }

    generateLotteryNumbers(processes, MAX_PROCESSES);
    
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d has lottery number %d\n", processes[i].id, processes[i].lotteryNumber);
    }

    int winner = selectWinner(processes, MAX_PROCESSES);
    if (winner != -1) {
        printf("Winner Process: %d\n", winner);
    } else {
        printf("No winner selected.\n");
    }

    return 0;
}
