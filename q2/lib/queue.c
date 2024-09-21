#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <stdbool.h> 

Deque* createDeque() 
{
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

void push_front(Deque* deque, Thread t) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->thread = t;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if (deque->front == NULL) 
    {
        deque->rear = newNode;
    } else 
    {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

void push_back(Deque* deque, Thread t) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->thread = t;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (deque->rear == NULL) 
    {
        deque->front = newNode;
    } else 
    {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

Thread pop_front(Deque* deque) 
{
    if (is_empty(deque)) 
    {
        printf("Deque is empty! Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = deque->front;
    Thread t = temp->thread;

    deque->front = deque->front->next;
    if (deque->front == NULL) 
    {
        deque->rear = NULL;
    } else 
    {
        deque->front->prev = NULL;
    }

    free(temp);
    return t;
}

Thread pop_back(Deque* deque) 
{
    if (is_empty(deque)) 
    {
        printf("Deque is empty! Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = deque->rear;
    Thread t = temp->thread;

    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) 
    {
        deque->front = NULL;
    } else 
    {
        deque->rear->next = NULL;
    }

    free(temp);
    return t;
}

bool is_empty(Deque* deque) 
{
    return deque->front == NULL; 
}

void deleteDeque(Deque* deque) 
{
    while (!is_empty(deque)) 
    {
        pop_front(deque);
    }
    free(deque);
}

bool in_deque(Deque* deque, unsigned int thread_id) {
    Node* current = deque->front;
    while (current != NULL) {
        if (current->thread.id == thread_id) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int deque_size(Deque* deque) {
    int size = 0;
    Node* current = deque->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}
