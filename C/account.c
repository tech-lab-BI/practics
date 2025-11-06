#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define customar_size 5
#define ac_no_size 11
#define pass_len 7

struct Account {
	
	char name[20];
	char email[30];
	char ph[ac_no_size];
	
	int ac_no[ac_no_size];
	char password[pass_len];
	unsigned long int balance;
	unsigned int amt;//for deposit / withdraw / transfer
	
};

struct Account customar[customar_size];
int count = -1;

int ac_id(int a[]){				//return index of a/c of customar at structure 
	
	int i = 0,j = 0;
	
	while(i<=count && j<ac_no_size){
		
		if(a[j] != customar[i].ac_no[j]){
			i++;
			j = 0;
		}
		else{
			j++;
		}
		if(j == ac_no_size){
			break;
		}
		
	}
	
	if((count == -1)||(j == 0)){
		return -1;
	}
	else{
		return i;
	}
	
	
}

void ip_ac_det(){				//take customar details
	
	char tem[2];
	
	printf(":: A/C Details ::\n");
	printf("Name :- ");
	gets(customar[count].name);
	//gets(tem);//buffer
	printf("Phone no :- ");
	gets(customar[count].ph);
	//gets(tem);//buffer
	printf("E-mail :- ");
	gets(customar[count].email);
	//gets(tem);//buffer
	
}

void create_ac(){				//random get a/c number
	
	int i,j;
	
	if(count >= customar_size){
		printf("A/C creation failed !!!");
	}
	else{
		count++;
		ip_ac_det();
		for(i=0;i<ac_no_size;i++){
			customar[count].ac_no[i] = (rand() % 9) + 1;
		}
		printf("\nA/C create successfully..........");
		
		printf("\nA/C no -> ");
		for(j=0;j<ac_no_size;j++){
			printf("%d",customar[count].ac_no[j]);
		}
		
		printf("\nEnter 6-digit password :- ");
		gets(customar[count].password);
		//gets(tem);//buffer
	}
	
}

void op_ac_det(int id){			//output of a/c details
	
	int j;
	
	printf(":: A/C Details ::\n");
	printf("\nNAME -> %s",customar[id].name);
	printf("\nEmail -> %s",customar[id].email);
	printf("\nPh no -> %s",customar[id].ph);
	printf("\nA/C no -> ");
	for(j=0;j<ac_no_size;j++){
		printf("%d",customar[id].ac_no[j]);
	}
	printf("\nPassword :- ******\n");
	printf("\n...all are encrypted.......");
	
}

void status(int ch,int id){		//give massage after successful transection
	
	int i;
	
	switch(ch){
		case 1:
			printf("INR %lu.00 credited to a/c - ",customar[id].amt);
			break;
		case 2:
			printf("INR %lu.00 debited to a/c - ",customar[id].amt);
			break;
		case 3:
			printf("INR %lu.00 transfer from a/c - ",customar[id].amt);
			break;
		
	}
	for(i=0;i<ac_no_size;i++){
		if(i<7){
			printf("X");
		}
		else{
			printf("%d",customar[id].ac_no[i]);
		}
	}
	printf(" current balance = %lu.00 rs.",customar[id].balance);
}

int transection(){				//for transection (debit / credit / transfer )
	
	int i,ch,id,ac[ac_no_size];
	int trn_id;
	

	
	while(1){
		
		printf("Login page ::- ");
		printf("\n\n\t[1. Deposit");
		printf("\t 2. Withdraw");
		printf("\t 3. Transfer");
		printf("\t 4. sign out]");
		
		printf("\n\nChoose :: ");
		scanf("%d",&ch);
	
		printf("\n------------------------------------\n");	
	
		switch(ch){
			case 1:
				printf("Enter deposit amount :: ");
				scanf("%lu",&customar[id].amt);
				customar[id].balance += customar[id].amt;
				status(ch,id);
				break;
			case 2:
				printf("Withdraw amount :: ");
				scanf("%lu",&customar[id].amt);
					
				if(customar[id].balance < customar[id].amt){
					printf("YOU can't withdraw !! as your balance low .");
				}
				else{
					customar[id].balance -= customar[id].amt;
					status(ch,id);
				}
				break;
			case 3:
				printf("From ");
				for(i=0;i<ac_no_size;i++){
					if(i<pass_len)
						printf("X");
					else
						printf("%d",customar[id].ac_no[i]);
				}
				printf(" To >>(a/c no) ");
				for(i=0;i<ac_no_size;i++)
					scanf("%1d",&ac[i]);
				trn_id=ac_id(ac);
				if(trn_id == -1){
					printf("\n Accepter details not match our data !!");
					break;
				}
			
				printf("\nEnter transfer amount :: ");
				scanf("%lu",&customar[id].amt);
				if((customar[id].balance - customar[id].amt) < 0){
					printf("YOU can't withdraw !! as your balance low .");
				}
				else{
					customar[id].balance -= customar[id].amt;
					customar[trn_id].balance += customar[id].amt;
					status(ch,id);
				}
				break;
			default:
				return 0;
		}
		
		
		
		printf("\n------------------------------------\n");	
	
	}
	
	status(ch,id);
}

void login(){					//login for transection
	
	int i,id,ac[ac_no_size];
	char log_pass[6],tem[2];
	
	printf("\na/c no - ");// take account
	for(i=0;i<ac_no_size;i++){
		scanf("%1d",&ac[i]);
	}
	printf("\nprocessing.......................\n");
	id = ac_id(ac);
	
	gets(tem);
	
	if(id != -1){
		printf("\nEnter password : ");// take password
		gets(log_pass);
		for(i=0;i<6;i++){
			if(log_pass[i] != customar[id].password[i]){
				printf("Incorrect password !!");
				return ;
			}	
		}
		
		transection();
	}
	else{
		printf("No data found!!!!");	
	}
	
}

void check_balance(){			//check balance of a a/c
	
	int i,id,ac[ac_no_size];
	
	printf("\na/c no - ");
	for(i=0;i<ac_no_size;i++){
		scanf("%1d",&ac[i]);
	}
	printf("\nprocessing.......................\n");
	id = ac_id(ac);
	
	if(id == -1){
		printf("\nData not found !");
		return;
	}
	else{
		for(i=0;i<ac_no_size;i++){
			if(i<7){
				printf("X");
			}
			else{
				printf("%d",customar[id].ac_no[i]);
			}
		}
		printf(" current balance = %lu.00 rs.",customar[id].balance);
	}
}



int main(){
	
	int i,ch,id,ac[ac_no_size];
	char tem[2];
	srand(time(NULL));
	
	printf("$$$$$$$$  WELCOME TO INSPIRE BANK  $$$$$$$\n\n");
	
	while(1){
		
		printf("Homepage ::- ");
		printf("\n\t [1. Creat a/c");
		printf("\t 2. log in ");
		printf("\t 3. Check balance");
		printf("\t 4. See details]");
		printf("\n\nChoose :- ");
		scanf("%d",&ch);
		gets(tem);//buffer
	
		printf("\n------------------------------------\n");	
		
		switch(ch){
			case 1:
				create_ac();
				break;
			case 2:
				login();
				break;
			case 3:
				check_balance();
				break;
			case 4:
				printf("\n	a/c no - ");
				for(i=0;i<ac_no_size;i++){
					scanf("%1d",&ac[i]);
				}
				printf("\n	processing.......................\n");
				id = ac_id(ac);
				if(id == -1)
					printf("\n	Data not found !!");
				else
					op_ac_det(id);
				break;
			default :
				printf("Invalid choice!!");
				exit(0);	
		}
	
		printf("\n------------------------------------\n");	
	}
	
	return 0;
}
