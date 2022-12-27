/****************************************************/
/* Auther : KhOloud Khaled                          */
/* Date   : 25 DEC 2022                             */
/* File   : USER.h                                  */
/* Var    : V 1.0                                   */
/****************************************************/


#ifndef USER_H_
#define USER_H_

#include "BankSystem.h"

// extern to main function
extern int main();
//This function call main_user() function if the account valid
void USER();
//This function is the main algorithm of the user
void main_user(struct node* user);
//This function check if the user password is correct or not
uint8 check_userPassword(struct node* user , uint32 password);
//This function enable user to change password
void Change_Password(struct node* user);
#endif /* USER_H_ */
