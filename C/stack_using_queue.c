#include<stdio.h>
#include<stdlib.h>
#define capacity 3

int quene[capacity], queneHelp[capacity]; //backend
int front=-1, rear=-1, frontHelp=-1, rearHelp=-1;
int isempty(){
	if(rear == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(){
	if(rear == (capacity-1)){
		return 1;
	}
	else{
		return 0;
	}
}
void enquene(int x){
	if(isempty())
		front = 0;
	quene[++rear] = x;
}
int dequene(){
	int tem = quene[front];
	if(front==rear)	front=-1;
	else{
		int i;
		for(i=front;i<rear;i++){
			quene[i] = quene[i+1];
		}
	}
	rear--;
	return tem;
}
int peekQ(){
	return quene[rear];
}
void displayQ(){
	int i;
	printf("Queue element : ");
	for(i=front;i<=rear;i++){
		printf("%d  ",quene[i]);
	}
}

int isemptyHelp(){
	if(rearHelp == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfullHelp(){
	if(rearHelp == (capacity-1)){
		return 1;
	}
	else{
		return 0;
	}
}
void enqueneHelp(int x){
	if(isemptyHelp())
		frontHelp = 0;
	queneHelp[++rearHelp] = x;
}
int dequeneHelp(){
	int tem = queneHelp[frontHelp];
	if(frontHelp==rearHelp)	frontHelp=-1;
	else{
		int i;
		for(i=frontHelp;i<rearHelp;i++){
			queneHelp[i] = queneHelp[i+1];
		}
	}
	rearHelp--;
	return tem;
}

//int stack[max]; //frontend
//int top = -1;
int isFull() {
    if (isfull()) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty() {
    if (isempty()) {
        return 1;
    }
    else {
        return 0;
    }
}
void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
    }
    else {
        enquene(data);
        printf("Element %d pushed to stack\n", data);
    }
}
int pop() {
	int tem=-999;
    if (isEmpty()) {
        printf("Stack Underflow\n");
    }
    else {
        int i=front;
        while(i!=rear){
        	enqueneHelp(dequene());
		}
		tem = dequene();
		i = frontHelp;
		while(i!=rearHelp){
			enquene(dequeneHelp());
		}
    }
    return tem;
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -999;
    }
    else {
        return peekQ();
    }
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
    else {
        displayQ();
        printf("(top)");
    }
}

int main() {
    int ch, data, result;
    
    while(1) {
        printf("\n========== STACK OPERATIONS ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &data);
                push(data);
                break;
                
            case 2:
                result = pop();
                if (result != -999) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 3:
                result = peek();
                if (result != -999) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 4:
                display();
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
