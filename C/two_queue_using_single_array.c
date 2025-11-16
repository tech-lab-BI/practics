#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int Queue[MAX];
int F1=-1, R1=-1, F2=MAX, R2=MAX;

// left queue
int isFull1() {
    if (R1+1 == R2)
        return 1;
    else
        return 0;
}
int isEmpty1() {
    if (F1 == -1)
        return 1;
    else
        return 0;
}
void enqueue1(int data) {
    if (isFull1()) {
        printf("Queue Overflow\n");
        return;
    }
    if (F1 == -1) {
        F1 = 0;
    }
    R1++;
    Queue[R1] = data;
    printf("Enqueued %d to queue\n", data);
}
int dequeue1() {
    if (isEmpty1()) {
        printf("Queue Underflow\n");
        return -9999;
    }
    int data = Queue[F1];
    F1++;
    // Reset queue when empty
    if (F1 > R1) {
        F1 = R1 = -1;
    }
    return data;
}
int peek1() {
    if (isEmpty1()) {
        printf("Queue is empty\n");
        return -9999;
    }
    return Queue[F1];
}
void display1() {
    if (isEmpty1()) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue elements (front to rear): ");
    for (i = F1; i <= R1; i++) {
        printf("%d ", Queue[i]);
    }
    printf("\nFront = %d, Rear = %d\n", F1, R1);
}

// right queue
int isFull2() {
    if (R2-1 == R1)
        return 1;
    else
        return 0;
}
int isEmpty2() {
    if (F2 == MAX)
        return 1;
    else
        return 0;
}
void enqueue2(int data) {
    if (isFull2()) {
        printf("Queue Overflow\n");
        return;
    }
    if (F2 == MAX) {
        F2 = MAX-1;
    }
    R2--;
    Queue[R2] = data;
    printf("Enqueued %d to queue\n", data);
}
int dequeue2() {
    if (isEmpty2()) {
        printf("Queue Underflow\n");
        return -9999;
    }
    int data = Queue[F2];
    F2--;
    // Reset queue when empty
    if (F2 < R2) {
        F2 = R2 = MAX;
    }
    return data;
}
int peek2() {
    if (isEmpty2()) {
        printf("Queue is empty\n");
        return -9999;
    }
    return Queue[F2];
}
void display2() {
    if (isEmpty2()) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue elements (front to rear): ");
    for (i = F2; i >= R2; i--) {
        printf("%d ", Queue[i]);
    }
    printf("\nFront = %d, Rear = %d\n", F2, R2);
}

int chooseOperation(){
	int q,ch;
	printf("Choose queue 1.left\t2right \n Your chioce : ");
	scanf("%d",&q);
	printf("\n--- Queue Menu ---\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
    scanf("%d", &ch);
    
    if(q==1 && ch!=5)	ch+=10;
    else if(q==2 && ch!=5)	ch+=20;
    
    return ch;
}
int main() {
    int choice, data;
    
    while (1) {
    	choice = chooseOperation();
        printf("\n------------------------------------------------\n");
        
        switch (choice) {
            case 11:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue1(data);
                break;
            case 12:
                data = dequeue1();
                if (data != -9999) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 13:
                data = peek1();
                if (data != -9999) {
                    printf("Front element: %d\n", data);
                }
                break;
            case 14:
                display1();
                break;
            case 21:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue2(data);
                break;
            case 22:
                data = dequeue2();
                if (data != -9999) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 23:
                data = peek2();
                if (data != -9999) {
                    printf("Front element: %d\n", data);
                }
                break;
            case 24:
                display2();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n------------------------------------------------\n");
    }
    
    return 0;
}
