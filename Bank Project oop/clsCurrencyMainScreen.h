#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;


class clsCurrencyMainScreen :protected clsScreen
{
	enum enCurrencyExhangeMenue
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5

	};
	static short _ReadCurrencyExhangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}


	static void _ShowListCurrenciesScreen()
	{

		clsCurrenciesListScreen::ShowListCurrenciesScreen();

	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{

		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}

	static  void _GoCurrencyExhangeMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrencyExchange();
	}

	static void _PerfromCurrencyExhangeMenueOption(enCurrencyExhangeMenue CurrencyExhangeMenue)
	{

		switch (CurrencyExhangeMenue)
		{
		case clsCurrencyMainScreen::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoCurrencyExhangeMenue();
			break;

		case clsCurrencyMainScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoCurrencyExhangeMenue();
			break;

		case clsCurrencyMainScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoCurrencyExhangeMenue();
			break;

		case clsCurrencyMainScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoCurrencyExhangeMenue();
			break;

		case clsCurrencyMainScreen::eMainMenue:
			system("cls");

			break;
		}



	}

public:

	static void ShowCurrencyExchange()
	{
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExhange))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("   Currancy Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrancy Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies .\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrencyExhangeMenueOption((enCurrencyExhangeMenue)_ReadCurrencyExhangeMenueOption());
	}







};

