/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : ADMIN.h		                            */
/* Var    : V 1.0                                   */
/****************************************************/

#ifndef ADMIN_H_
#define ADMIN_H_

#include "STD_TYPES.h"
#include "BankSystem.h"


// extern main function
extern int main();
//This function call admin_dashboard() function if the admin authorized
void ADMIN();
//This function is the main algorithm of the admin
void admin_dashboard();
//This function check if the admin password is correct or not
uint8 check_password(uint32 password);
//This function check if the admin name is correct or not
uint8 check_adminName(uint8* admin_name);
//This function set the account satuts
void Set_Account_Status(uint32 id, uint8* status);


#endif /* ADMIN_H_ */
