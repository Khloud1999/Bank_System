/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : APP.c                                   */
/* Var    : V 1.0                                   */
/****************************************************/



#include "BankSystem.h"
#include "ADMIN.h"
#include "USER.h"




int main(){
	system ("cls");
	uint32 mode = 0;

	PRINTF(" 0: ADMIN MODE\n");
	PRINTF(" 1: USER MODE\n");
	PRINTF(" 2: EXIT\n\n");
	PRINTF(" Enter your choice: ");

	// take the choice
	SCANF("%d", &mode);
	PRINTF("\n======================================================\n");
	PRINTF("======================================================\n");

	switch(mode)
	{
		case (0):
			//admin mode
			ADMIN();
			break;
		case (1):
			//user mode
			USER();
			break;
		case (2):
			exit(0);
			break;
		default:
			PRINTF("\n Invalid input please inter 0 or 1 or 2\n");
			break;

	}
	return 0;
}
