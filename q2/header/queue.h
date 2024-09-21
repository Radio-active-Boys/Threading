#ifndef QUEUE_H
#define QUEUE_H

#include "thread.h"   
#include <stdbool.h>  
typedef struct Node 
{
    Thread thread;          
    struct Node* next;      
    struct Node* prev;     
} Node;

typedef struct Deque 
{
    Node* front;            
    Node* rear;            
} Deque;

Deque* createDeque();
void push_front(Deque* deque, Thread t);
void push_back(Deque* deque, Thread t);
Thread pop_front(Deque* deque);
Thread pop_back(Deque* deque);
bool is_empty(Deque* deque); 
void deleteDeque(Deque* deque);
bool in_deque(Deque* deque, unsigned int thread_id);
int deque_size(Deque* deque);

#endif
