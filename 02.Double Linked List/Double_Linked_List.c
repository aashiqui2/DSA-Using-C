#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    newnode->prev = NULL; // New node's previous pointer is NULL

    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode; // Set the current head's previous pointer to the new node
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
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
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
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;

    printf("Inserted %d at pos %d\n", val, pos);
}

void displayFromFirst()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    printf("Elements in the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displayFromLast()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Elements in the list from end are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
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
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    free(temp);
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
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        printf("Deleted %d\n", temp->data);
        free(temp);
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    printf("Deleted %d\n", temp->data);
    free(temp);
}

void search(int val)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            printf("Value %d found at position %d\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list\n", val);
}

int length()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
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
        printf("4. Display the list from beginning\n");
        printf("5. Display the list from last\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete from specified position\n");
        printf("9. Search for a value\n");
        printf("10. Get the length of the list\n");
        printf("11. Exit\n");
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
            displayFromFirst();
            break;
        case 5:
            displayFromLast();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteFromPos(pos);
            break;
        case 9:
            printf("Enter the value to search for: ");
            scanf("%d", &val);
            search(val);
            break;
        case 10:
            printf("Length of the list is %d\n", length());
            break;
        case 11:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }

    return 0;
}
