#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int value;
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter temperature reading: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Removed %d\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
