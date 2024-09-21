#include "thread.h"
#include <stdio.h>
#include "queue.h"

double Timer = 0.0;

double total_cpu_time(Thread arr[], int n) 
{
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].cpu_time;
    }
    return sum;
}

void sort_arrival_time(Thread arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].arrival_time > arr[j].arrival_time) 
            {
                Thread temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void sort_priority(Thread arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i].priority < arr[j].priority) 
            {
                Thread temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void thread_fcfs(Thread arr[], int n) 
{
    sort_arrival_time(arr, n);
    for (int i = 0; i < n; i++) 
    {
        printf("Thread ID: %u | Arrival Time: %.2f | CPU Time: %.2f | Priority: %u\n",arr[i].id, arr[i].arrival_time, arr[i].cpu_time, arr[i].priority);
    }
}

void thread_sjf(Thread arr[], int n) 
{
    double total_BT = total_cpu_time(arr, n);
    sort_arrival_time(arr, n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (Timer <= total_BT && arr[j].arrival_time < Timer && arr[i].cpu_time > arr[j].cpu_time) 
            {
                Thread temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        Timer += arr[i].cpu_time;
        printf("Thread ID: %u | Arrival Time: %.2f | CPU Time: %.2f | Priority: %u\n",arr[i].id, arr[i].arrival_time, arr[i].cpu_time, arr[i].priority);
    }
    printf("\nTotal CPU time: %.2f", total_BT);
}

void thread_priority_scheduling(Thread arr[], int n) 
{
    unsigned total_BT = total_cpu_time(arr, n);
    sort_arrival_time(arr, n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (Timer <= total_BT && arr[j].arrival_time < Timer && arr[i].priority < arr[j].priority) 
            {
                Thread temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        Timer += arr[i].cpu_time;
        printf("Thread ID: %u | Arrival Time: %.2f | CPU Time: %.2f | Priority: %u\n",arr[i].id, arr[i].arrival_time, arr[i].cpu_time, arr[i].priority);
    }
}

void thread_rr(Thread arr[], int n, double TimeQuantum) 
{
    Deque* readyQueue = createDeque();
    Deque* completeQueue = createDeque();
    double Timer = 0.0;
    int i = 0;

    while (i < n || !is_empty(readyQueue)) 
    {
        while (i < n && arr[i].arrival_time <= Timer) 
        {
            push_back(readyQueue, arr[i]);
            i++;
        }

        if (is_empty(readyQueue)) 
        {
            if (i < n) {
                Timer = arr[i].arrival_time;
                continue;
            }
            break;
        }

        Thread t = pop_front(readyQueue);

        if (t.remaining_time > TimeQuantum) 
        {
            Timer += TimeQuantum;
            t.remaining_time -= TimeQuantum;
            push_back(readyQueue, t);
        } 
        else 
        {
            Timer += t.remaining_time;
            t.remaining_time = 0;
            push_back(completeQueue, t);
            printf("Thread ID: %u | Completed at time: %.2f\n", t.id, Timer);
        }
    }

    deleteDeque(readyQueue);
    deleteDeque(completeQueue);
}
