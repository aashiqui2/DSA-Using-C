//! Open Addressing (chaining)
#include <stdio.h>
#include <stdlib.h>

#define size 7

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *arr[size];

void init()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = NULL;
    }
}

node *createNode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void insert(int value)
{
    int key = value % size;
    node *newnode = createNode(value);

    if (arr[key] == NULL)
    {
        arr[key] = newnode;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        node *temp = arr[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        printf("Collision: %d inserted at arr[%d] in the linked list\n", value, key);
    }
}
void print()
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] -> ", i);
        node *temp = arr[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void search(int value)
{
    int key = value % size;
    node *temp = arr[key];
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Search Found: %d at arr[%d]\n", value, key);
            return;
        }
        temp = temp->next;
    }
    printf("Search Not Found for %d\n", value);
}

void del(int value)
{
    int key = value % size;
    node *temp = arr[key]; // a[3]=52
    node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            {
                arr[key] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d deleted from arr[%d]\n", value, key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not present in the hash table\n", value);
}

int main()
{
    // Key (24,52,91,67,48,83)

    init();
    insert(24);
    insert(52);
    insert(91);
    insert(67);
    insert(48);
    insert(83);

    printf("Hash table\n");
    print();
    printf("\n");

    printf("Searching value 4..\n");
    search(4);
    printf("Searching value 4..\n");
    search(91);

    printf("Deleting value 10..\n");
    del(52);
    printf("After the deletion hash table\n");
    print();

    return 0;
}