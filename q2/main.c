#include "thread.h"
#include <stdio.h>

int main(int args, char *argv[]) {
    Thread threads[] = {
        {1, 5.0, 2.0, 3}, {2, 4.0, 1.0, 1}, {3, 6.0, 3.0, 2}, {4, 5.0, 2.0, 3},
        {5, 3.0, 1.0, 1}, {6, 10.0, 3.0, 2}, {7, 2.5, 4.0, 4}, {8, 7.5, 4.5, 5},
        {9, 1.5, 2.5, 1}, {10, 9.0, 2.5, 2}, {11, 2.0, 5.0, 3}, {12, 8.5, 1.5, 5},
        {13, 6.5, 1.5, 2}, {14, 3.5, 2.0, 1}, {15, 1.0, 3.5, 4}, {16, 7.0, 4.0, 5},
        {17, 5.5, 2.0, 3}, {18, 4.5, 3.0, 2}, {19, 6.0, 3.0, 3}, {20, 2.0, 4.0, 1}
    };

    int n = sizeof(threads) / sizeof(threads[0]);

    // printf("FCFS Algo\n");
    // thread_fcfs(threads, n);
    // printf("sjf Algo\n");
    // thread_sjf(threads, n);
    // printf("\nPriority Algo\n");
    // thread_priority_scheduling(threads, n);
    double timeQuantum = 2.0;
    printf("RR Algo Time Quantum : %0.2f\n",timeQuantum);
    thread_rr(threads, n, timeQuantum);

    return 0;
}
