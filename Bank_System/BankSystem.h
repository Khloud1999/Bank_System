/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : BankSystem.h                            */
/* Var    : V 1.0                                   */
/****************************************************/

#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "STD_TYPES.h"

/* Verification data for national id & password */
#define MIN14DIGITS 	10000000000000		
#define MAX14DIGITS 	99999999999999
#define MIN10DIGITS 	1000000000
#define MAX10DIGITS 	9999999999	
#define MIN5DIGITS 		10000	
#define MAX5DIGITS 		99999
#define MIN3DIGITS		100
#define MAX3DIGITS		999


#define PRINTF(...)		{fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

#define SCANF(...)		{fflush(stdout); \
						fflush(stdin); \
						scanf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

typedef struct sClient{

	uint8   name[50];
	uint8   address[50];
	uint64  national_id;
	float32 age;
	uint32  acc_id;								
	uint8   acc_status[50];
	uint64  acc_balance;
	uint32  acc_password;
	uint64  guardian_national_id;

}Client;

struct node
{
	Client client ;
	struct node* nextPtr ;
};


/* This function scan data of new client like:
	national ID, guardian national id, name, address, age,
	account ID, password, status & balance. */
void Create_New_Account();

//this function count word in string
uint32 Number_of_words(const uint8* input );
// get the client from his id
struct node* get_client(uint32 id);
//print the information of new user
void print_user_info(struct node* user);
//This function inputs account id 1, account id 2 & balance to transfer
void Make_Transaction(uint32 id1, uint32 id2, uint64 balance);
//this function to get Cash from account
void Get_Cash(uint32 id, uint64 balance);
// This function deposit in account
void Deposit_In_Account(uint32 id, uint64 balance);

#endif
