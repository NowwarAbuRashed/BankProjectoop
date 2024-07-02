#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsCurrency.h"
using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{

	enum enFindTo{eCode=1,eCountry=2};

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
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-)\n";

        }
    }

    static void PrintCurrencyByCode()
    {

        cout << "\nPlease Enter CurrencyCode: ";
        string Code = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(Code);

        _ShowResults(Currency);
    }

    static void PrintCurrencyByCountry()
    {
        cout << "\nPlease Enter Country Name: ";
        string Country = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCountry(Country);

        _ShowResults(Currency);
    }

public:

	static void ShowFindCurrencyScreen()
	{
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "Find By: [1] Code or [2] Currency ? ";
        enFindTo Chois=((enFindTo)clsInputValidate::ReadShortNumber());

        switch (Chois)
        {
        case clsFindCurrencyScreen::eCode:
            PrintCurrencyByCode();

            break;

        case clsFindCurrencyScreen::eCountry:
            PrintCurrencyByCountry();

            break;
        default:
            break;
        }



	}

};

