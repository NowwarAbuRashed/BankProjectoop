#pragma once
#include <iostream>
#include"clsDate.h"
using namespace std;


class clsInputValidate
{





public:
	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (From > To)
			swap(From, To);

		return  (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (From > To)
			swap(From, To);
		return  (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (From > To)
			swap(From, To);
		return  (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (clsDate::CheckIfDate1IsAfterThanDate2(From, To))
		{
			swap(From, To);
		}
		return (!(clsDate::CheckIfDate1IsAfterThanDate2(Date, To) || clsDate::CheckIfDate1IsLessThanDate2(Date, From)));
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidateThisDate(Date);
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid number, Enter again:\n")
	{
		int Number = 0;
		while (!(cin >> Number))
		{
			cout << ErrorMessage;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid number, Enter again:\n")
	{
		float Number = 0;
		while (!(cin >> Number))
		{
			cout << ErrorMessage;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid number, Enter again:\n")
	{
		double Number = 0;
		while (!(cin >> Number))
		{
			cout << ErrorMessage;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid number, Enter again:\n")
	{
		short Number = 0;
		while (!(cin >> Number))
		{
			cout << ErrorMessage;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return Number;
	}

	static string ReadString(string Message="")
	{
		string S;
		cout << Message;
		getline(cin >> ws, S);
		return S;

	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();
		while (!(IsNumberBetween(Number, From, To)))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadIntNumber();
		while (!(IsNumberBetween(Number, From, To)))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}




};

