/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : BankSystem.c                            */
/* Var    : V 1.0                                   */
/****************************************************/

#include "STD_TYPES.h"
#include "BankSystem.h"

static uint32 bank_id 	= 1000000000;


// global variable point to the head of linked list
struct node* H_ptr =NULL;


/* This function scan data of new client like:
	national ID, guardian national id, name, address, age,
	account ID, password, status & balance. */
void Create_New_Account(){
	struct node* new_user_ptr;
	struct node* last_user_ptr;
	// check list empty or not
	if(H_ptr == NULL){
		// empty list
		new_user_ptr = (struct node*) malloc(sizeof(struct node));
		H_ptr = (struct node*) new_user_ptr;

	}else{ // not empty list
		// navigate until last user
		last_user_ptr = (struct node*) H_ptr;

		while(last_user_ptr->nextPtr)
			last_user_ptr= last_user_ptr->nextPtr ;

		// create a new student

		new_user_ptr = (struct node*) malloc(sizeof(struct node));
		last_user_ptr->nextPtr =  new_user_ptr;

	}

	// fill user informations

	//scan national id
	NATIONAL_ID_FLAG:
	PRINTF("ENTER Your NATIONAL ID: ");
	SCANF("%llu", &(new_user_ptr->client.national_id));
	if (!isdigit(new_user_ptr->client.national_id) && ((new_user_ptr->client.national_id < MIN14DIGITS) || (new_user_ptr->client.national_id > MAX14DIGITS)))
	{
		PRINTF("INVALID NATIONAL ID\n");
		goto NATIONAL_ID_FLAG;
	}

	//scan name
	uint32 counter1 =0 ;
	NAME_FLAG:
	if (counter1 == 3)
	{
		PRINTF("\n No more tries!\n");
		return ;
	}
	PRINTF(" FULL NAME: ");
    SCANF("%[^\n]s",new_user_ptr->client.name);
	uint32 words_count = Number_of_words(new_user_ptr->client.name);
	if (words_count < 4)
	{
		PRINTF("\n Enter valid full name (4) words\n");
		++counter1;
		goto NAME_FLAG;
	}
			
	//generate random password
	srand(time(0)); //generate pass every time
	new_user_ptr->client.acc_password = rand();
	
	//scan address
	uint32 counter2 =0  ;
	words_count = 0;
	ADDR_FLAG:
	if (counter2 == 3)
	{
		PRINTF("\n No more tries!\n");
		return ;
	}
	printf(" FULL ADDRESS: ");
    SCANF("%[^\n]s",new_user_ptr->client.address);
	words_count =  Number_of_words(new_user_ptr->client.address);
	if (words_count < 3)
	{
		printf("\nEnter address like :\n Street, City, Country\n");
		++counter2;
		goto ADDR_FLAG;
	}
	
	//account s tatus
	//string_copy((new_user_ptr->client.acc_status),"active"); // need to modify
	strcpy(new_user_ptr->client.acc_status,"active");
	//scan age & Gurdian national id
	uint32 counter3 = 0;
	AGE_FLAG:
	if (counter3 == 3)
	{
		PRINTF("\n No more tries!\n");
		return ;
	}
	
	printf(" AGE: ");
	SCANF("%f", &(new_user_ptr->client.age));
	if((new_user_ptr->client.age >= 1) && (new_user_ptr->client.age <= 100)){

		if (new_user_ptr->client.age < 21){	/* GUARDIAN NATIONAL ID is required */
			GUARDIAN_NAT_ID:
			printf(" GUARDIAN NATIONAL ID: ");
			SCANF("%llu", &(new_user_ptr->client.guardian_national_id));
			if (!isdigit(new_user_ptr->client.guardian_national_id) && ((new_user_ptr->client.guardian_national_id < MIN14DIGITS) || (new_user_ptr->client.guardian_national_id > MAX14DIGITS)))
			{
				goto GUARDIAN_NAT_ID;
			}
		}
		else
		{
			new_user_ptr->client.guardian_national_id = 0x00;
		}
	}
	else
	{
		printf("\nEnter valid age!\n");
		++counter3;
		goto AGE_FLAG;
	}	
	
	//scan account balance
	uint32 counter4 = 0;
	BALANCE_FLAG:
	if (counter4 == 3)
	{
		PRINTF("\n No more tries!\n");
		return ;
	}
	PRINTF(" ACCOUNT BALANCE: ");
	SCANF("%llu", &(new_user_ptr->client.acc_balance));

	if (!(new_user_ptr->client.acc_balance >= 1) && !(new_user_ptr->client.acc_balance <= 1000000))
	{
		printf("\nEnter valid balance!\n");
		++counter4;
		goto BALANCE_FLAG;
	}
		
	//assign bank id to the acount
	new_user_ptr->client.acc_id = bank_id;
	bank_id ++;

	new_user_ptr->nextPtr = NULL;

	print_user_info(new_user_ptr);
			
}

//This function inputs account id 1, account id 2 & balance to transfer
void Make_Transaction(uint32 id1, uint32 id2, uint64 balance){
	struct node* client1 = get_client(id1);

	struct node* client2 = get_client(id2);
	if(client1 != NULL && client2 != NULL){
		if ((strcmp(client1->client.acc_status, "active") == 0) && (strcmp(client2->client.acc_status, "active") == 0) && (balance <= (client1->client.acc_balance)))
		{
			(client2->client.acc_balance) += balance;
			(client1->client.acc_balance) -= balance;
			PRINTF(" Account ID %d balance = %llu$\n", id1, client1->client.acc_balance);
			PRINTF(" Account ID %d balance = %llu$\n", id2, client2->client.acc_balance);
		}
		else
		{
			PRINTF(" Sorry! Account ID %d has not sufficient balance or any of account ID %d or %d is not active! \n",id1, id1, id2);
		}
	}
	else
	{
		PRINTF(" Sorry! Account ID is not existed! \n");

	}

}
//this function count word in string
uint32 Number_of_words(const uint8* input ){
	uint32 words_num=1,i=0;
	while(input[i]!='\0'){
		if(input[i] ==' ')
			words_num++;
		i++;
	}
	return words_num;
}

// get the client from his id
struct node* get_client(uint32 id){
	// flag if the id is found or not
	uint8 flag=0;
	struct node *P_temp = H_ptr;
	if(P_temp->client.acc_id == id){
		return P_temp;
	}
	else
	{
		while(P_temp->nextPtr != NULL){
			if(P_temp->nextPtr->client.acc_id == id){
				flag = 1;
				return P_temp->nextPtr;

			}
			P_temp = P_temp->nextPtr;
		}
	}
	if(flag==0){
		PRINTF("\nINVALID ID");
		return ((struct node*) NULL);
	}
	return ((struct node*) P_temp);
}
//print the information of new user
void print_user_info(struct node* user){


	if(H_ptr != NULL){

		if(user != NULL){
			PRINTF("\n*****************************************************\n");
			PRINTF("*****************************************************\n");
			PRINTF("Full NAME :\t\t %s \n",user->client.name);
			PRINTF("NATIONAL ID :\t\t %llu \n",user->client.national_id);
			PRINTF("FULL ADDRESS :\t\t %s \n",user->client.address);
			PRINTF("AGE :\t\t %04f \n",user->client.age);
			PRINTF("GURADIAN NATIONAL ID :\t\t  %llu \n",user->client.guardian_national_id);
			PRINTF("ACCOUNT ID :\t\t %d \n",user->client.acc_id);
			PRINTF("ACCOUNT STATUS :\t\t %s \n",user->client.acc_status);
			PRINTF("ACCOUNT BALANCE :\t\t  %llu \n",user->client.acc_balance);
			PRINTF("PASSWORD :\t\t %d \n",user->client.acc_password);
			PRINTF("\n\t===============================\t");

		}
		else
		{
			PRINTF("INVALID ID !!");
		}

	}
	else
	{
		PRINTF("There's no accounts !!");
	}


}

//this function to get Cash from account
void Get_Cash(uint32 id, uint64 balance){
	struct node* user =get_client(id);
	if ((user) && (user->client.acc_status) && ((balance) <= (user->client.acc_balance)))
	{
		user->client.acc_balance -= balance;
		printf(" Account ID %d balance = %d$\n", id, user->client.acc_balance);
	}
	else {
		printf(" Account ID %d is not active or entered balance larger than account balance\n",id);
	}
}


// This function deposit in account
void Deposit_In_Account(uint32 id, uint64 balance){
	struct node* user =get_client(id);
  if ((user) && (user->client.acc_status))
  {
  user->client.acc_balance += balance;
  printf(" Account ID %d balance = %d$\n", id, user->client.acc_balance);
  }
  else
  {
	  printf(" Account ID %d is not active\n");
  }
}
