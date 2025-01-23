#include<stdio.h>
#include<stdlib.h>
 typedef struct Node{
    int data;
    struct Node*next;
 }Node;

 typedef struct {
    Node *top;
 }Stack;

 void initialiseStack(Stack *stack)
 {
    stack->top = NULL;
 }
 int isEmpty(Stack *stack)
 {
    return stack->top == NULL;
 }

 void push(Stack *stack , int newData)
 {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=newData;
    newNode->next = stack->top;
    stack->top = newNode;
 }

 int pop(Stack *stack)
 {
    if(isEmpty(stack))
    {
        printf("Error");
        return -1;
    }
     int poppedData = stack->top->data;
     Node *temp = stack->top;
     stack->top = stack->top->next;
     free(temp);
     return poppedData;
 }

 int peek(Stack *stack)
 {
    if(isEmpty(stack))
    {
        printf("Error");
        return -1;
    }
    return stack->top->data;
 }

 void display(Stack *stack)
 {
    Node*current = stack->top;
    if(isEmpty(stack))
    {
        printf("Error:Stack is EMpty");
    }
        printf("Stack elements:\n");
        while(current!=NULL)
        {
        printf("%d", current->data);
        current = current->next;
        }
        printf("\n");
 }
    void freestack(Stack *stack)
    {
        while(stack->top!=NULL)
        {
            Node*temp = stack->top;
            stack->top = stack->top->next;
            free(temp);
        }
    }

 int main()
 {
    Stack mystack;
    initialiseStack(&mystack);
    int choice,value;
    do{
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

      switch(choice)
      {
        case 1 : 
        printf("Enter the value to be inserted:");
        scanf("%d",&value);
        push(&mystack,value);
        break;

        case 2: 
        value = pop(&mystack);
        if(value!=-1)
        printf("Popped elements:%d\n",value);
        break;

        case 3: 
        value = peek(&mystack);
        if(value!=-1)
        printf("Top elements:%d\n",value);
        break;

        case 4:
        display(&mystack);
        break;

        case 5:
        printf("Exiting.....");
        break;

        default:
        printf("Invalid choice");
      }
    }
    while(choice !=5);
    freestack(&mystack);
    return 0;
 }
