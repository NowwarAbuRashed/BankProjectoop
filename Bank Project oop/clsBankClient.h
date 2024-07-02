#pragma once
#include<iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include"Global.h"
#include<vector>
#include<fstream>

using namespace std;

class clsBankClient:public clsPerson
{

private:

	static enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode=2};
	
	enMode  _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete=false;

	struct stTransferslog;

	static clsBankClient _ConvertLinetoClientOpject(string Line,string Seperator="#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static clsBankClient _GetEmptyClientOpject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "","", 0);
	}

	static vector<clsBankClient>_LoadClientsDataFromFile()
	{
		vector<clsBankClient>vClients;

		fstream MyFile;
		MyFile.open("Clients.txt",ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Clint = _ConvertLinetoClientOpject(Line);
				vClients.push_back(Clint);
			}
			MyFile.close();
		}
		return vClients;

	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client._AccountNumber + Seperator;
		stClientRecord +=  Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);
		return stClientRecord;
	}

	static void _SaveCleintsDataToFile(vector<clsBankClient>_vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open()) 
		{
			string DataLine;
			for (clsBankClient Clint : _vClients)
			{
				if (Clint._MarkedForDelete==false) 
				{
					DataLine = _ConverClientObjectToLine(Clint);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient &Clint : _vClients)
		{
			if (Clint._AccountNumber == this->_AccountNumber)
			{
				Clint = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	string _ConverTransferslogToLine(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{
		string stClientRecord = clsDate::GetSystemDateTimeString() + Seperator;
		stClientRecord += GetAccountNumber() + Seperator;
		stClientRecord += DestinationClient.GetAccountNumber() + Seperator;
		stClientRecord += to_string(Amount) + Seperator;
		stClientRecord += to_string(AccountBalance) + Seperator;
		stClientRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		stClientRecord += UserName;
		return stClientRecord;
	}

	void _RegisterTransferslog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _ConverTransferslogToLine(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static stTransferslog _ConvertLinetoTransferslogOpject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);
		stTransferslog Transferslog;
		Transferslog.DateTime = vClientData[0];
		Transferslog.AccountNumberFrom = vClientData[1];
		Transferslog.AccountNumberTo = vClientData[2];
		Transferslog.Amount = stod( vClientData[3]);
		Transferslog.AccountBalansse1 =stod( vClientData[4]);
		Transferslog.AccountBalansse2 = stod(vClientData[5]);
		Transferslog.NameUsre = vClientData[6];
		return Transferslog;
	}

	static vector<stTransferslog>_LoadTransferslogFromFile()
	{
		vector<stTransferslog>vClients;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stTransferslog Clint = _ConvertLinetoTransferslogOpject(Line);
				vClients.push_back(Clint);
			}
			MyFile.close();
		}
		return vClients;

	}


public:

	struct stTransferslog
	{
		string DateTime;
		string AccountNumberFrom;
		string AccountNumberTo;
		double Amount;
		double AccountBalansse1;
		double AccountBalansse2;
		string NameUsre;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;


	 bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	 bool MarkedForDelete()
	 {
		 return _MarkedForDelete;
	 }
	


	static clsBankClient Find(string AccountNumber)
	{

		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientOpject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientOpject();


	}
	static clsBankClient Find(string AccountNumber,string PinCode)
	{

		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientOpject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientOpject();


	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client =clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svFaildAccountNumberExists=2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			if (IsEmpty()) 
			{
				return enSaveResults::svFaildEmptyObject;
			}

		case clsBankClient::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;
		case clsBankClient::AddNewMode:
			
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		default:
			break;
		}

	}

	bool Delete()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& Clint : _vClients)
		{
			if (Clint.GetAccountNumber() == _AccountNumber)
			{
				Clint._MarkedForDelete=true;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
		*this = _GetEmptyClientOpject();
		return true;
	}

	static vector<clsBankClient>GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients;
		vClients = _LoadClientsDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient Clint : vClients)
		{
			TotalBalances += Clint.AccountBalance;
		}
		return TotalBalances;
	}


	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if(Amount>_AccountBalance)
		{ 
			return false;
		}
		else 
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}


	bool Transfer(double Amount, clsBankClient& DestinationClient,string UserName)
	{

		if (Amount > AccountBalance)
		{
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferslog(Amount, DestinationClient, UserName);
		return true;

	}


	static vector<stTransferslog>GetTransferslogList()
	{
		return _LoadTransferslogFromFile();
	}







};

