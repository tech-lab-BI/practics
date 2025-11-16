#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack[max];
int top1=-1, top2=max;

//left side use operation
int isFull1() {
    if (top1+1 == top2) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty1() {
    if (top1 == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
void push1(int data) {
    if (isFull1()) {
        printf("Stack Overflow\n");
    }
    else {
        stack[++top1] = data;
        printf("Element %d pushed at left side\n", data);
    }
}
int pop1() {
    if (isEmpty1()) {
        printf("Stack Underflow\n");
        return -999;
    }
    else {
        return stack[top1--];
    }
}
int peek1() {
    if (isEmpty1()) {
        printf("Stack is empty\n");
        return -999;
    }
    else {
        return stack[top1];
    }
}
void display1() {
    if (isEmpty1()) {
        printf("Stack is empty\n");
    }
    else {
        int i;
        printf("Stack elements: ");
        for (i = 0; i <= top1; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

//right side use operation
int isFull2() {
    if (top2-1 == top1) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty2() {
    if (top2 == max) {
        return 1;
    }
    else {
        return 0;
    }
}
void push2(int data) {
    if (isFull2()) {
        printf("Stack Overflow\n");
    }
    else {
        stack[--top2] = data;
        printf("Element %d pushed at right side\n", data);
    }
}
int pop2() {
    if (isEmpty2()) {
        printf("Stack Underflow\n");
        return -999;
    }
    else {
        return stack[top2++];
    }
}
int peek2() {
    if (isEmpty2()) {
        printf("Stack is empty\n");
        return -999;
    }
    else {
        return stack[top2];
    }
}
void display2() {
    if (isEmpty2()) {
        printf("Stack is empty\n");
    }
    else {
        int i;
        printf("Stack elements: ");
        for (i = max-1; i >= top2; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void display(){
	int i;
	for(i=0;i<max;i++){
		printf("%d ",stack[i]);
	}
}
int chooseOperation(){
	int ch,s;
	printf("\n========== STACK OPERATIONS ==========\n");
	printf("1. Stack-1 \t 2. Stack-2 \t 3. Array element \n Choose stack : ");
	scanf("%d",&s);
	if(s==3) { // check whole array
    	display();
    	s = chooseOperation();
    }
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    
    if(s==1 && ch!=5)	ch+=10;
    else if(s==2 && ch!=5)	ch+=20;
    
    return ch;
}
int main() {
    int ch, data, result;
    
    while(1) {
        ch = chooseOperation();
        switch(ch) {
            case 11:
                printf("Enter value to push: ");
                scanf("%d", &data);
                push1(data);
                break;

            case 12:
                result = pop1();
                if (result != -999) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 13:
                result = peek1();
                if (result != -999) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 14:
                display1();
                break;
                
            case 21:
                printf("Enter value to push: ");
                scanf("%d", &data);
                push2(data);
                break;

            case 22:
                result = pop2();
                if (result != -999) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 23:
                result = peek2();
                if (result != -999) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 24:
                display2();
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
    return 0;
}
