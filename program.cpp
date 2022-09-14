#include <iostream>
#include"STD_TYPES.h"
#include"interface.h"
#include <time.h>
#include<string>


u32 Bank_u32Welcome(void)
{	
	u32 admin=0;
	std::cout<<"Welcome To ITI Bank"<<std::endl;
	
	//Ask to choose if admin or client
	std::cout<<"Please choose 1 for Admin or 2 for Client:"<<std::endl;
	std::cin>>admin;
	
	//Check validity of User's choice
	while((admin < 1) || (admin > 2))
	{
		std::cout<<"Wrong choice\n";
		std::cout<<"Please choose 1 for Admin or 2 for Client:\n";
		std::cin>>admin;
	}		
	return admin;
}

void Bank_u32AdminLogin(void)
{
	std::cout<<"Welcome to Admin window\n\n";
	std::string admin_username;
	std::string admin_password;
	
	//Ask admin to enter username and password
	std::cout<<"Username: ";
	std::cin>>admin_username;
	std::cout<<"Password: ";
	std::cin>>admin_password;
	
	//Check for Admin's username and password
	u8 CheckUsername = Bank_u8Check(admin_username , "admin"); 
	u8 CheckPassword = Bank_u8Check(admin_password , "Admin1234"); 
	while((CheckUsername != 0) || (CheckPassword != 0))
	{
		std::cout<<"Wrong username or password\n";
		std::cout<<"Please try again\n";
		std::cout<<"Username: ";
		std::cin>>admin_username;
		std::cout<<"Password: ";
		std::cin>>admin_password;
		CheckUsername = Bank_u8Check(admin_username , "admin"); 
		CheckPassword = Bank_u8Check(admin_password , "Admin1234"); 
	}
	std::cout<<"Login Successful\n";
}

u32 Bank_u32AdminMainMenu(void)
{
	//Choose from options in Admin window
	u32 AdminChoice = 0;
	std::cout<<"Enter 1 to Create New Account\n";
	std::cout<<"Enter 2 to Open Existing Account\n";
	std::cout<<"Enter 3 to Exit System\n";
	std::cin>>AdminChoice;
	//Check for Admin's choice
	while(AdminChoice < 1 || AdminChoice > 3)
	{
		std::cout<<"Invalid input please try again\n";
		std::cout<<"Enter 1 to Create New Account\n";
		std::cout<<"Enter 2 to Open Existing Account\n";	
		std::cout<<"Enter 3 to Exit System\n";
		std::cin>>AdminChoice;
	}
	return AdminChoice;
}

u8 Bank_u8Check(std::string a,std::string b)  
{  
	//Function to compare 2 strings
    u8 flag=0,i=0;    
    
	while(a[i]!='\0' || b[i]!='\0') 
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  

void Bank_vCreateFirstAccount(BankAccount* ptr)
{
	std::cout<<"Create first bank account\n";
	std::cout<<"Full Name: ";
	fflush(stdin);
	std::getline(std::cin , ptr->Full_Name);
	std::cout<<"Full Address: ";
	fflush(stdin);
	std::getline(std::cin , ptr->Full_Address);
	/*
	std::cout<<"National ID: ";
	std::cin>>ptr->NationalID;
	while((ptr->NationalID < 10000000000000) || (ptr->NationalID > 99999999999999))
	{
		std::cout<<"Wrong input, National ID must be a 14 digits number: ";
		std::cin>>ptr->NationalID;
	}
	*/
	std::cout<<"Age: ";
	std::cin>>ptr->Age;
	ptr->BankAccountID = 1000000000;
	if((ptr->Age) < 21)
	{
		std::cout<<"Guardian Name: ";
		fflush(stdin);
		std::getline(std::cin , ptr->Guardian_Name);
		std::cout<<"Guardian National ID: ";
		std::cin>>ptr->GuardianNationalID;
		while((ptr->GuardianNationalID < 10000000000000) ||(ptr->GuardianNationalID > 99999999999999))
		{
			std::cout<<"Wrong input, National ID must be a 14 digits number: ";
			std::cin>>ptr->GuardianNationalID;
		}
	}	
	else
	{
		ptr->Guardian_Name = "None";
		ptr->GuardianNationalID = 0;
	}
	ptr->AccountStatus = "Active";
	printf("Balance: ");
	std::cin>>ptr->Balance;
	Bank_vGenerateRandomPassword(ptr->Password); 
	ptr->Link = NULL;
	std::cout<<"Account created successfully\n\n";
	
}

void Bank_vCreateNewAccount(BankAccount* head)
{
	BankAccount* first = head;
	BankAccount* ptr = new BankAccount;
	while(first->Link != NULL)
	{
		first = first->Link;
	}
	first->Link = ptr;
	

	std::cout<<"Full Name: ";
	fflush(stdin);
	std::getline(std::cin ,ptr->Full_Name);
	std::cout<<"Full Address: ";
	fflush(stdin);
	std::getline(std::cin , ptr->Full_Address);
	
	std::cout<<"National ID: ";
	std::cin>>ptr->NationalID;
	while((ptr->NationalID < 10000000000000) || (ptr->NationalID > 99999999999999))
	{
		std::cout<<"Wrong input, National ID must be a 14 digits number: ";
		std::cin>>ptr->NationalID;
	}
	
	std::cout<<"Age: ";
	std::cin>>ptr->Age;
	static u32 FirstBankAccountID = 1000000001;
	ptr->BankAccountID = FirstBankAccountID;
	FirstBankAccountID++;
	if((ptr->Age) < 21)
	{
		std::cout<<"Guardian Name: ";
		fflush(stdin);
		std::getline(std::cin , ptr->Guardian_Name);
		std::cout<<"Guardian National ID: ";
		std::cin>>ptr->GuardianNationalID;
		while((ptr->GuardianNationalID < 10000000000000) ||(ptr->GuardianNationalID > 99999999999999))
		{
			std::cout<<"Wrong input, National ID must be a 14 digits number: ";
			std::cin>>ptr->GuardianNationalID;
		}
	}	
	else
	{
		ptr->Guardian_Name = "None";
		ptr->GuardianNationalID = 0;
	}
	ptr->AccountStatus = "Active";
	std::cout<<"Balance: ";
	std::cin>>ptr->Balance;
	Bank_vGenerateRandomPassword(ptr->Password); 
	ptr->Link = NULL;
	std::cout<<"Account created successfully\n";
	std::cout<<"Redirecting to main menu...\n\n";
}

void Bank_vGenerateRandomPassword(std::string& password)
{
	#if 0
	int randomizer = 0;

	/* Seed the random-number generator
	 with current time so that the
	 numbers will be different every time*/
	
	srand((unsigned int)(time(NULL)));

	// Array of numbers
	char numbers[] = "0123456789";

	// Array of small alphabets
	char letter[] = "abcdefghijklmnoqprstuvwyzx";

	// Array of capital alphabets
	char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

	// Array of the special symbols
	char symbols[] = "!@#$&";

	// To select the randomizer inside the loop
	randomizer = rand() % 4;

	//Generate password of 12 random characters
	for (u8 i = 0; i < 12; i++) {

		if (randomizer == 1) {
			password[i] = numbers[rand() % 10];
			randomizer = rand() % 4;
			//printf("%c", password[i]);
		}
		else if (randomizer == 2) {
			password[i] = symbols[rand() % 5];
			randomizer = rand() % 4;
			//printf("%c", password[i]);
		}
		else if (randomizer == 3) {
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			//printf("%c", password[i]);
		}
		else {
			password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			//printf("%c", password[i]);
		}
	}
	password[12] = '\0';
	#endif
	const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int string_length = sizeof(alphanum)-1;
    srand(time(0));
    for(int i = 0; i < 12; i++)
	{
	    password += alphanum[rand() % string_length];
    }
}

void Bank_vShowAccountInfo(BankAccount* account)
{
	//Function to print account information
	std::cout<<"Full Name: "<<account->Full_Name<<std::endl;
	std::cout<<"Full Address: "<<account->Full_Address<<std::endl;
	std::cout<<"National ID: "<<account->NationalID<<std::endl;
	std::cout<<"Age: "<<account->Age<<std::endl;
	std::cout<<"Bank Account ID: "<<account->BankAccountID<<std::endl;
	std::cout<<"Guardian: "<<account->Guardian_Name<<std::endl;
	std::cout<<"Guardian National ID: "<<account->GuardianNationalID<<std::endl;
	std::cout<<"Account Status: "<<account->AccountStatus<<std::endl;
	std::cout<<"Balance: "<<account->Balance<<std::endl;
	std::cout<<"Password: "<<account->Password<< std::endl;
	std::cout<<std::endl;

}

BankAccount* Bank_pOpenExistingAccount(BankAccount* head)
{
	u64 accountID;
	u8 flag = 0; //flag to check validity of account ID
	
	EnterAccountID:
	std::cout<<"Enter Bank Account ID:";
	std::cin>>accountID;
	
	BankAccount* ptr = head;
	while(ptr != NULL)
	{
		//Check if account ID exist
		if(ptr->BankAccountID == accountID)
		{
			flag = 1;
			break;
		}
		ptr = ptr->Link;
	}
	if(flag == 0)
	{
		//In case of invalid account ID ask to enter again
		std::cout<<"Wrong Account ID.\n";
		goto EnterAccountID;
	}
	return ptr;
}

u8 Bank_u8ExistingAccountOptions(void)
{
	u32 flag=0;
	u32 choice;
	//Ask admin to choose one of available options and check choice's validity
	do
	{
		if (flag == 1)
		{
			std::cout<<"Invalid input\n";
		}
		std::cout<<"Choose one of the options below:\n";
		std::cout<<"Enter 1 to Make Transaction\n";
		std::cout<<"Enter 2 to Change Account Status\n";
		std::cout<<"Enter 3 to Get Cash\n";
		std::cout<<"Enter 4 to Deposit in Account\n";
		std::cout<<"Enter 5 to Show Account Details\n";
		std::cout<<"Enter 6 to Return to Main Menu\n";
		std::cin>>choice;
		flag = 1;
	}while((choice < 1) || (choice > 6));
	std::cout<<"\n";
	return choice;
}

void Bank_vExit(void)
{
	
	std::cout<<"\nSigned Out\n";
	std::cout<<"Thank you\n\n";
}

void Bank_vGetCash(BankAccount* ptr)
{	
	u64 cash = 0;
	u8 repeat = 'n';

		//Ask admin to enter cash amount
		std::cout<<"Enter cash amount:";
		std::cin>>cash;
		
		//Check if cash less than balace
		if((cash) < (ptr->Balance))
		{
			ptr->Balance -= cash;
			std::cout<<"Successful\n\n";
			std::cout<<"Current Balance =$%d \n\n",ptr->Balance;
		}
		else
		{
			std::cout<<"There's is no enough balance\n\n";
		}
}

void Bank_vChangeAccountPassword(BankAccount* ptr)
{
	std::string new_password1;
	std::string new_password2;
	u8 check = 1;
	do
	{
		//Ask client to enter new password
		std::cout<<"Enter new password\n";
		std::cin>>new_password1;
		//Ask client to enter new password again
		std::cout<<"Enter new password again\n";
		std::cin>>new_password2;
		//Check if new password match
		check = Bank_u8Check(new_password1 , new_password2);
		if(check != 0)
		{
			std::cout<<"New password don't match please try again\n";
		}
	}while(check != 0);
	//Assign new password to account password
	ptr->Password = new_password1;
	std::cout<<"Password changed successfully\n\n";
	
}

void Bank_vDeposit(BankAccount* ptr)
{
	u64 deposit = 0;
	std::cout<<"Enter deposit amount: \n";
	std::cin>>deposit;
	ptr->Balance += deposit; 
	std::cout<<"Deposit successful your new balance is; "<<ptr->Balance
	<<std::endl<<std::endl;
}

u32 Bank_u32CountAccounts(BankAccount* head)
{
	//Function to count number of existing bank accounts
	u32 count = 0;
	if(head == NULL)
	{
		std::cout<<"There are no accounts";
	}
	BankAccount* ptr = head;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->Link;
	}
	std::cout<<"Number of Accounts: %d\n",count;
	return count;
}

u8 Bank_u8MakeTransaction(BankAccount* head , BankAccount* sender)
{
	//Check if sender account is active
	if((Bank_u8Check(sender->AccountStatus , "Active")) != 0)
	{
		std::cout<<"Sender Account is not Active\n\n";
		return 0;
	}
	u64 receiverID;
	u64 money = 0;;
	u8 flag = 0; //flag to check validity of account ID
	
	EnterAccountID:
	//Enter receiver account ID
	std::cout<<"Enter Bank Account ID you want to transfer money to:";
	std::cin>>receiverID;
	
	BankAccount* receiver = head;

	//Loop to check validity of enter Account ID
	while(receiver != NULL)
	{
		//Check if account ID exist
		if(receiver->BankAccountID == receiverID)
		{
			flag = 1;
			break;
		}
		receiver = receiver->Link;
	}
	if(flag == 0)
	{
		//In case of invalid account ID ask to enter again
		std::cout<<"Wrong Account ID.\n";
		goto EnterAccountID;
	}
	
	//Check if receiver account is active
	if((Bank_u8Check(receiver->AccountStatus , "Active")) != 0)
	{
		std::cout<<"Receiver Account is not Active\n\n";
		return 0;
	}
	
	//Ask to enter amount of money to be transferred
	std::cout<<"Enter amount of money to send: ";
	std::cin>>money;
	
	//Check if sender have enough balance
	if(money < sender->Balance)
	{
		sender->Balance -= money;
		receiver->Balance +=  money;
		std::cout<<"Transaction Successful\n\n";
	}
	else
	{
		std::cout<<"Sorry you don't no enough balance\n\n";
	}
}

void Bank_vChangeAccountStatus(BankAccount* ptr)
{
	
	u32 state = 0;
	u8 flag = 0;
	
	//Ask admin to choose an Account State
	do
	{
		if(flag == 1)
		{
			printf("Invalid input please try again\n");
		}
		std::cout<<"Change Account status:\n";
		std::cout<<"Enter 1: Active State \n";
		std::cout<<"Enter 2: Restricted State \n";
		std::cout<<"Enter 3: Closed State \n";
		std::cin>>state;
		flag == 1;
	}while(state < 1 || state > 3);
	
	//Assign choosen state to Account State
	switch(state)
	{
		case 1: ptr->AccountStatus = "Active"; break;
		case 2: ptr->AccountStatus = "Restricted"; break;
		case 3: ptr->AccountStatus = "Closed"; break;
	}
	std::cout<<"Account Status changed successfully\n";
	std::cout<<"Redirecting to main menu\n\n";
}

BankAccount* Bank_vClientLogin(BankAccount* head)
{
	
	u64 account_id;
	std::string client_password;
	
	BankAccount* ptr = head;
	u8 flag1 = 0;
	u8 flag2 = 0;
	std::cout<<"Welcome to Client Window\n\n";

	//Ask to enter and Account ID and check it's validity
	do
	{
		
		if(flag2 == 1)
		{
			std::cout<<"Incorrect Bank Account ID\n";
		}
		std::cout<<"Enter Bank Account ID:\n";
		std::cin>>account_id;
		
		ptr = head;
		while(ptr != NULL)
		{
			if(ptr->BankAccountID == account_id)
			{
				flag1 = 1;
				break;
			}
			else
			{
				ptr = ptr->Link;	
			}
		}
		flag2 = 1;
	}while(flag1 != 1);
	
	Bank_vShowAccountInfo(ptr);
	
	u8 CheckPassword = 1; //Flag to check if password is correct
	u8 flag3 = 0;
	do
	{
		if(flag3 == 1)
		{
			std::cout<<"Wrong Password\n";
		}
		std::cout<<"Enter Account Password: \n";
		std::cin>>client_password;
		//Compare entered password with account password
		CheckPassword = Bank_u8Check(client_password , ptr->Password); 
		flag3 = 1;
	}while(CheckPassword != 0);
	
	std::cout<<"Login Successful\n\n";
	
	return ptr;
}

u32 Bank_u32ClientMainMenu(void)
{
	u32 flag=0;
	u32 choice;
	//Ask client to choose from available options and check choice's validity
	do
	{
		if (flag == 1)
		{
			printf("Invalid input\n");
		}
		std::cout<<"Choose one of the options below:\n";
		std::cout<<"Enter 1 to Make Transaction\n";
		std::cout<<"Enter 2 to Change Account Password\n";
		std::cout<<"Enter 3 to Get Cash\n";
		std::cout<<"Enter 4 to Deposit in Account\n";
		std::cout<<"Enter 5 to Show Account Details\n";
		std::cout<<"Enter 6 to Return to Main Menu\n";
		std::cout<<"Enter 7 to Exit System\n";
		std::cin>>choice;
		flag = 1;
	}while((choice < 1) || (choice > 7));
	std::cout<<"\n";
	return choice;
}
