#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;

class clsUpdateCurrencyRateScreen :protected clsScreen
{

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        cout << "\n\nUpdate Currency Rate: \n";
        cout << "\n------------------------\n";
        cout << "\nEnter New Rate: ";
        if (!Currency.IsEmpty())
        { 
            Currency.UpdateRate(clsInputValidate::ReadFloatNumber());
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Update  :-(\n";
            _PrintCurrency(Currency);
        }
    }

    static clsCurrency CurrencyByCode()
    {

        cout << "\nPlease Enter Currency Code: ";
        string Code = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency is not found, choose another one: ";
            Code = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(Code);

        return Currency;
    }

public:


	static void ShowUpdateRateScreen()
	{

		_DrawScreenHeader("\t  Update Currency Screen");
     
        clsCurrency  Currency = CurrencyByCode();
        _PrintCurrency(Currency);
        cout << "Are you sure you want to update the rate of this Currency y/n? ";
        char Shoice = 'n';
        cin >> Shoice;
        if (Shoice=='y'||Shoice=='Y')
        {
            _ShowResults(Currency);
        }



	}


};

