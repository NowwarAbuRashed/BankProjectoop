#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"Global.h"
using namespace std;



class clsTransferScreen:protected clsScreen
{

	static void _PrintClintCard(clsBankClient Clint)
	{
		cout << "\n Clint Card:\n";
		cout << "\n____________________\n\n";
		cout << "Full Name   : " << Clint.FullName() << endl;
		cout << "Acc. Number : "<<Clint.GetAccountNumber()<<endl;
		cout << "Balance     : "<<Clint.AccountBalance<<endl;
		cout << "\n____________________\n\n";
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}


public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		cout << "Please Enter Account Number to Transfer From: ";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		
		_PrintClintCard(SourceClient);

		cout << "Please Enter Account Number to Transfer To: ";
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		
		_PrintClintCard(DestinationClient);

		cout << "Enter Transfer Amount? ";
		double Amount = clsInputValidate::ReadDblNumberBetween(0, SourceClient.AccountBalance, "Amount Exceeds the available Balance, Enter another Amount ? ");
		char Shoice = 'n';
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

			_PrintClintCard(SourceClient);
			_PrintClintCard(DestinationClient);
			
		

	}


};

