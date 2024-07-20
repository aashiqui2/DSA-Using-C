#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

void insertAtBeginning(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory\n");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    printf("Inserted %d at the beginning\n", val);
}

void insertAtEnd(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory\n");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    printf("Inserted %d at the end\n", val);
}

void insertAtPos(int pos, int val)
{
    if (pos == 0)
    {
        insertAtBeginning(val);
        return;
    }

    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory\n");
        return;
    }
    newnode->data = val;

    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted %d at pos %d\n", val, pos);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    printf("Elements in the list are: ");
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data); // Print the last element
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    node *temp = head;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
    }
    free(temp);
    printf("Node deleted at beginning\n");
}

void delete_end()
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    node *temp = head;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        node *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Node deleted at end\n");
}

void deleteFromPos(int pos)
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    node *temp = head;
    if (pos == 0)
    {
        delete_begin();
        return;
    }
    node *prev;
    for (int i = 0; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == head)
        {
            printf("Invalid position\n");
            return;
        }
    }
    prev->next = temp->next;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

int search(int val)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    node *temp = head;
    int pos = 0;
    while (temp->next != head)
    {
        if (temp->data == val)
        {
            printf("Value %d found at position %d\n", val, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    if (temp->data == val) // Check the last element
    {
        printf("Value %d found at position %d\n", val, pos);
        return pos;
    }
    printf("Value %d not found in the list\n", val);
    return -1;
}

int length()
{
    if (head == NULL)
    {
        return 0;
    }

    int count = 0;
    node *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++; // Count the last element
    return count;
}

int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("\n --------Linked List Menu-----------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at specified position\n");
        printf("4. Display the list\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete from specified position\n");
        printf("8. Search for a value\n");
        printf("9. Get the length of the list\n");
        printf("10. Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &val);
            insertAtBeginning(val);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &val);
            insertAtEnd(val);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("Enter the data: ");
            scanf("%d", &val);
            insertAtPos(pos, val);
            break;
        case 4:
            display();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteFromPos(pos);
            break;
        case 8:
            printf("Enter the value to search for: ");
            scanf("%d", &val);
            search(val);
            break;
        case 9:
            printf("Length of the list is %d\n", length());
            break;
        case 10:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }

    return 0;
}
