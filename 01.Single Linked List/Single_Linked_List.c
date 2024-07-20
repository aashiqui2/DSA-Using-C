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
        printf("Out of Memory");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    printf("Inserted %d at the beginning", val);
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
        printf("Out of Memory");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {

        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("Inserted %d at pos %d", val, pos);
}
void insertAtEnd(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Out of Memory");
        return;
    }
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = NULL;
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
    }
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    node *temp = head;
    printf("Elements in the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void delete_begin()
{
    if (head == NULL) // if List is empty we return
    {
        printf("Linked List is empty | Nothing to delete \n");
        return;
    }
    else
    {
        head = head->next;
    }
    printf("Node Deleted at Begining \n");
}
void delete_end()
{
    if (head == NULL) // if List is empty we return
    {
        printf("Linked List is empty | Nothing to delete \n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        node *temp = head;
        node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    printf("Node Deleted at End \n");
}
void deleteFromPos(int pos)
{
    if (head == NULL) // if List is empty we return
    {
        printf("Linked List is empty | Nothing to delete \n");
        return;
    }
    node *temp = head;
    node *prev=NULL;
    if (pos == 0)
    {
        head = head->next;
        printf("Deleted %d", temp->data);
        free(temp);
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    prev->next = temp->next;
    printf("Deleted %d", temp->data);
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
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at specified position \n");
        printf("4.Display the list\n");
        printf("5.Delete at Beginning\n");
        printf("6.Delete at End\n");
        printf("7.Delete from specified position\n");
        printf("8.Search the element\n");
        printf("9.to Find the length\n");
        printf("10.Exit\n");
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
            printf("Enter the data to search: ");
            scanf("%d", &val);
            search(val);
            break;
        case 9:
            printf("Length of the list is %d\n", length());
            break;
        case 10:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }

    return 0;
}