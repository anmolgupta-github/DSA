#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int arr[100];
    int size;
} heap;

void insertheap(heap *h, int value)
{
    h->size += 1;
    h->arr[h->size] = value;
    int i = h->size;

    while (i > 1)
    {
        if (h->arr[i] > h->arr[i / 2])
        {
            int temp = h->arr[i];
            h->arr[i] = h->arr[i / 2];
            h->arr[i / 2] = temp;
            i = i / 2;
        }
        else
        {
            return;
        }
    }
}
void heapify(heap *h, int i)
{
    int largest = i;
    int left = 2 * i; 
    int right = (2 * i) + 1;

    if (left <= h->size && h->arr[largest] < h->arr[left])
    {

        largest = left;
    }
    if (right <= h->size && h->arr[largest] < h->arr[right])
    {

        largest = right;
    }
    if (largest != i)
    {
        int tmp = h->arr[i];
        h->arr[i] = h->arr[largest];
        h->arr[largest] = tmp;
        heapify(h, largest);
    }
}
int deleteFromHeap(heap *h)
{
    if (h->size == 0)
    {
        printf("Heap is empty, cannot delete.\n");
        return -1;
    }

    int deletedNum = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size -= 1;

    heapify(h, 1);
    return deletedNum;
}

void print(heap *h)
{
    if (h->size == 0)
    {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 1; i <= h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main()
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->arr[0] = -1;
    h->size = 0;

    int choice, value;

    do
    {
        printf("\nHeap Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete Max\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertheap(h, value);
            break;
        case 2:
            value = deleteFromHeap(h);
            if (value != -1)
            {
                printf("Deleted max element: %d\n", value);
            }
            break;
        case 3:
            print(h);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(h);
    return 0;
}