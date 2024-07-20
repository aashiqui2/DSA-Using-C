#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
    printf("Pushed %d onto stack\n", val);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

int count() {
    return top + 1;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void change(int pos, int val) {
    if (pos < 0 || pos > top) {
        printf("Invalid position\n");
        return;
    }
    stack[pos] = val;
    printf("Changed element at position %d to %d\n", pos, val);
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\nStack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Count\n");
        printf("8. Change\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1) {
                    printf("Popped %d from stack\n", val);
                }
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("Top element is %d\n", val);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                if (isFull()) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 7:
                printf("Number of elements in stack: %d\n", count());
                break;
            case 8:
                printf("Enter position and new value: ");
                scanf("%d %d", &pos, &val);
                change(pos, val);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
