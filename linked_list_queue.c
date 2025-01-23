#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void intialiseQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, int newdata)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newdata;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Eroor: No element dequeue from an empty queue");
        return -1;
    }
    int dequeuedata = queue->front->data;
    Node *temp = queue->front;
    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }
    free(temp);
    return dequeuedata;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Eroor: No element dequeue from an empty queue");
        return -1;
    }
    return queue->front->data;
}

void displayqueue(Queue *queue)
{
    Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(Queue *queue)
{
    while (queue->front != NULL)
    {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}
int main()
{
    Queue myQueue;
    intialiseQueue(&myQueue);

    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Show Front Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                break;
            case 2:
                value = dequeue(&myQueue);
                if (value != -1) 
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                printf("Queue elements:\n");
                displayqueue(&myQueue);
                break;
            case 4:
                value = front(&myQueue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freeQueue(&myQueue);

    return 0;
}