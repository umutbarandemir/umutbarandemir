#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void MainMenu(void);
void Password();
int IncorrectPass=0;
int Choice;
unsigned long Amount=5000;
FILE *filep;
	
char UserPassword1[5]={"1111"};
char UserPassword2[5]={"2589"};
char UserPassword3[5]={"8521"};
char UserPassword4[5]={"8523"};
char UserPassword5[5]={"1478"};
char UserPassword6[5]={"3698"};
char UserPassword7[5]={"7412"};
char UserPassword8[5]={"9632"};
char UserPassword9[5]={"4563"};
char UserPassword10[5]={"3214"};

int main() {
	filep=fopen("exit.txt","w");
	Password();
	MainMenu();
	return 0;
}


void Password(void) {

system("cls");

char d[25]="Password Protected";
char ch,EnteredPass[5];
int i=0,j;

	printf("\t\t********* WELCOME  TO ******** \n    \t\t  ****** UMBOD ATM *******\n");
	printf("\t \n\n\n Please Enter Password : ");	

while(ch!=13)  //ASCII  13=Enter 8=backspace
{

	ch=getch();

	if(ch!=13 && ch!=8)
	{
	putch('*');
	EnteredPass[i] = ch;
	i++;
	}
}

EnteredPass[i] = '\0'; //Þifre sýfýrlama

if((strcmp(EnteredPass,UserPassword1)==0)||(strcmp(EnteredPass,UserPassword2)==0)||(strcmp(EnteredPass,UserPassword3)==0)||(strcmp(EnteredPass,UserPassword4)==0)||(strcmp(EnteredPass,UserPassword5)==0)||(strcmp(EnteredPass,UserPassword6)==0)||(strcmp(EnteredPass,UserPassword7)==0)||(strcmp(EnteredPass,UserPassword8)==0)||(strcmp(EnteredPass,UserPassword9)==0)||(strcmp(EnteredPass,UserPassword10)==0)){

printf("\n\n\n\t\tPassword matched!!");
printf("\n\n\tPress any key to countinue.....");
getch();
MainMenu();
}

else{
	IncorrectPass++;
		printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
		if(IncorrectPass==3){
			system("cls");
			
			printf("You have entered the wrong password more than three times.");
			printf("The system has locked itself. Closing program...");
			getchar();
			exit(0);
		}
		getch();
Password();
 }
 
}
 void MainMenu(){
 	system("cls"); //degerli
 	
 		printf("1. Check Balance\n");
		printf("2. Withdraw Money\n");
		printf("3. Deposit Money\n");
		printf("4. Money Transfer\n");
		printf("5. Currency Transactions\n");
		printf("6. Quit\n");
		printf("\nEnter your Choice: ");
	
		scanf("%d", &Choice);
 	
 	switch (Choice)
		{
		case 1:
			Balance();
			break;
		case 2:
			Withdraw();
			break;
		case 3:
			DepositDT();
			break;
		case 4:
			TransferTR();
			break;
		case 5:
			CurrencyTR();
			break;
		case 6:
			Exit();
			break;
			default: 
			printf("\n Invalid Choice");
			break;
		}
 	
 	
 }
