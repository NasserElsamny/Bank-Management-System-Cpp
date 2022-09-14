

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include"STD_TYPES.h"
#include<iostream>

typedef struct Account_t
{
	std::string Full_Name;
	std::string Full_Address;
	u64 NationalID;
	u16 Age;
	u64 BankAccountID;
	std::string Guardian_Name;
	u64 GuardianNationalID;
	std::string AccountStatus;
	u64 Balance;
	std::string Password; 
	struct Account_t* Link;
	
}BankAccount;


u32 Bank_u32Welcome(void);
void Bank_u32AdminLogin(void);
u32 Bank_u32AdminMainMenu(void);
u8 Bank_u8Check(std::string ,std::string); 
void Bank_vCreateFirstAccount(BankAccount*);
void Bank_vCreateNewAccount(BankAccount*);
void Bank_vExit(void);
void Bank_vGenerateRandomPassword(std::string& password);
void Bank_vShowAccountInfo(BankAccount*);
BankAccount* Bank_pOpenExistingAccount(BankAccount* head);
void Bank_vGetCash(BankAccount*);
void Bank_vChangeAccountPassword(BankAccount*);
void Bank_vDeposit(BankAccount*);
u32 Bank_u32CountAccounts(BankAccount* head);
u8 Bank_u8ExistingAccountOptions(void);
void Bank_vChangeAccountStatus(BankAccount*);
u8 Bank_u8MakeTransaction(BankAccount*, BankAccount*);
BankAccount* Bank_vClientLogin(BankAccount*);
u32 Bank_u32ClientMainMenu(void);

#endif