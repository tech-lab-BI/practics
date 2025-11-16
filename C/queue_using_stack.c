#include <stdio.h>
#include <stdlib.h>
#define max 3

int stack[max],stackHelp[max];//backend
int top = -1,topHelp = -1;
int isFull() {
    if (top == max - 1) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty() {
    if (top == -1) {
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
        stack[++top] = data;
//        printf("Element %d pushed to stack\n", data);
    }
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -999;
    }
    else {
        return stack[top--];
    }
}
int peek_S() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -999;
    }
    else {
        return stack[top];
    }
}
void display_S() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
    else {
        int i;
//        printf("Stack elements: ");
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int isFullHelp() {
    if (topHelp == max - 1) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmptyHelp() {
    if (topHelp == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
void pushHelp(int data) {
    if (isFullHelp()) {
        printf("Stack Overflow\n");
    }
    else {
        stackHelp[++topHelp] = data;
//        printf("Element %d pushed to stackHelp\n", data);
    }
}
int popHelp() {
    if (isEmptyHelp()) {
        printf("Stack Underflow\n");
        return -999;
    }
    else {
        return stackHelp[topHelp--];
    }
}

//int quene[max];//frontend
//int f=-1,r=-1;
int isempty(){
	if(isEmpty()){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(){
	if(isFull()){
		return 1;
	}
	else{
		return 0;
	}
}
void enquene(int x){
	push(x);
}
int dequene(){
	while(top!=0){
		pushHelp(pop());
	}
	int tem = pop();
	while(topHelp!=-1){
		push(popHelp());
	}
	return tem;
}
int peek(){
	peek_S();
}
void display(){
	printf("Queue elements: ");
	display_S();
}

void main() {
    int ch,val;
	while(1){
		printf("\n+++++++++++++\n");
		printf("  :: MENU ::\n");
		printf("1. enquene\n");
		printf("2. dequene\n");
		printf("3. display\n");
		printf("4. peek\n");
		printf("5. exit\n");
		printf("Eneter choice :: ");
		scanf("%d",&ch);
		printf("\n+++++++++++++++\n");
		switch(ch){
			case 1:
				if(isfull()){
					printf("quene overflow. !!!!!!!!!!!");
				}
				else{
					printf("put your value :: ");
					scanf("%d",&val);
					enquene(val);
				}
				break;
			case 2:
				if(isempty()){
					printf("quene underflow !!!!!!!!!!!!");
				}
				else{
					printf("Deleted element :: %d",dequene());
				}
				break;
			case 3:
				if(isempty()){
					printf("quene empty !!!!!!!!!!!!!");
				}
				else{
					display();
				}
				break;
			case 4:
				if(isempty()){
					printf("quene empty !!!!!!!!!!!!");
				}
				else{
					printf("Deleted element :: %d",peek());
				}
				break;
			case 5:
				exit(0);
			default:
				printf("wrong chioce");
		}
	}
}
