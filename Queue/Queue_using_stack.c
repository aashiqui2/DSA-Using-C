#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct Stack
{
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

int isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isStackFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

void push(Stack *stack, int val)
{
    if (isStackFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = val;
}

int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Queue using two stacks
typedef struct Queue
{
    Stack stack1;
    Stack stack2;
} Queue;

void initQueue(Queue *queue)
{
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(Queue *queue, int val)
{
    push(&queue->stack1, val);
    printf("Enqueued %d to queue\n", val);
}

int dequeue(Queue *queue)
{
    if (isStackEmpty(&queue->stack2))
    {
        while (!isStackEmpty(&queue->stack1))
        {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return pop(&queue->stack2);
}

int peekQueue(Queue *queue)
{
    if (isStackEmpty(&queue->stack2))
    {
        while (!isStackEmpty(&queue->stack1))
        {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return peek(&queue->stack2);
}

int isQueueEmpty(Queue *queue)
{
    return isStackEmpty(&queue->stack1) && isStackEmpty(&queue->stack2);
}

void displayQueue(Queue *queue)
{
    Stack tempStack1 = queue->stack1;
    Stack tempStack2 = queue->stack2;

    if (isQueueEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    while (!isStackEmpty(&tempStack2))
    {
        printf("%d ", pop(&tempStack2));
    }

    while (!isStackEmpty(&tempStack1))
    {
        push(&tempStack2, pop(&tempStack1));
    }

    while (!isStackEmpty(&tempStack2))
    {
        int val = pop(&tempStack2);
        printf("%d ", val);
        push(&queue->stack2, val);
    }

    printf("\n");
}

int main()
{
    Queue queue;
    initQueue(&queue);

    int choice, val;
    while (1)
    {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(&queue, val);
            break;
        case 2:
            val = dequeue(&queue);
            if (val != -1)
            {
                printf("Dequeued %d from queue\n", val);
            }
            break;
        case 3:
            val = peekQueue(&queue);
            if (val != -1)
            {
                printf("Front element is %d\n", val);
            }
            break;
        case 4:
            displayQueue(&queue);
            break;
        case 5:
            if (isQueueEmpty(&queue))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
