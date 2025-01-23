#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node *insertAtBeginning(node *head, int newData)
{
    node *newNode = createNode(newData);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

node *insertAtEnd(node *head, int newData)
{
    node *newNode = createNode(newData);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

node *deleteFromBeginning(node *head)
{
    if (head == NULL)
    {
        printf("Cannot delete from an empty doubly linked list.\n");
        return head;
    }

    node *temp = head;

    if (head->next != NULL)
    {
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        head = NULL;
    }

    free(temp);

    return head;
}

node *deleteFromEnd(node *head)
{
    if (head == NULL)
    {
        printf("Cannot delete from an empty doubly linked list.\n");
        return head;
    }

    node *temp = head;

    if (head->next != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    free(temp);

    return head;
}

void displayList(node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(node *head)
{
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    node *head = NULL;
    int choice, data;

    do
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 3:
            head = deleteFromBeginning(head);
            printf("Deleted from beginning.\n");
            break;
        case 4:
            head = deleteFromEnd(head);
            printf("Deleted from end.\n");
            break;
        case 5:
            printf("Doubly Linked List: ");
            displayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    freeList(head);
    return 0;
}
