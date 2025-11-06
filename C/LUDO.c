#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct score{
	char name[10];
	int score;
}p1,p2;

void display(){
	
	int r,c,i=100,j=81;//i for odd row , j for even row
	
	printf("---------------------------------------------------\n");
	for(r=1;r<=10;r++){
		printf("|");
		if(r%2 != 0){//for row-wise odd positions
			for(c=1;c<=10;c++){
				
				if((i == j) && (p1.score == p2.score)){//both are same position
					printf(" %c|%c ",p1.name[0],p2.name[0]);
				}
				else if(p1.score == i)
					printf(" <%c> ",p1.name[0]);
				else if(p2.score == i)
					printf(" <%c> ",p2.name[0]);
				else{
					if(i/10 == 0)//single digit
		    			printf("  %d  ",i);
		    		else if(i/100 == 0)//two digit
		    			printf(" %d  ",i);
		    		else//three 
		    			printf("%d  ",i);
		    	}
		    	
				i--;
	    		
			}
			i -= 10;
		}
		else{// for row-wise even positions
			for(c=1;c<=10;c++){
				
				if((i == j) && (p1.score == p2.score)){
					//printf("\n---------%d,%d\n",c,p1.score);
					printf(" %c|%c ",p1.name[0],p2.name[0]);
				}
				else if(p1.score == j)
					printf(" <%c> ",p1.name[0]);
				else if(p2.score == j)
					printf(" <%c> ",p2.name[0]);
				else{
					if(j/10 == 0)//single digit
		    			printf("  %d  ",j);
		    		else if(j/100 == 0)//two digit
		    			printf(" %d  ",j);
		    		else//three digit
		    			printf("%d  ",j);
				}
				
				j++;
	    		
			}
			j -= 30;
		}
		printf("|");
		printf("\n");
	}
	printf("----------------------------------------------------\n");
	
}

void details_ip(){
	
	char c1;
	printf("Player 1 (Enter full name): ");
	scanf("%s",&p1.name);
	scanf("%c",&c1);//fake i/p
	printf("Player 2 (Enter full name): ");
	scanf("%s",&p2.name);
	
}

void winner_check(){
	
	if(p1.score >= 100){
		printf("WINNER :: %s",p1.name);
		printf("Hope you enjoy this game !");
		exit(0);
	}
	if(p2.score >= 100){
		printf("WINNER :: %s",p2.name);
		printf("Hope you enjoy this game !");
		exit(0);
	}
	
}

int snake_ladder(int s){
	
	switch(s){//snake
		case 98:
			s = 10;
			break;
		case 40:
			s -= 13;
			break;
		case 22:
			s -= 5;
			break;
		default:
			s;
	}
	
	switch(s){//ladder
		case 12:
			s += 9;
			break;
		case 67:
			s += 2;
			break;
		case 87:
			s += 1;
			break;
		default:
			s;
	}
	
	return s;
	
}

int main(){
	
	int dies = 6;
	char c1[2];
	srand(time(NULL));
	
	p1.score = p2.score = 0;
	
	printf(":::WELCOME TO LUDO:::\n");
	printf("Instruction :- \n\t1. Two player put their name \n\t2. In board their 1st char\n\t3. For role your dies press enter\n");
	details_ip();
	
	printf("Here is your Board :\n");
	display();
	printf("NOW BEGIN  -->>");
	
	while(1){
		
		printf("\n%c turn (press enter)",p1.name[0]);
		gets(c1);//fake char
		p1.score += (rand() % dies) + 1;
		p1.score = snake_ladder(p1.score);
		
		scanf("%c",&c1);
		
		printf("%c turn (press enter)",p2.name[0]);
		gets(c1);//fake char
		p2.score += (rand() % dies) + 1;
		p2.score = snake_ladder(p2.score);
		
		printf("Now, position are :\n");
		display();
		
		winner_check();
		
	}
	
	return 0;
	
}
