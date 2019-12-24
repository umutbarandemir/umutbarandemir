#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
unsigned long Deposit,Amount,WithdrawWD,AccountN;
int Choice, ChoiceWD, ChoiceCurr, Password, Transfer;
char Transaction;
void MainMenu(void);
FILE *filep;

int Yes_No()
{
	printf("\n\n\nDo you want to do another Transaction?(Y/N): \n");
		switch(getch())
		{
        case 'y':
            MainMenu();
            break;
        case 'n':
            exit(0);
            
            break;
        default:
            system("cls");
            printf("\nYou pressed a wrong key Do you want to try again?(Y/N))");
            switch(getch())
			{
                case 'y':
                    MainMenu();
                    break;
                case 'n':
                    exit(0);
                    break;
                default:
                    printf("\nyou pressed an incorrect character, the program quiting...");
                    getch();
                    exit(0);
                    break;
            }
            break;
    	}		
}

int Balance()
{
		printf("Your Balance : %lu\n", Amount);
			Yes_No();	
}

int Withdraw()
{
		
		printf("1. 50TL\n2. 100TL\n3. 200TL\n4. 500TL\n5.Enter the Amount to Withdraw\n");
			scanf("%d",&ChoiceWD);
			switch(ChoiceWD)
			{
				case 1: 
				if(50>Amount)
				{
					printf("Insufficent Balance\n ");
				}
					else
					{
						Amount=Amount-50;
						printf("Transaction Successful\n");
						printf("New Balance is %lu \n",Amount);
					
						filep=fopen("Exit.txt","a");
						fputs("50 TL withdraw from the account.\n",filep);
						fputs("************\n",filep);
						fclose(filep);		
					}
						Yes_No();
						
						
				break;
				
				case 2: 
					if(100>Amount)
					{
						printf("Insufficent Balance\n ");
					}
						else
						{
							Amount=Amount-100;
							printf("Transaction Successful\n");
							printf("New Balance is %lu \n",Amount);
						
							filep=fopen("Exit.txt","a");
							fputs("100 TL withdraw from the account.\n",filep);
							fputs("************\n",filep);
							fclose(filep);
						}	
							Yes_No();
							break;
				
				case 3: 
					if(200>Amount)
					{
						printf("Insufficent Balance\n ");
					}
						else
						{
							Amount=Amount-200;
							printf("Transaction Successful\n");
							printf("New Balance is %lu \n",Amount);
						
							filep=fopen("Exit.txt","a");
							fputs("200 TL withdraw from the account.\n",filep);
							fputs("************\n",filep);
							fclose(filep);
						}
							
							Yes_No();
							break;
				
				case 4: 
					if(500>Amount)
					{
						printf("Insufficent Balance\n ");
					}
						else
						{
							Amount=Amount-500;
							printf("Transaction Successful\n");
							printf("New Balance is %lu \n",Amount);
							
							filep=fopen("Exit.txt","a");
							fputs("500 TL withdraw from the account.\n",filep);
							fputs("************\n",filep);
							fclose(filep);
						}
							Yes_No();
							break;
					
				case 5: 
						printf("Your Current Balance is %lu \n", Amount);
						printf("\n Enter the Amount to Withdraw: ");
						scanf("%lu", &WithdrawWD);
					if (WithdrawWD % 5 != 0)
					{
						printf("\n Please Enter the Amount in Multiples of 5");
					}
						else if (WithdrawWD >(Amount))
						{
							printf("\n Insufficent Balance");
						}
							else
							{
								Amount = Amount - WithdrawWD;
								printf("\n Your New Balance is %lu\n", Amount);
								
								filep=fopen("Exit.txt","a");
								fprintf(filep,"%lu TL withdraw from the account.\n",WithdrawWD);
								fputs("************\n",filep);
								fclose(filep);
								
							}
								Yes_No();
								break;
								default: 
								printf("Invalid Choice");
								getch();
								exit(0);
			}
			
}

int DepositDT()
{
		printf("\n Enter The Amount To Deposit ");
		scanf("%lu", &Deposit);
		printf("Are you sure you want to deposit %lu? (Y/N): \n",Deposit);	
			
			switch(getch())
			{
				case 'y':
					Amount = Amount + Deposit;
					printf("Your New Balance is %lu\n", Amount);
					filep=fopen("Exit.txt","a");
					fprintf(filep,"You deposited %lu TL.\n",Deposit);
					fputs("***********\n",filep);
					fclose(filep);
					break;
				case 'n':
					printf("Transaction canceled. You are directed to the main menu.");
					getch();
					MainMenu();
					break;
					default:
					printf("You pressed an incorrect character\nQuiting...");	
					getch();
					exit(0);			
			}
					Yes_No();
}

int TransferTR()

	/*2922334455
	2934567890
	2944332211
	2977889900
	2912312312
	2857924680
	2812223334
	2811222233
	2811122222
	2844455555*/

{			
	printf("\n Enter the amount that will be sent : ");
	scanf("%d",&Transfer);
	if(Transfer>Amount){
		printf("Invalid Amount");
	}
	else if(Transfer<=Amount){
		printf("Enter the account number that money will be sent to : ");
		scanf("%lu",&AccountN);
		if(AccountN == 2922334455 || AccountN == 2934567890 || AccountN == 2944332211 || AccountN == 2977889900 || AccountN == 2912312312 || AccountN == 2857924680 || AccountN == 2812223334 || AccountN == 2811222233 || AccountN == 2811122222 || AccountN == 2844455555)
		{
		Amount=Amount-Transfer;
		printf("You sent %d TL to %lu account number.",Transfer,AccountN);
		printf("\nYour New Balance is %lu",Amount);	
		
		filep=fopen("Exit.txt","a");
		fprintf(filep,"You sent %d TL to %lu account number.\n",Transfer,AccountN);
		fputs("***********************************************\n",filep);
		fclose(filep);
		}
		else {
			printf("Invalid Account Number ");
		}
	}
	Yes_No();

}
int CurrencyTR(){
	int dollar,euro,pound,TL1,TL2,TL3;
	printf("Select currency to convert to TL\n");
	printf("1.Dollar\n2.Euro\n3.Pound\n");
	scanf("%d",&ChoiceCurr);
	switch(ChoiceCurr){
		case 1:
			printf("Deposit the dollar to be converted to TL : ");
			scanf("%d",&dollar);
			TL1=dollar*5;
			printf("%d dollars equals to %d TL.",dollar,TL1);
			printf("\nAre you sure you want to deposit %d dollars? (Y/N): \n",dollar);
			
			switch(getch())
			{
				case 'y':
					Amount = Amount + TL1;
					printf("Your New Balance is %lu\n", Amount);
					filep=fopen("Exit.txt","a");
					fprintf(filep,"You deposited %d dollars.\n",dollar);
					fputs("***********\n",filep);
					fclose(filep);
					break;
				case 'n':
					printf("Transaction canceled. You are directed to the main menu.");
					getch();
					MainMenu();
					break;
					default:
					printf("You pressed an incorrect character\nQuiting...");	
					getch();
					exit(0);			
			}
			break;
		case 2:
			printf("Deposit the euro to be converted to TL : ");	
			scanf("%d",&euro);
			TL2=euro*6;
			printf("%d euros equals to %d TL",euro,TL2);
			printf("\nAre you sure you want to deposit %d euros? (Y/N): \n",euro);
			
			switch(getch())
			{
				case 'y':
					Amount = Amount + TL2;
					printf("Your New Balance is %lu\n", Amount);
					filep=fopen("Exit.txt","a");
					fprintf(filep,"You deposited %d euros.\n",euro);
					fputs("***********\n",filep);
					fclose(filep);
					break;
				case 'n':
					printf("Transaction canceled. You are directed to the main menu.");
					getch();
					MainMenu();
					break;
					default:
					printf("You pressed an incorrect character\nQuiting...");	
					getch();
					exit(0);			
			}
			break;
		case 3:
			printf("Deposit the pound to be converted to TL : ");	
			scanf("%d",&pound);
			TL3=pound*7;
			printf("%d pounds equals to %d TL",pound,TL3);
			printf("\nAre you sure you want to deposit %d pound? (Y/N): \n",pound);
			
			switch(getch())
			{
				case 'y':
					Amount = Amount + TL3;
					printf("Your New Balance is %lu\n", Amount);
					filep=fopen("Exit.txt","a");
					fprintf(filep,"You deposited %d pounds.\n",pound);
					fputs("***********\n",filep);
					fclose(filep);
					break;
				case 'n':
					printf("Transaction canceled. You are directed to the main menu.");
					getch();
					MainMenu();
					break;
					default:
					printf("You pressed an incorrect character\nQuiting...");	
					getch();
					exit(0);			
			}
			break;
		default:
			printf("Invalid Choice");	
			getch();
			exit(0);
		}
			Yes_No();
}

int Exit()
{
	printf("\n\n\n Are you sure you want to exit ATM?(Y/N): \n");
	switch(getch())
			{
				break;
				case 'n':
					printf("You are directed to the main menu.");
					getch();
					MainMenu();
					break;
				case 'y':
					printf("Quiting...");
					getch();
					exit(0);
					break;
					default:
					printf("Invalid Choice");
					break;
					
			}
}
