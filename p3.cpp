#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("ADC Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("ADC Queue Underflow occurred!\n");
        return -1;
    }

    return queue[front++];
}

int main() {
    int value;

    printf("Enter 10 ADC sample values:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("\nRemoving every 2nd ADC sample:\n");
    while (front <= rear) {
        dequeue();   // skip one
        value = dequeue();
        if (value != -1)
            printf("Removed ADC sample: %d\n", value);
    }

    printf("\nExtra removal to show underflow:\n");
    dequeue();

    return 0;
}
