#include <stdio.h>
#define MAX 5

// Linear Queue structure
struct lqueue {
    int billAmount[MAX];
    int front;
    int rear;
};

typedef struct lqueue LQ;

// Enqueue function (Add bill amount)
void Enqueue(LQ *q) {
    int amount;

    if (q->rear == MAX - 1) {
        printf("Queue is full. Cannot add new bill.\n");
    } else {
        printf("Enter bill amount: ");
        scanf("%d", &amount);

        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->billAmount[q->rear] = amount;
        printf("Bill added successfully.\n");
    }
}

// Dequeue function (Process bill)
void Dequeue(LQ *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty. No bill to process.\n");
    } else {
        printf("Processed bill amount: %d\n", q->billAmount[q->front]);
        q->front++;
    }
}

// Display function
void Display(LQ *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Pending Bills: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->billAmount[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    LQ q;
    q.front = -1;
    q.rear = -1;

    int choice;

    printf("Pharmacy Bill Management System (Linear Queue)\n");

    while (1) {
        printf("\n1. Add Bill\n2. Process Bill\n3. Display Bills\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Enqueue(&q);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                Display(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
