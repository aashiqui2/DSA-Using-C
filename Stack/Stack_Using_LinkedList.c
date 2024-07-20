#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *top = NULL;
void push(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto stack\n", val);
}
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    node *temp = top;
    int val = temp->data;
    top = temp->next;
    free(temp);
    return val;
}
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}
int isEmpty()
{
    return top == NULL;
}
int count()
{
    int count = 0;
    node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void change(int pos, int val)
{
    if (pos < 0)
    {
        printf("Invalid position\n");
        return;
    }
    node *temp = top;
    for (int i = 0; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->data = val;
        printf("Changed element at position %d to %d\n", pos, val);
    }
    else
    {
        printf("Invalid position\n");
    }
}
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("\nStack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Count\n");
        printf("7. Change\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
            {
                printf("Popped %d from stack\n", val);
            }
            break;
        // case 3:
        //     val = peek();
        //     if (val != -1)
        //     {
        //         printf("Top element is %d\n", val);
        //     }
        //     break;
        case 4:
            display();
            break;
        // case 5:
        //     if (isEmpty())
        //     {
        //         printf("Stack is empty\n");
        //     }
        //     else
        //     {
        //         printf("Stack is not empty\n");
        //     }
        //     break;
        // case 6:
        //     printf("Number of elements in stack: %d\n", count());
        //     break;
        // case 7:
        //     printf("Enter position and new value: ");
        //     scanf("%d %d", &pos, &val);
        //     change(pos, val);
        //     break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}