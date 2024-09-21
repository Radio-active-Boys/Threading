#ifndef THREAD_H
#define THREAD_H

typedef struct {
    unsigned int id;
    double cpu_time;
    double arrival_time;
    unsigned priority;
    double remaining_time;
} Thread;


double total_cpu_time(Thread arr[], int n);
void sort_arrival_time(Thread arr[], int n);
void sort_priority(Thread arr[], int n);
void thread_fcfs(Thread arr[], int n);
void thread_sjf(Thread arr[], int n);
void thread_priority_scheduling(Thread arr[], int n);
void thread_rr(Thread arr[], int n, double TimeQuantum);

#endif
