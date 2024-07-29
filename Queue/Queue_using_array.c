#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = val;
    printf("Enqueued %d to queue\n", val);
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return val;
}

int peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

int count() {
    if (isEmpty()) {
        return 0;
    }
    return rear - front + 1;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void change(int pos, int val) {
    if (isEmpty() || pos < 0 || pos >= count()) {
        printf("Invalid position\n");
        return;
    }
    queue[front + pos] = val;
    printf("Changed element at position %d to %d\n", pos, val);
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if (val != -1) {
                    printf("Dequeued %d from queue\n", val);
                }
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("Front element is %d\n", val);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                if (isFull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 7:
                printf("Number of elements in queue: %d\n", count());
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
