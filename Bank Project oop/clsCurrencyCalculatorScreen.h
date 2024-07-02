#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;


class clsCurrencyCalculatorScreen:protected clsScreen
{

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static clsCurrency _CurrencyByCode()
    {

        string Code = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency is not found, choose another one: ";
            Code = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(Code);

        return Currency;
    }

    static void PrintCalculatoionResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
    {
        
            cout << "\nConvert From :\n";
            _PrintCurrency(CurrencyFrom);
            cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << CurrencyFrom.ConvertToUSD(Amount) << " USD\n";

            if (CurrencyTo.CurrencyCode() == "USD")
            {
                return;
            }
       
            cout << "\nConverting from USD to: \n";
            cout << "\nTo :\n";
            _PrintCurrency(CurrencyTo);
            cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo) << " " << CurrencyTo.CurrencyCode() << endl;




    }

public:


	static void ShowCurrencyCalculatorScreen()
	{  
        
        char Shoice='n';
        do {
            system("cls");

            _DrawScreenHeader("\t  Calculator Currency Screen");

            cout << "\nPlease Enter Currency Code1:\n";
            clsCurrency CurrencyFrom = _CurrencyByCode();

            cout << "\nPlease Enter Currency Code2:\n";
            clsCurrency CurrencyTo = _CurrencyByCode();

            cout << "\nEnter Amount to Exchang: ";
            float Amount = clsInputValidate::ReadFloatNumber();

            PrintCalculatoionResult(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Shoice;
        } while (Shoice=='y'||Shoice=='Y');

	}

};

