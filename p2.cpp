#include <stdio.h>
#define SIZE 5

char queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    char ch;
    if (rear == SIZE - 1) {
        printf("UART Buffer Overflow!\n");
        return;
    }

    printf("Enter received character: ");
    scanf(" %c", &ch);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = ch;
    printf("Character '%c' stored\n", ch);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("UART Buffer Underflow!\n");
        return;
    }

    printf("Transmitted character: %c\n", queue[front]);
    front++;
}

int main() {
    int choice;

    do {
        printf("\n1.Receive Character\n2.Transmit Character\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
