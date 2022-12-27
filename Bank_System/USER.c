/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : USER.c			                        */
/* Var    : V 1.0                                   */
/****************************************************/


#include "USER.h"

void USER(){

		uint32 account_id;
		uint32 account_password;
		struct node* user=NULL;

		PRINTF("Welcome USER\n");
		PRINTF("======================================================\n");
		goto USER_INFO;

		USER_INFO:
		PRINTF("ACCOUNT ID:\t");
		SCANF("%d",&account_id);
		PRINTF("\nPASSWORD:\t");
		SCANF("%d",&account_password);

		user = get_client(account_id);

		if((user != NULL) && check_userPassword(user,account_password))
		{
			main_user(user);
		}
		else
		{
			PRINTF("======================================================\n");
			PRINTF("Invalid ACCOUNT ID or Password.Please try again!!!\n");
			goto USER_INFO;
		}

}

void main_user(struct node* user){
		sint8 choice;
		uint32 account_id=0;
		uint64 balance=0;

		system ("cls");
		PRINTF("\n********* WELCOME USER *********\n");
		goto user_options;
		user_options:

		PRINTF("\n 1: MAKE TRANSFER\n");
		PRINTF(" 2: CHANGE PASSWORD\n");
		PRINTF(" 3: Get CASH\n");
		PRINTF(" 4: DEPOSIT IN ACCOUNT\n");
		PRINTF("-1: BACK\n");
		PRINTF(" 0: EXIT\n");
		PRINTF("*****************************************************\n");
		PRINTF(" Enter your choice:\t");
		SCANF("%d",&choice);

		switch(choice)
		{

			case (1):
						system ("cls");
						PRINTF("\nOTHER ACCOUNT ID:\t");
						SCANF("%d",&account_id);
						PRINTF("\nBALANCE:\t");
						SCANF("%lld",&balance);

						Make_Transaction(user->client.acc_id,account_id,balance);
						goto user_options;
						break;
			case (2):
						system ("cls");

						Change_Password(user);
						goto user_options;
						break;

			case (3):
						system ("cls");
						PRINTF("\nBALANCE:\t");
						SCANF("%lld",&balance);
						Get_Cash(user->client.acc_id,balance);
						goto user_options;
						break;
			case (4):
						system ("cls");
						PRINTF("\nBALANCE:\t");
						SCANF("%lld",&balance);
						Deposit_In_Account(user->client.acc_id,balance);
						goto user_options;
						break;
			case (-1):
						USER();
						break;
			case (0):
						main();
						break;


		}
}

void Change_Password(struct node* user){
	uint32 old_password =0 ,new_password=0;
	uint8 counter=0;
	goto old_password_section;
	old_password_section:
	PRINTF("\nCHANGE PASSWORD\n");
	PRINTF("ENTER OLD PASSWORD\n");
	SCANF("%d",&old_password);

	if(check_userPassword(user , old_password)){

		PRINTF("ENTER NEW PASSWORD\n");
		SCANF("%d",&new_password);
		user->client.acc_password = new_password;
		PRINTF("PASSWORD CHANGED CORRECTLY\n");
		print_user_info(user);

	}else{
		counter++;
		if(counter <3){
			goto old_password_section;
		}else{
			PRINTF("MORE THAN 3 WRONG TRIES\n");
			USER();
		}

	}
}

uint8 check_userPassword(struct node* user , uint32 password){

	uint8 status =0;
	if(user->client.acc_password == password){
		status =1;
	}else{
		status =0;
	}

	return status;
}
