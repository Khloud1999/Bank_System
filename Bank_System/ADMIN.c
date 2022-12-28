/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : ADMIN.h		                            */
/* Var    : V 1.0                                   */
/****************************************************/

#include "ADMIN.h"

/* Admin access  */
#define  ADMIN_ACCOUNT 		"kholoud"
#define  ADMIN_PWD  		4444


void ADMIN(){

	uint8 admin_name[10];
	uint32 admin_password;
	PRINTF("Welcome in admin \n");
	PRINTF("======================================================\n");
	goto ADMIN_INFO;

	ADMIN_INFO:
	PRINTF("USER Name:\t");
	SCANF("%[^\n]s",admin_name);
	PRINTF("\nPASSWORD:\t");
	SCANF("%d",&admin_password);

	if(check_password(admin_password) && check_adminName(admin_name))
	{
		admin_dashboard();
	}
	else
	{
		PRINTF("======================================================\n");
		PRINTF("Invalid USER Name or Password.Please try again!!!\n");
		goto ADMIN_INFO;
	}
}

void admin_dashboard(){

	sint8 choice;
	uint32 account_id1=0,account_id2=0;
	uint64 balance=0;
	uint8 status[15];
	system ("cls");
	PRINTF("********* WELCOME TO BANK MANAGEMENT SYSTEM *********\n");
	goto admin_options;
	admin_options:
	PRINTF("\n 1: CREATE NEW ACCOUNT\n");
	PRINTF(" 2: MAKE TRANSFER\n");
	PRINTF(" 3: CHANGE ACCOUNT STATUS\n");
	PRINTF(" 4: Get CASH\n");
	PRINTF(" 5: DEPOSIT IN ACCOUNT\n");
	PRINTF("-1: BACK\n");
	PRINTF(" 0: EXIT\n");
	PRINTF("*****************************************************\n");
	PRINTF(" Enter your choice:\t");
	SCANF("%d",&choice);

	switch(choice)
	{
		case (1):
					Create_New_Account();
					goto admin_options;
					break;
		case (2):
					system ("CLS");
					PRINTF("\nACCOUNT ID1:\t");
					SCANF("%d",&account_id1);
					PRINTF("\nACCOUNT ID2:\t");
					SCANF("%d",&account_id2);
					PRINTF("\nBALANCE:\t");
					SCANF("%lld",&balance);

					Make_Transaction(account_id1,account_id2,balance);
					goto admin_options;
					break;
		case (3):
					system ("CLS");
					PRINTF("\nACCOUNT ID1:\t");
					SCANF("%d",&account_id1);
					PRINTF("\nStatus:\t");
					PRINTF("\nOPtions: (");
					PRINTF("active , restricted or closed )\n");
					SCANF("%[^\n]s",&status);
					Set_Account_Status(account_id1,status);
					goto admin_options;
					break;
		case (4):
					system ("CLS");
					PRINTF("\nACCOUNT ID1:\t");
					SCANF("%d",&account_id1);
					PRINTF("\nBALANCE:\t");
					SCANF("%lld",&balance);
					Get_Cash(account_id1,balance);
					goto admin_options;
					break;
		case (5):
					system ("CLS");
					PRINTF("\nACCOUNT ID1:\t");
					SCANF("%d",&account_id1);
					PRINTF("\nBALANCE:\t");
					SCANF("%lld",&balance);
					Deposit_In_Account(account_id1,balance);
					goto admin_options;
					break;
		case (-1):
					ADMIN();
					break;
		case (0):
					main();
					break;


	}
}


uint8 check_password(uint32 password){
	uint8 status=0;
	if (password == ADMIN_PWD)
	{
		status = 1;
	}
	else
	{
		status = 0;
	}
	return status;
}

uint8 check_adminName(uint8* admin_name){
		uint8 status=0;
		if (strcmp((uint8*)ADMIN_ACCOUNT,admin_name )==0)
		{
			status = 1;
		}
		else
		{
			status = 0;
		}
		return status;
}

/* This function set the account satuts */
void Set_Account_Status(uint32 id, uint8* status){
	struct node* user =get_client(id);
	if (user && strcmp("active", user->client.acc_status) == 0)
	{
		if(strcmp("active", status) == 0)
		{
			strcpy(user->client.acc_status, status);
			printf(" Account ID %d status becomes %s\n", user->client.acc_id, user->client.acc_status);
		}
		else if (strcmp("restricted", status) == 0)
		{
			strcpy(user->client.acc_status, status);
			printf(" Account ID %d status becomes %s\n", user->client.acc_id, user->client.acc_status);
		}
		else if (strcmp("closed", status) == 0)
		{
			strcpy(user->client.acc_status, status);
			printf(" Account ID %d status becomes %s\n", user->client.acc_id, user->client.acc_status);
		}
		else
		{
			printf("\n Invalid Input!\n");
		}
	}
	else
	{
		printf(" Account ID %d does not exist!\n", id);
	}
}

