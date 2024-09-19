#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};


struct Node *front = NULL;
struct Node *rear = NULL;


void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d to queue\n", val);
}


int dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node *temp = front;
    int val = front->data;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return val;
}


int peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}


int isEmpty()
{
    return front == NULL;
}


void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
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
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val != -1)
            {
                printf("Dequeued %d from queue\n", val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("Front element is %d\n", val);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
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
